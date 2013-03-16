#!/usr/bin/env python
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

from handlers import *
import protocol.request_dic as request_dic

def default_user_handler(userid, op, msg):
    app.App.logger.root.critical("unknown user msg: " + op + ":" + msg)

def default_handler(op, msg):
    app.App.logger.root.critical("unknown msg: " + op + ":" + msg)
    
def log_root():
    return app.App.instance.logger.root

class Router(object):
    def __init__(self):
        self.handler_dic = self.parse_handler_map()

    def __del__(self):
        self.close()
        
    def close(self):
        pass

    def dispatch(self, request_handler):
        app.App.instance.db.open_session()

        userid = self.parse_token(request_handler.request)
        msg_list = self.parse_msg(request_handler.request)
        val_list = self.handle_msg(userid, msg_list)
        response = self.parse_response(val_list)

        app.App.instance.db.close_session()
        return response
        
    def parse_token(self, request):
        if not request.arguments.has_key("token"):
            return ""

        token = request.arguments.get("token")[0]
        userid = int(base64.decodestring(token))
        return userid
    
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

    def handle_msg(self, userid, msg_list):
        val_list = []
        for msg in msg_list:
            op = msg.keys()[0]
            cont = msg.values()[0]
            opc = 0
            msgc = None

            start = time.time()
            func = self.handler_dic.get(op, default_handler)
            if not func:
                log_root().critical("unknown func: " + str(op))
                continue
            
            if userid:
                if len(inspect.getargspec(func).args) != 3:
                    log_root().critical('illeagal arg format: ' + opc)
                    continue
                log_root().info("handler func: %d:%d", op, userid)
                opc, msgc = func(op, cont, userid)
            else:
                if len(inspect.getargspec(func).args) != 2:
                    log_root().critical('illeagal arg format: ' + opc)
                    continue
                log_root().info("handler func: %s",op)
                opc, msgc = func(op, cont)

            dt = time.time() - start
            log_root().info("handler time: %s, %.3fms", op, dt * 1000)
            
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
