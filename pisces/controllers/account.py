# -*- coding:utf-8 -*-

from config import *

import app
import db
import log

import util.token as token
#import util.crypt as crypt

from models.account import Account
from models.profile import Profile

import protocol.error_code as error_code
import protocol.opcode_request as opcode_request
import protocol.opcode_response as opcode_response

import proto.common_pb2 as proto_common
import proto.account_pb2 as proto_account

from excepts.illeagal_msg import IlleagalMsgExcept

def db():
    return app.App.instance.db

def log_root():
    return app.App.instance.logger.root

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
    pwd = reg.pwd
    if len(pwd) > 32:
        err.errop = op
        err.errno = error_code.PWD_TO_LONG
        return opcode_response.REQUEST_ERROR, err.SerializeToString()

    query = db().query(Account)
    account = query.filter_by(name = reg.name).first()
    if not account:
        act = Account(query.count() + 1, reg.name, pwd)
        db().add(act)
        db().commit()
        #db().flush()

        log_root().info('create account: %s' % reg.name)
        
        ret = proto_account.RegisterResponse()
        return opcode_response.REGISTER_RESPONSE,ret.SerializeToString()
    else:
        err.errop = op
        err.errno = error_code.ACCOUNT_EXIST
        return opcode_response.REQUEST_ERROR, err.SerializeToString()

def login(op, msg):
    login = proto_account.Login()
    try:
        login.ParseFromString(msg)
    except:
        raise IlleagalMsgExcept(op, '')

    query = db().query(Account)
    account = query.filter_by(name = login.name).first()
    #pwd = crypt.des_decode(DES_KEY, login.pwd)
    pwd = login.pwd

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
        ret = proto_account.LoginResponse()
        ret.token = token.uid_to_token(account.usrid)
        return opcode_response.LOGIN_RESPONSE, ret.SerializeToString()
