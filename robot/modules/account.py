# -*- coding:utf-8 -*-

from common import *
import proto.account_pb2 as pro_account
import profile as mod_profile

def request_register():
    reg = pro_account.Register()
    reg.name = 'leon'
    reg.pwd = 'leon'
    data = reg.SerializeToString()
    dispatcher().send_msg(Msg(REGISTER, data))

def register_response(msg):
    rsp = pro_account.RegisterResponse()
    rsp.ParseFromString(msg.data)
    if not rsp.status:
        request_login()
    elif rsp.status == error_code.ACCOUNT_EXIST:
        request_login()
    else:
        log_error(msg.opcode, rsp.status)

def request_login():
    lg = pro_account.Login()
    lg.name = 'leon'
    lg.pwd = 'leon'
    data = lg.SerializeToString()
    dispatcher().send_msg(Msg(LOGIN, data))

def login_response(msg):
    rsp = pro_account.LoginResponse()
    rsp.ParseFromString(msg.data)
    if not rsp.status:
        dispatcher().set_token(rsp.token)
        mod_profile.request_getinfo()
    else:
        log_error(msg.opcode, rsp.status)
