# -*- coding:utf-8 -*-

import base64
import mcrypt
import hashlib

from config import *

def parse_token(token):
    cnt = int(token[-1])
    data = (token[0:-1].replace('.', '+').replace('_', '/') + '=' * cnt)
    data = base64.decodestring(data)
    mc = mcrypt.MCRYPT(MCRYPT_ALGORITHM, MCRYPT_MODE)
    mc.init(MCRYPT_KEY)
    val = mc.decrypt(data)
    crc = val[0:8]
    info = val[8:len(val)]
    if crc != str(hashlib.md5(info).hexdigest())[0:8]:
        return []
    else:
        uid, app_ver, lg_time = info.split('|')
        return [int(uid), app_ver, lg_time]

def gen_token(uid, app_ver, lg_time):
    info = str(uid) + '|' + app_ver + '|' + lg_time
    crc = str(hashlib.md5(info).hexdigest())[0:8]
    data = crc + info
    mc = mcrypt.MCRYPT(MCRYPT_ALGORITHM, MCRYPT_MODE)
    mc.init(MCRYPT_KEY)
    val = mc.encrypt(data)
    val = base64.encodestring(val)
    cnt = val.count('=')
    val = val.replace('+', '.').replace('/', '_').replace('=', '') + str(cnt)
    return val

