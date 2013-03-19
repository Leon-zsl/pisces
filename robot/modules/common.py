# -*- coding:utf-8 -*-

import app

from msg import Msg
from protocol.opcode_request import *
#from protocol.opcode_response import *
import protocol.error_code as error_code
import protocol.error_msg as error_msg

import proto.common_pb2 as pro_common

def logger():
    return app.App.instance.logger

def dispatcher():
    return app.App.instance.dispatcher

def log_error(op, err):
    logger().error('req err: [op]%d, [err]%d, [msg]%s' \
                   % (op, err, error_msg.dic[err]))

def request_error_response(msg):
    err = pro_common.RequestError()
    err.ParseFromString(msg.data)
    logger.error('req err: [op]%d, [err]%d, [msg]%s' \
                 % (err.errop, err.error, err.errmsg))
