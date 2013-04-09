# -*- coding:utf-8 -*-

from common import *
import profile as mod_profile

def request_register():
    reg = {}
    reg['name'] = 'leoncc'
    reg['pwd'] = 'leoncc'
    dispatcher().send_msg(Msg('register', reg))

def register_response(msg):
    print 'register succ'
    request_login()

def register_error_account_exist(err):
    print 'register account exist'
    request_login()

def request_login():
    lg = {}
    lg['name'] = 'leoncc'
    lg['pwd'] = 'leoncc'
    dispatcher().send_msg(Msg('login', lg))

def login_response(msg):
    dispatcher().set_token(msg.msg['token'])
    print 'login succ'
    mod_profile.request_getinfo()

def login_error_account_not_exist(err):
    log_request_error(err)
