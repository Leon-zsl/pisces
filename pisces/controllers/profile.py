# -*- coding:utf-8 -*-

import app
import db
import log

from models.profile import Profile

import protocol.error_code as error_code
import protocol.opcode_request as opcode_request
import protocol.opcode_response as opcode_response

import proto.common_pb2 as proto_common
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

    if not profile:
        err = proto_common.RequestError()
        err.errop = op
        err.errno = error_code.ILLEAGAL_USRID
        return opcode_response.REQUEST_ERROR, err.SerializeToString()
    else:
        ret = proto_profile.GetProfileInfoResponse()
        ret.name = profile.name
        ret.lev = profile.lev
        ret.exp = profile.exp
        ret.gold = profile.gold
        ret.gem = profile.gem
        return opcode_response.GET_PROFILE_INFO_RESPONSE, \
          ret.SerializeToString()

    
