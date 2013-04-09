# -*- coding:utf-8 -*-

import app
import db
import log

from models.profile import Profile

import protocol.error_code as error_code

def db():
    return app.App.instance.db

def log_root():
    return app.App.instance.logger.root

def create_profile(op, msg, usrid):
    query = db().query(Profile)
    pf = query.get(usrid)
    if pf:
        err = {}
        err['errop'] = op
        err['errno'] = ACCOUNT_EXIST
        err['errmsg'] = ''
        return 'request_error', err
    
    pf = Profile(usrid, msg['nickname'], 1, 0, 0, 0)
    db().add(pf)
    db().commit()
    #db().flush()

    log_root().info('create profile %d:%s' % (usrid, msg['nickname']))

    ret = {}
    return 'create_profile_response', ret

def get_info(op, msg, usrid):
    query = db().query(Profile)
    profile = query.get(usrid)

    if not profile:
        err = {}
        err['errop'] = op
        err['errno'] = error_code.ILLEAGAL_USRID
        err['errmsg'] = ''
        return 'request_error', err
    else:
        ret = {}
        ret['nickname'] = profile.name
        ret['lev'] = profile.lev
        ret['exp'] = profile.exp
        ret['gold'] = profile.gold
        ret['gem'] = profile.gem
        return 'get_profile_info_response', ret
