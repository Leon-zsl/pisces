# -*- coding:utf-8 -*-

#import json
#import imp
#import sys
#import os
#import os.path
#import time
import base64

import app
from processor import Processor
from exception import PiscesException

import util.token as token

def log_root():
    return app.App.instance.logger.root

def db():
    return app.App.instance.db

def db_rcd():
    return app.App.instance.db_record

class Router(object):
    def __init__(self):
        self.processor = Processor()

    def __del__(self):
        self.close()
        
    def close(self):
        self.processor.close()

    def dispatch(self, request_handler):
        # start = time.time()
        db().open_session()
        db_rcd().open_session()
        try:
            token = self.parse_token(request_handler.request)
            msg_list = self.parse_msg(request_handler.request)
            val_list = self.handle_msg(token, msg_list, 
                                       request_handler)
            response = self.parse_response(val_list)
            return response
        except PiscesException, ex:
            db_rcd().rollback()
            db().rollback()
            log_root().critical('uncaught pisces except: ' + ex.msg)
        finally:
            db_rcd().close_session()
            db().close_session()
            # dt = time.time() - start
            # log_root().info('dispatch time: %.3fms' % (dt * 1000))
            
    def parse_token(self, request):
        if not request.arguments.has_key("token"):
            return 0

        tk = request.arguments.get("token")[0]
        tk = token.parse_token(tk)
        return tk
    
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

    def handle_msg(self, token, msg_list, request_handler):
        val_list = []
        for msg in msg_list:
            op = msg.keys()[0]
            cont = msg.values()[0]
            opc, msgc = self.processor.process(op, cont, token, 
                                               request_handler)
            val_list.append({ opc : msgc })
        return val_list

    def parse_response(self, val_list):
        strc = ""
        for val in val_list:
            strc += str(val.keys()[0]) + ":" + \
              base64.encodestring(val.values()[0]) + "|"
        return strc
