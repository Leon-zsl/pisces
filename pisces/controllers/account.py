# -*- coding:utf-8 -*-

from config import *

import app
import db
import log

import util.token as token
#import util.crypt as crypt

from models.account import Account

import protocol.error_code as error_code
import protocol.opcode_request as opcode_request
import protocol.opcode_response as opcode_response

import proto.account_pb2 as proto_account

from excepts.illeagal_msg import IlleagalMsgExcept

def db():
    return app.App.instance.db

def register(op, msg):
    reg = proto_account.Register()
    try:
        reg.ParseFromString(msg)
    except:
        raise IlleagalMsgExcept(op, '')

    ret = proto_account.RegisterResponse()
    if not reg.name:
        ret.status = error_code.EMPTY_NAME
        return ret
    if len(reg.name) > 64:
        ret.status = error_code.NAME_TO_LONG
        return ret
    
    #pwd = crypt.des_decode(DES_KEY, reg.pwd)
    pwd = reg.pwd
    if len(pwd) > 32:
        ret.status = error_code.PWD_TO_LONG
        return ret

    query = db().query(Account)
    account = query.filter_by(name = reg.name).first()

    if not account:
        act = Account(query.count() + 1, reg.name, pwd)
        db().add(act)
        ret.status = error_code.NO_ERROR
    else:
        ret.status = error_code.ACCOUNT_EXIST
    return opcode_response.REGISTER_RESPONSE, ret.SerializeToString()

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

    ret = proto_account.LoginResponse()
    if not account:
        ret.status = error_code.ACCOUNT_NOT_EXIST
        ret.token = token.uid_to_token(0)
    elif pwd != account.pwd:
        ret.status = error_code.ACCOUNT_INVALID_PWD
        ret.token = token.uid_to_token(0)
    else:
        ret.status = error_code.NO_ERROR
        ret.token = token.uid_to_token(account.usrid)
    return opcode_response.LOGIN_RESPONSE, ret.SerializeToString()
