#!/usr/bin/env python
# -*- coding:utf-8 -*-

import app
import db
import log

from models.profile import Profile

import protocol.error_code as error_code
import protocol.opcode_request as opcode_request
import protocol.opcode_response as opcode_response

import proto.profile_pb2 as proto_profile

from excepts.illeagal_usrid import IlleagalUsridExcept

def db():
    return app.App.instance.db

def log_root():
    return app.App.instance.logger.root

def get_info(op, msg, usrid):
    req = proto_profile.GetProfileInfo()
    try:
        req.ParseFromString(msg)
    except:
        raise IlleagalMsgExcept(op, '')

    query = db().query(Profile)
    profile = query.get(usrid)

    ret = proto_profile.GetProfileInfoResponse()
    if not profile:
        ret.status = error_code.ILLEAGAL_USRID
    else:
        ret.status = error_code.NO_ERROR
        ret.name = profile.name
        ret.lev = profile.lev
        ret.exp = profile.exp
        ret.gold = profile.gold
        ret.gem = profile.gem
    return opcode_response.GET_PROFILE_INFO_RESPONSE,ret.SerializeToString()

    
