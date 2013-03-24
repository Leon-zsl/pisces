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

from models.account import Account
from models.profile import Profile

from records.login import LoginRecord

import protocol.error_code as error_code
import protocol.opcode_request as opcode_request
import protocol.opcode_response as opcode_response

import proto.common_pb2 as proto_common
import proto.account_pb2 as proto_account

from excepts.illeagal_msg import IlleagalMsgExcept

def db():
    return app.App.instance.db

def db_rcd():
    return app.App.instance.db_record

def log_root():
    return app.App.instance.logger.root

def create_account(reg, query):
    salt = str(random.randint(0, 10000000))
    salt = '0' * (8 - len(salt)) + salt
    pwd = salt + str(hashlib.md5(salt + reg.pwd).hexdigest())
    
    t = time.gmtime()
    t = "%d:%d:%d:%d:%d:%d" % (t.tm_year, t.tm_mon, t.tm_mday,
                               t.tm_hour, t.tm_min, t.tm_sec)
    uid = query.count() + 1
    act = Account(uid, reg.name, pwd, t)
    db().add(act)
    db().commit()
    #db().flush()
    
    lt = "%d:%d:%d:%d:%d:%d" % (0, 0, 0, 0, 0, 0)
    lgrcd = LoginRecord(uid, reg.name, t, lt, 0, 0, 0)
    db_rcd().add(lgrcd)
    db_rcd().commit()
    
    log_root().info('create account: %s' % reg.name)

def register(op, msg):
    reg = proto_account.Register()
    try:
        reg.ParseFromString(msg)
    except:
        raise IlleagalMsgExcept(op, '')

    err = proto_common.RequestError()
    if not reg.name:
        err.errop = op
        err.errno = error_code.EMPTY_NAME
        return opcode_response.REQUEST_ERROR, err.SerializeToString()
    if len(reg.name) > 64:
        err.errop = op
        err.errno = error_code.NAME_TO_LONG
        return opcode_response.REQUEST_ERROR, err.SerializeToString()
    
    #pwd = crypt.des_decode(DES_KEY, reg.pwd)
    if len(reg.pwd) > 24:
        err.errop = op
        err.errno = error_code.PWD_TO_LONG
        return opcode_response.REQUEST_ERROR, err.SerializeToString()

    query = db().query(Account)
    account = query.filter_by(name = reg.name).first()
    if not account:
        create_account(reg, query)
        ret = proto_account.RegisterResponse()
        return opcode_response.REGISTER_RESPONSE,ret.SerializeToString()
    else:
        err.errop = op
        err.errno = error_code.ACCOUNT_EXIST
        return opcode_response.REQUEST_ERROR, err.SerializeToString()

def login(op, msg, req_handler):
    login = proto_account.Login()
    try:
        login.ParseFromString(msg)
    except:
        raise IlleagalMsgExcept(op, '')

    query = db().query(Account)
    account = query.filter_by(name = login.name).first()
    #pwd = crypt.des_decode(DES_KEY, login.pwd)
    salt = account.pwd[0:8]
    pwd = salt + str(hashlib.md5(salt + login.pwd).hexdigest())

    err = proto_common.RequestError()
    if not account:
        err.errop = op
        err.errno = error_code.ACCOUNT_NOT_EXIST
        return opcode_response.REQUEST_ERROR, err.SerializeToString()
    elif pwd != account.pwd:
        err.errop = op
        err.errno = error_code.ACCOUNT_INVALID_PWD
        return opcode_response.REQUEST_ERROR, err.SerializeToString()
    else:
        log_root().info('account login: %s' % login.name)
        t = time.gmtime()
        t = "%d:%d:%d:%d:%d:%d" % (t.tm_year, t.tm_mon, t.tm_mday,
                                  t.tm_hour, t.tm_min, t.tm_sec)
        account.login_time = t
        db().commit()

        qry_rcd = db_rcd().query(LoginRecord)
        lgrcd = qry_rcd.get(account.usrid)
        first_login = not lgrcd.login_count
        
        lgrcd.last_login_time, lgrcd.login_time = lgrcd.login_time, t
        lgrcd.login_count += 1
        
        if first_login:
            lgrcd.total_login_days = 1
            lgrcd.continuous_login_days = 1
        else:
            lt = lgrcd.last_login_time
            ct = lgrcd.login_time
            v = lt.split(':')
            lm, ld = int(v[1]), int(v[2])
            v = ct.split(':')
            cm, cd = int(v[1]), int(v[2])
            if lm < cm or ld < cd:
                lgrcd.total_login_days += 1
            if lm == cm and ld == cd - 1:
                lgrcd.continuous_login_days += 1
        db_rcd().commit()
        
        ret = proto_account.LoginResponse()
        ret.token = token.gen_token(account.usrid, APP_VERSION, t)
        return opcode_response.LOGIN_RESPONSE, ret.SerializeToString()
