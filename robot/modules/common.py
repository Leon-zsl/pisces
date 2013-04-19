# -*- coding:utf-8 -*-

import app

from msg import Msg

import protocol.protocol_dic
import protocol.error_code as error_code

def logger():
    return app.App.instance.logger

def dispatcher():
    return app.App.instance.dispatcher

def get_err_desc(err):
    lst = dir(protocol.error_code)
    for attr in lst:
        val = getattr(protocol.error_code, attr)
        if type(val) == int and val == err:
            return attr
    return 'unknown error code'

def log_error(op, err):
    logger().error('op err: [op]%s, [err]%d:%s' \
                   % (op, err, get_err_desc(err)))

def log_request_error(reqerr):
    logger().error('req err: [op]%s, [err]%d:%s, [msg]%s' \
                  % (reqerr.errop,
                     reqerr.errno, 
                     get_err_desc(reqerr.errno),
                     reqerr.errmsg))

def default_error_response(reqerr):
    log_request_error(reqerr)
    
def request_error_response(msg):
    err = msg.msg
    handler = protocol.protocol_dic.request_error_dic.get(err.errno)
    if not handler:
        handler=protocol.protocol_dic.request_error_dic.get('default')
    elif type(handler) == dict:
        handler = handler.get(err.errop)
        if not handler:
            handler = handler.get('default')

    if not handler:
        handler = default_error_response

    handler(err)
