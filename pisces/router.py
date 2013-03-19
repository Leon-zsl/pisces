# -*- coding:utf-8 -*-

import json
import base64
import inspect
import imp
import sys
import os
import os.path
import time
import google.protobuf as protobuf

import app
import log

import util.token as token

from controllers import *
import protocol.request_dic as request_dic

import proto.common_pb2 as proto_common

from excepts.illeagal_arg import IlleagalArgExcept
from excepts.illeagal_msg import IlleagalMsgExcept
from excepts.miss_token import MissTokenExcept

def default_user_handler(usrid, op, msg):
    app.App.logger.root.critical("unknown user msg: " + op + ":" + msg)

def default_handler(op, msg):
    app.App.logger.root.critical("unknown msg: " + op + ":" + msg)
    
def log_root():
    return app.App.instance.logger.root

def db():
    return app.App.instance.db

class Router(object):
    def __init__(self):
        self.handler_dic = self.parse_handler_map()

    def __del__(self):
        self.close()
        
    def close(self):
        pass

    def dispatch(self, request_handler):
        db().open_session()

        usrid = self.parse_token(request_handler.request)
        msg_list = self.parse_msg(request_handler.request)
        val_list = self.handle_msg(usrid, msg_list)
        response = self.parse_response(val_list)

        db().close_session()
        return response
        
    def parse_token(self, request):
        if not request.arguments.has_key("token"):
            return 0

        tk = request.arguments.get("token")[0]
        usrid = token.token_to_uid(tk)
        return usrid
    
    def parse_msg(self, request):
        if not request.arguments.has_key("msg"):
            log_root().critical("no msg in request")
            return []
        
        req_msg = request.arguments.get("msg")[0]
        msg_list = req_msg.split('|')
        if not msg_list:
            log_root().critical("no msg request")
            return []
        
        val_list = []
        for msg in msg_list:
            kvp = msg.split(":")
            dic = { int(kvp[0]) : base64.decodestring(kvp[1]) }
            val_list.append(dic)
        return val_list

    def handle_msg(self, usrid, msg_list):
        val_list = []
        for msg in msg_list:
            op = msg.keys()[0]
            cont = msg.values()[0]
            opc, msgc = self.exc_handler(op, cont, usrid)
            val_list.append({ opc : msgc })
        return val_list

    def parse_response(self, val_list):
        strc = ""
        for val in val_list:
            strc += str(val.keys()[0]) + ":" + \
              base64.encodestring(val.values()[0]) + "|"
        return strc

    def parse_handler_map(self):
        # dic = {}
        # for file in os.listdir('handlers'):
        #     if not file.endswith('.py'):
        #         continue
        #     name = os.path.splitext(file)[0]
        #     mod = imp.load_module(name, *imp.find_module(name,
        #                                                  ['handlers']))
        #     if mod:
        #         for attr in mod.__dict__.keys():
        #             func = getattr(mod, attr)
        #             if inspect.isfunction(func):
        #                 dic[attr] = func
        # print dic
        return request_dic.dic

    def exc_handler(self, op, msg, usrid):
        opc = 0
        msgc = ''
        func = self.handler_dic.get(op, default_handler)
        if not func:
            log_root().critical("unknown func: " + str(op))
            return

        log_root().info("handler func: %d:%d", op, 
                        usrid if usrid else 0)
        start = time.time()
        try:
            if len(inspect.getargspec(func).args) == 2:
                opc, msgc = func(op, msg)
            elif len(inspect.getargspec(func).args) == 3:
                if not usrid:
                    raise MissTokenExcept(op, '')
                opc, msgc = func(op, msg, usrid)
            else:
                raise IlleagalArgExcept(op, '')
        except IlleagalArgExcept, ex:
            db().rollback()
            log_root.error('illeage handler arg format: ' + ex.op)
            return opc, msgc
        except MissTokenExcept, ex:
            db().rollback()
            log_root.error('miss token msg format: ' + ex.op)
            err = proto_common.RequestError()
            err.errno = error_code.MISS_TOKEN
            err.errop = ex.op
            err.errmsg = ex.msg
            return opcode_response.REQUEST_ERROR,err.SerializeToString()
        except IlleagalMsgExcept, ex:
            db.rollback()
            log_root.error('illeagal msg format: ' + ex.op)
            err = proto_common.RequestError()
            err.errno = error_code.ILLEAGAL_MSG
            err.errop = ex.op
            err.errmsg = ex.msg
            return opcode_response.REQUEST_ERROR,err.SerializeToString()
            
        dt = time.time() - start
        log_root().info("handler time: %s, %.3fms", op, dt * 1000)

        return opc, msgc
