#!/usr/bin/env python
# -*- coding:utf-8 -*-

import app
import db
import log

from models.account import Account

import protocol.error_code as error_code
import protocol.opcode_request as opcode_request
import protocol.opcode_response as opcode_response

import pb2.request_pb2 as request_pb2
import pb2.response_pb2 as response_pb2

def db():
    return app.App.instance.db

def register(op, msg):
    pass

def login(op, msg):
    login = request_pb2.Login()
    try:
        login.ParseFromString(msg)
    except:
        err = response_pb2.RequestError()
        err.errop = op
        err.errno = error_code.ILLEAGAL_MSG_FORMAT
        err.errerrmsg = ""
        return opcode_response.REQUESTERROR, err.SerializeToString()

    query = db().query(Account)
    account = query.get(login.name)
    if not account:
        userid = query.count() + 1
        account = Account(userid, login.name, login.pwd)
        db().add(account)
        db().commit()
    
    ret = response_pb2.LoginSuccess()
    ret.userid = account.uid
    return opcode_response.LOGINSUCC, ret.SerializeToString()

def logout(op, msg, usrid):
    pass
