#!/usr/bin/env python
# -*- coding:utf-8 -*-

import app
import db
import log

from models.account import Account

import protocol.error_code as error_code
import protocol.opcode_request as opcode_request
import protocol.opcode_response as opcode_response

import proto.request.account_pb2 as request_account

import proto.response.common_pb2 as response_common
import proto.response.account_pb2 as response_account

from excepts.illeagal_msg import IlleagalMsgExcept

def db():
    return app.App.instance.db

def register(op, msg):
    pass

def login(op, msg):
    login = request_account.Login()
    try:
        login.ParseFromString(msg)
    except:
        raise IlleagalMsgExcept('');

    query = db().query(Account)
    account = query.get(login.name)

    ret = response_account.LoginResponse()
    if not account:
        ret.status = error_code.NOT_LOGIN
        ret.token = ''
    else:
        ret.status = error_code.NO_ERROR
        ret.token = account.usrid
    return opcode_response.LOGIN_RESPONSE, ret.SerializeToString()

def logout(op, msg, usrid):
    pass
