#!/usr/bin/env python
# -*- coding:utf-8 -*-

import base64

def token_to_uid(token):
    return int(base64.decodestring(token))

def uid_to_token(uid):
    return base64.encodestring(str(uid))

