#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import os.path
import sys

from config import *

def pck_proto():
    print 'pck request begin...'
    if not os.path.exists(EXP_PROTO_REQUEST_PATH_C):
        os.makedirs(EXP_PROTO_REQUEST_PATH_C)
    if not os.path.exists(EXP_PROTO_REQUEST_PATH):
        os.makedirs(EXP_PROTO_REQUEST_PATH)

    files = [f for f in os.listdir(PROTO_REQUEST_PATH) if f.endswith('.proto')]
    cmd = 'protoc'                                         \
      + ' --proto_path=' + PROTO_REQUEST_PATH              \
      + ' --cpp_out=' + EXP_PROTO_REQUEST_PATH_C           \
      + ' --python_out=' + EXP_PROTO_REQUEST_PATH
    for file in files:
        cmd += ' ' + os.path.join(PROTO_REQUEST_PATH, file)
    os.system(cmd)
    print 'pck request succ'

    print 'pck response begin...'
    files = [f for f in os.listdir(PROTO_RESPONSE_PATH) if f.endswith('.proto')]
    cmd = 'protoc'                                        \
      + ' --proto_path=' + PROTO_RESPONSE_PATH            \
      + ' --cpp_out=' + EXP_PROTO_RESPONSE_PATH_C         \
      + ' --python_out=' + EXP_PROTO_RESPONSE_PATH
    for file in files:
        cmd += ' ' + os.path.join(PROTO_RESPONSE_PATH, file)
    os.system(cmd)
    print 'pck response succ'
