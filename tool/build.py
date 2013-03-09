#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import sys

import except_handler
import path_util
import pck_config
from config import *

def build_conf():
    print "build conf begin..."
    pck_config.pack_config_dir(CONF_PATH,
                               CONF_CODE_PATH,
                               CONF_BIN_PATH,
                               CONF_CSV_PATH,
                               CONF_FACT_PY,
                               MAKO_PATH,
                               CONF_MAKO_PY,
                               CONF_FACT_MAKO_PY)
    print "build conf end"

def build():
    exhook = sys.excepthook
    sys.excepthook = except_handler._excepthook
    
    build_conf()

    sys.excepthook = exhook

if __name__ == '__main__':
    build()
