# -*- coding:utf-8 -*-

#import imp
#import sys
#import os
#import os.path
#import time
import base64
import json
import util.jsonobj as jsonobj

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
            log_root().exception('uncaught pisces except: ' + ex.msg)
        except Exception, ex:
            db_rcd().rollback()
            db().rollback()
            log_root().exception('uncaught sys except: ' + str(ex))
        finally:
            db_rcd().close_session()
            db().close_session()
            # dt = time.time() - start
            # log_root().info('dispatch time: %.3fms' % (dt * 1000))
            
    def parse_token(self, request):
        if not request.arguments.has_key('token'):
            return 0

        tk = request.arguments.get('token')[0]
        tk = token.parse_token(tk)
        return tk
    
    def parse_msg(self, request):
        if not request.arguments.has_key('msg'):
            log_root().critical('no msg in request')
            return []
        
        req_msg = request.arguments.get('msg')[0]
        msg_list = json.loads(req_msg)
        if not msg_list:
            log_root().critical('no msg request')
            return []
        return msg_list

    def handle_msg(self, token, msg_list, request_handler):
        val_list = []
        for msg in msg_list:
            if not msg:
                log_root().error('msg req is null')
                continue

            msg_v = json.loads(base64.decodestring(msg.values()[0]))
            msg_v = jsonobj.dic2jsonobj(msg_v)
            opc, msgc = self.processor.process(msg.keys()[0],
                                               msg_v,
                                               token, 
                                               request_handler)
            msgc = jsonobj.jsonobj2dic(msgc)
            msgc = base64.encodestring(json.dumps(msgc))
            val_list.append({opc : msgc})
        return val_list

    def parse_response(self, val_list):
        return json.dumps(val_list)
