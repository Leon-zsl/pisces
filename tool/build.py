#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import sys
import os.path

import except_handler
import path_util
import pck_config
import pck_proto

from config import *

def build_conf_s():
    print "build conf py begin..."
    pck_config.pack_config_dir_py(CONF_PATH,
                                  CONF_CODE_PATH_PY,
                                  MAKO_PATH,
                                  CONF_FACT_PY,
                                  CONF_MAKO_PY,
                                  CONF_FACT_MAKO_PY)
    print "build conf py end"

def build_conf_c():
    print "build conf cpp begin..."
    pck_config.pack_config_dir_cc(CONF_PATH,
                                  CONF_CODE_PATH_C,
                                  MAKO_PATH,
                                  CONF_FACT_C,
                                  CONF_FACT_H,
                                  CONF_MAKO_C,
                                  CONF_MAKO_H,
                                  CONF_FACT_MAKO_C,
                                  CONF_FACT_MAKO_H)
    print "build conf cpp end"

def build_conf_d():
    print 'build conf data begin...'
    pck_config.pack_config_dir_data(CONF_PATH,
                                    CONF_BIN_PATH,
                                    CONF_CSV_PATH)
    print 'build conf data end'

def build_proto():
    print 'pck proto begin...'
    pck_proto.pck_proto()
    print 'pck proto end'

def gen_init_py(path):
    txt = r"""# -*_ coding: utf-8 -*-

import os
import os.path
    
__all__ = [pck.split('.')[0] for pck in os.listdir(os.path.split(os.path.realpath(__file__))[0]) if pck.endswith('.py') and pck != __file__ or os.path.isdir(os.path.join(os.path.realpath(__file__), pck))]
    """

    f = open(os.path.join(path, '__init__.py'), 'w')
    f.write(txt)
    f.close()

def cp_res():
    print 'cp res begin...'
    gen_init_py(EXP_PROTO_PATH_PY)
    path_util.copy_folder_type(EXP_PROTO_PATH_PY,
                               DST_PROTO_PATH_PY,
                               '.py')
    path_util.copy_folder_type(EXP_PROTO_PATH_PY,
                               DST_PROTO_PATH_R,
                               '.py')
    
    gen_init_py(CONF_CODE_PATH_PY)
    path_util.copy_folder_type(CONF_CODE_PATH_PY,
                               DST_CONF_CODE_PATH_PY,
                               '.py')
    path_util.copy_folder_type(CONF_CODE_PATH_PY,
                               DST_CONF_CODE_PATH_R,
                               '.py')
    print 'cp res end'
    
def build():
    exhook = sys.excepthook
    sys.excepthook = except_handler._excepthook

    build_proto()
    
    build_conf_s()
    build_conf_c()
    build_conf_d()

    cp_res()
    
    sys.excepthook = exhook

if __name__ == '__main__':
    build()
