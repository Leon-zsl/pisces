# -*- coding:utf-8 -*-

from common import *
import character as mod_character

import app

def logger():
    return app.App.instance.logger

def request_getinfo():
    gi = {}
    dispatcher().send_msg(Msg('get_profile_info', gi))

def getinfo_response(msg):
    logger().info('profile getinfo succ: ' + msg.msg['nickname'])
    mod_character.request_getinfo()

def getinfo_error_invalid_usrid(err):
    logger().info('invalid usr info')
    request_create_profile()

def request_create_profile():
    req = {}
    req['nickname'] = 'fox'
    req['character_id'] = 1
    dispatcher().send_msg(Msg('create_profile', req))

def create_profile_response(msg):
    logger().info('create profile succ')
    mod_character.request_getinfo()
