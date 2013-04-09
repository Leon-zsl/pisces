# -*- coding:utf-8 -*-

import base64
import time
import inspect
import json

from config import *
from excepts import *

from protocol import error_code
from protocol import request_dic

from models import account

import app

def log_root():
    return app.App.instance.logger.root

def db():
    return app.App.instance.db

def db_rcd():
    return app.App.instance.db_record

class Processor(object):
    def __init__(self):
        self.handler_dic = self.parse_handler_map()

    def __del__(self):
        self.close()

    def close(self):
        pass
        
    def parse_handler_map(self):
        return request_dic.dic

    def process(self, op_msg, token, request_handler):
        if not op_msg:
            return ""
        
        msg_dic = json.loads(op_msg)
        if not msg_dic:
            log_root().critical("invalid post data: " + op_msg)
            return ""
        
        op = msg_dic.keys()[0]
        msg = json.loads(base64.decodestring(msg_dic.values()[0]))
        func = self.handler_dic.get(op)
        if not func:
            log_root().critical("invalid request: " + op)
            err = {}
            err['errno'] = error_code.INVALID_REQUEST
            err['errop'] = op
            err['errmsg'] = ''
            return json.dumps({'request_error' :
                               base64.encodestring(json.dumps(err))})

        try:
            start = time.time()

            omit_token = op in request_dic.token_omit
            require_request = op in request_dic.request_info_require
            
            if not omit_token:
                val = self.check_token(token)
                if val:
                    err = {}
                    err['errno'] = val
                    err['errop'] = op
                    err['errmsg'] = ''
                    return json.dumps({'request_error':
                                      base64.encodestring(json.dumps(err))})

            if not omit_token and require_request:
                opc, msgc = func(op, msg, token[0], request_handler)
            elif not omit_token:
                opc, msgc = func(op, msg, token[0])
            elif require_request:
                opc, msgc = func(op, msg, request_handler)
            else:
                opc, msgc = func(op, msg)
                
            dt = time.time() - start
            log_root().info("handler time: %s:%.3fms" % \
                            (op, dt * 1000))
            return json.dumps({opc :
                               base64.encodestring(json.dumps(msgc))})
        except illeagal_msg.IlleagalMsgExcept, ex:
            db().rollback()
            db_rcd().rollback()
            log_root.error('illeagal msg format: ' + ex.op)
            err = {}
            err['errno'] = error_code.ILLEAGAL_MSG
            err['errop'] = ex.op
            err['errmsg'] = ex.msg
            return json.dumps({'request_error':
                               base64.encodestring(json.dumps(err))})
                    
    def check_token(self, token):
        if not token:
            log_root.error('miss token: ' + op)
            return error_code.MISS_TOKEN
              
        if len(token) != 3:
            log_root.error('invalid token: ' + op)
            return error_code.INVALID_TOKEN

        usrid = token[0]
        if not usrid:
            log_root.error('illeagal usr id: ' + op)
            return error_code.ILLEAGAL_USRID

        usr = db().query(account.Account).get(usrid)
        if not usr:
            log_root.error('illeagal usr id: ' + op)
            return error_code.ILLEAGAL_USRID
            
        ver = token[1]
        if not ver or ver != APP_VERSION:
            log_root.error('invalid app version: ' + op)
            return error_code.INVALID_APP_VERSION

        lgtime = token[2]
        if not lgtime or lgtime != usr.login_time:
            log_root.error('token time out: ' + op)
            return error_code.TOKEN_TIMEOUT

        return error_code.NO_ERROR
