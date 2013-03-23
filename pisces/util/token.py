# -*- coding:utf-8 -*-

import base64
import mcrypt

from config import *

def parse_token(token):
    data = token.replace('.', '+').replace('_', '/') + '='
    data = base64.decodestring(data)
    mc = mcrypt.MCRYPT(MCRYPT_ALGORITHM, MCRYPT_MODE)
    mc.init(MCRYPT_KEY)
    val = mc.decrypt(data)
    uid, app_ver, lg_time = val.split('|')
    return [int(uid), app_ver, lg_time]

def gen_token(uid, app_ver, lg_time):
    data = str(uid) + '|' + app_ver + '|' + lg_time
    mc = mcrypt.MCRYPT(MCRYPT_ALGORITHM, MCRYPT_MODE)
    mc.init(MCRYPT_KEY)
    val = mc.encrypt(data)
    val = base64.encodestring(val)
    val = val.replace('+', '.').replace('/', '_').replace('=', '')
    return val

