#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import os.path
import sys

from config import *

def pck_proto():
    print 'pck proto begin...'
    if not os.path.exists(EXP_PROTO_PATH):
        os.makedirs(EXP_PROTO_PATH)
    if not os.path.exists(EXP_PROTO_PATH_C):
        os.makedirs(EXP_PROTO_PATH_C)

    files = [f for f in os.listdir(PROTO_PATH) if f.endswith('.proto')]
    cmd = 'protoc'                                 \
      + ' --proto_path=' + PROTO_PATH              \
      + ' --cpp_out=' + EXP_PROTO_PATH_C           \
      + ' --python_out=' + EXP_PROTO_PATH
    for file in files:
        cmd += ' ' + os.path.join(PROTO_PATH, file)
    os.system(cmd)
    print 'pck proto succ'
