# -*- coding:utf-8 -*-

import app
import log

from models.profile import Profile
from util.jsonobj import JsonObject

import protocol.error_code as error_code

def log_root():
    return app.App.instance.logger.root

def create_profile(op, msg, usrid):
    pf = Profile.get(usrid)
    if pf:
        err = JsonObject()
        err.errop = op
        err.errno = ACCOUNT_EXIST
        err.errmsg = ''
        return 'request_error', err
    
    pf = Profile(usrid, msg.nickname, 1, 0, 0, 0)
    Profile.add(pf)
    
    log_root().info('create profile %d:%s' % (usrid, msg.nickname))

    ret = JsonObject()
    return 'create_profile_response', ret

def get_info(op, msg, usrid):
    profile = Profile.get(usrid)
    if not profile:
        err = JsonObject()
        err.errop = op
        err.errno = error_code.ILLEAGAL_USRID
        err.errmsg = ''
        return 'request_error', err
    else:
        ret = JsonObject()
        ret.nickname = profile.name
        ret.lev = profile.lev
        ret.exp = profile.exp
        ret.gold = profile.gold
        ret.gem = profile.gem
        return 'get_profile_info_response', ret
