# -*- coding:utf-8 -*-

import random
import time
import hashlib

import app
import db
import log

from config import *
import util.token as token
#import util.crypt as crypt

from util.jsonobj import JsonObject

from models.account import Account

import protocol.error_code as error_code

def db():
    return app.App.instance.db

def log_rcd():
    return app.App.instance.logger.record

def log_root():
    return app.App.instance.logger.root

def create_account(reg):
    salt = str(random.randint(0, 10000000))
    salt = '0' * (8 - len(salt)) + salt
    pwd = salt + str(hashlib.md5(salt + reg.pwd).hexdigest())
    
    t = time.gmtime()
    t = '%d:%d:%d:%d:%d:%d' % (t.tm_year, t.tm_mon, t.tm_mday,
                               t.tm_hour, t.tm_min, t.tm_sec)
    uid = Account.count() + 1
    act = Account(uid, reg.name, pwd, t)
    Account.add(act)
    
    log_rcd().record('create_account',
                     {'uid' : uid, 
                      'name' : name})
    
    log_root().info('create account: %s' % reg.name)

def register(op, msg):
    err = JsonObject()
    if not msg.name:
        err.errop = op
        err.errno = error_code.EMPTY_NAME
        err.errmsg = ''
        return 'request_error', err
    if len(msg.name) > 64:
        err.errop = op
        err.errno = error_code.NAME_TO_LONG
        err.errmsg = ''
        return 'request_error', err
    
    #pwd = crypt.des_decode(DES_KEY, reg.pwd)
    if len(msg.pwd) > 24:
        err.errop = op
        err.errno = error_code.PWD_TO_LONG
        err.errmsg = ''
        return 'request_error', err

    account = Account.get_by_name(msg.name)
    if not account:
        create_account(msg)
        ret = JsonObject()
        return 'register_response',ret
    else:
        err.errop = op
        err.errno = error_code.ACCOUNT_EXIST
        err.errmsg = ''
        return 'request_error', err

def login(op, msg, req_handler):
    account = Account.get_by_name(msg.name)

    err = JsonObject()
    if not account:
        err.errop = op
        err.errno = error_code.ACCOUNT_NOT_EXIST
        err.errmsg = ''
        return 'request_error', err

    #pwd = crypt.des_decode(DES_KEY, login.pwd)
    salt = account.pwd[0:8]
    pwd = salt + str(hashlib.md5(salt + msg.pwd).hexdigest())
    if pwd != account.pwd:
        err.errop = op
        err.errno = error_code.ACCOUNT_INVALID_PWD
        err.errmsg = ''
        return 'request_error', err
    
    log_root().info('account login: %s' % msg.name)
    t = time.gmtime()
    t = '%d:%d:%d:%d:%d:%d' % (t.tm_year, t.tm_mon, t.tm_mday,
                               t.tm_hour, t.tm_min, t.tm_sec)
    account.login_time = t
    account.update()
    
    log_rcd().record('login_account',
                     {'uid' : account.id,
                      'name' : account.name,
                      'login_time' : t})
        
    ret = JsonObject()
    ret.token = token.gen_token(account.id, APP_VERSION, t)
    return 'login_response', ret
