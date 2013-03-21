# -*- coding:utf-8 -*-

import app

from msg import Msg

import protocol.opcode_request
import protocol.opcode_response
from protocol.opcode_request import *
from protocol.opcode_response import *

import protocol.protocol_dic
import protocol.error_code as error_code

import proto.common_pb2 as pro_common

def logger():
    return app.App.instance.logger

def dispatcher():
    return app.App.instance.dispatcher

def get_req_op_desc(op):
    lst = dir(protocol.opcode_request)
    for attr in lst:
        val = getattr(protocol.opcode_request, attr)
        if type(val) == int and val == op:
            return attr
    return 'unknown request opcode'

def get_rsp_op_desc(op):
    lst = dir(protocol.opcode_response)
    for attr in lst:
        val = getattr(protocol.opcode_response, attr)
        if type(val) == int and val == op:
            return attr
    return 'unknown response opcode'

def get_err_desc(err):
    lst = dir(protocol.error_code)
    for attr in lst:
        val = getattr(protocol.error_code, attr)
        if type(val) == int and val == err:
            return attr
    return 'unknown error code'

def log_error(op, err):
    logger().error('op err: [op]%d:%s, [err]%d:%s' \
                   % (op, 
                      get_req_op_desc(op), 
                      err, 
                      get_err_desc(err)))

def log_request_error(reqerr):
    logger().error('req err: [op]%d:%s, [err]%d:%s, [msg]%s' \
                  % (reqerr.errop,
                     get_req_op_desc(reqerr.errop),
                     reqerr.errno, 
                     get_err_desc(reqerr.errno),
                     reqerr.errmsg))

def default_error_response(reqerr):
    log_request_error(reqerr)
    
def request_error_response(msg):
    err = pro_common.RequestError()
    err.ParseFromString(msg.data)
    
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
