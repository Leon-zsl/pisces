# -*- coding:utf-8 -*-

import time
import inspect
import google.protobuf as protobuf

from config import *
from excepts import *

from protocol import error_code
from protocol import request_dic

from models import account
import proto.common_pb2 as proto_common

import app

def log_root():
    return app.App.instance.logger.root

def db():
    return app.App.instance.db

class Processor(object):
    def __init__(self):
        self.handler_dic = self.parse_handler_map()

    def __del__(self):
        self.close()

    def close(self):
        pass
        
    def parse_handler_map(self):
        return request_dic.dic

    def process(self, op, msg, token):
        func = self.handler_dic.get(op)
        if not func:
            log_root().critical("invalid request: " + str(op))
            err = proto_common.RequestError()
            err.errno = error_code.INVALID_REQUEST
            err.errop = op
            err.errmsg = ''
            return opcode_response.REQUEST_ERROR, \
              err.SerializeToString()

        try:
            opc = 0
            msgc = ''
            start = time.time()

            if len(inspect.getargspec(func).args) == 2:
                opc, msgc = self.proc_without_token(func, op, msg)
            elif len(inspect.getargspec(func).args) == 3:
                opc, msgc = self.proc_with_token(func, op, msg, token)
            else:
                raise illeagal_arg.IlleagalArgExcept(op, '')

            dt = time.time() - start
            log_root().info("handler time: %d: %.3fms", op, dt * 1000)
            return opc, msgc
        except illeagal_msg.IlleagalMsgExcept, ex:
            db.rollback()
            log_root.error('illeagal msg format: ' + ex.op)
            err = proto_common.RequestError()
            err.errno = error_code.ILLEAGAL_MSG
            err.errop = ex.op
            err.errmsg = ex.msg
            return opcode_response.REQUEST_ERROR, \
              err.SerializeToString()
                    
    def proc_with_token(self, func, op, msg, token):
        if not token:
            log_root.error('miss token: ' + op)
            err = proto_common.RequestError()
            err.errno = error_code.MISS_TOKEN
            err.errop = op
            err.errmsg = ''
            return opcode_response.REQUEST_ERROR, \
              err.SerializeToString()
              
        if len(token) != 3:
            log_root.error('invalid token: ' + op)
            err = proto_common.RequestError()
            err.errno = error_code.INVALID_TOKEN
            err.errop = op
            err.errmsg = ''
            return opcode_response.REQUEST_ERROR, \
              err.SerializeToString()            

        usrid = token[0]
        if not usrid:
            log_root.error('illeagal usr id: ' + op)
            err = proto_common.RequestError()
            err.errno = error_code.ILLEAGAL_USRID
            err.errop = op
            err.errmsg = ''
            return opcode_response.REQUEST_ERROR, \
              err.SerializeToString()

        usr = db().query(account.Account).get(usrid)
        if not usr:
            log_root.error('illeagal usr id: ' + op)
            err = proto_common.RequestError()
            err.errno = error_code.ILLEAGAL_USRID
            err.errop = op
            err.errmsg = ''
            return opcode_response.REQUEST_ERROR, \
              err.SerializeToString()
            
        ver = token[1]
        if not ver or ver != APP_VERSION:
            log_root.error('invalid app version: ' + op)
            err = proto_common.RequestError()
            err.errno = error_code.INVALID_APP_VERSION
            err.errop = op
            err.errmsg = ''
            return opcode_response.REQUEST_ERROR, \
              err.SerializeToString()

        lgtime = token[2]
        if not lgtime or lgtime != usr.login_time:
            log_root.error('token time out: ' + op)
            err = proto_common.RequestError()
            err.errno = error_code.TOKEN_TIMEOUT
            err.errop = op
            err.errmsg = ''
            return opcode_response.REQUEST_ERROR, \
              err.SerializeToString()
            
        return func(op, msg, usrid)

    def proc_without_token(self, func, op, msg):
        return func(op, msg)
            
