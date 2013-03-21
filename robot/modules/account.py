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
    print 'register succ'
    request_login()

def request_login():
    lg = pro_account.Login()
    lg.name = 'leon'
    lg.pwd = 'leon'
    data = lg.SerializeToString()
    dispatcher().send_msg(Msg(LOGIN, data))

def login_response(msg):
    rsp = pro_account.LoginResponse()
    rsp.ParseFromString(msg.data)
    dispatcher().set_token(rsp.token)
    print 'login succ'
    mod_profile.request_getinfo()
