# -*- coding:utf-8 -*-

from common import *
import profile as mod_profile
from util.jsonobj import JsonObject

import app

def logger():
    return app.App.instance.logger

def request_register():
    reg = JsonObject()
    reg.name = 'leonce'
    reg.pwd = 'leonce'
    dispatcher().send_msg(Msg('register', reg))

def register_response(msg):
    logger().info('register succ')
    request_login()

def register_error_account_exist(err):
    logger().info('register account exist')
    request_login()

def request_login():
    lg = JsonObject()
    lg.name = 'leonce'
    lg.pwd = 'leonce'
    dispatcher().send_msg(Msg('login', lg))

def login_response(msg):
    dispatcher().set_token(msg.msg.token)
    logger().info('login succ')
    mod_profile.request_getinfo()

def login_error_account_not_exist(err):
    log_request_error(err)
