#!/usr/bin/env python
# -*- coding:utf-8 -*-

import base64
import mcrypt

from config import *

def token_to_uid(token):
    data = token.replace('.', '+').replace('_', '/') + '='
    data = base64.decodestring(data)
    mc = mcrypt.MCRYPT(MCRYPT_ALGORITHM, MCRYPT_MODE)
    mc.init(MCRYPT_KEY)
    val = mc.decrypt(data)
    return int(val)

def uid_to_token(uid):
    data = str(uid)
    if len(data) < 20:
        data = '0' * (20 - len(data)) + data
    mc = mcrypt.MCRYPT(MCRYPT_ALGORITHM, MCRYPT_MODE)
    mc.init(MCRYPT_KEY)
    val = mc.encrypt(data)
    val = base64.encodestring(val)
    val = val.replace('+', '.').replace('/', '_').replace('=', '')
    return val

