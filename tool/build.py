#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import sys

import except_handler
import path_util
import pck_config
from config import *

def build_conf_s():
    print "build conf server begin..."
    pck_config.pack_config_dir_py(CONF_PATH,
                                  CONF_CODE_PATH,
                                  CONF_BIN_PATH,
                                  CONF_CSV_PATH,
                                  CONF_FACT_PY,
                                  MAKO_PATH,
                                  CONF_MAKO_PY,
                                  CONF_FACT_MAKO_PY)
    print "build conf server end"

def build_conf_c():
    print "build conf client begin..."
    pck_config.pack_config_dir_cc(CONF_PATH,
                                  CONF_CODE_PATH_C,
                                  CONF_BIN_PATH_C,
                                  CONF_CSV_PATH_C,
                                  MAKO_PATH,
                                  CONF_FACT_C,
                                  CONF_FACT_H,
                                  CONF_MAKO_C,
                                  CONF_MAKO_H,
                                  CONF_FACT_MAKO_C,
                                  CONF_FACT_MAKO_H)
    print "build conf client end"

def build():
    exhook = sys.excepthook
    sys.excepthook = except_handler._excepthook
    
    #build_conf_s()
    build_conf_c()
    
    sys.excepthook = exhook

if __name__ == '__main__':
    build()
