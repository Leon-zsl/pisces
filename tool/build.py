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

def build_conf_py():
    print "build conf py begin..."
    pck_config.pack_config_dir_py(CONF_PATH,
                                  CONF_CODE_PATH_PY,
                                  MAKO_PATH,
                                  CONF_FACT_PY,
                                  CONF_MAKO_PY,
                                  CONF_FACT_MAKO_PY)
    print "build conf py end"

def build_conf_cc():
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

def build_conf_lua():
    print 'build conf lua begin...'
    pck_config.pack_config_dir_lua(CONF_PATH,
                                   CONF_CODE_PATH_LUA,
                                   MAKO_PATH,
                                   CONF_FACT_LUA,
                                   CONF_MAKO_LUA,
                                   CONF_FACT_MAKO_LUA)    
    print 'build conf lua end'

def build_conf_data():
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

def cp_conf_res():
    gen_init_py(CONF_CODE_PATH_PY)
    path_util.copy_folder_type(CONF_CODE_PATH_PY,
                               DST_CONF_CODE_PATH_PY,
                               '.py')
    path_util.copy_folder_type(CONF_CODE_PATH_PY,
                               DST_CONF_CODE_PATH_R,
                               '.py')
    
def cp_proto_res():
    gen_init_py(EXP_PROTO_PATH_PY)
    path_util.copy_folder_type(EXP_PROTO_PATH_PY,
                               DST_PROTO_PATH_PY,
                               '.py')
    path_util.copy_folder_type(EXP_PROTO_PATH_PY,
                               DST_PROTO_PATH_R,
                               '.py')
    
def build():
    exhook = sys.excepthook
    sys.excepthook = except_handler._excepthook

    if len(sys.argv) < 2 or sys.argv[1].lower().strip() == 'all':
        #build_proto()
        build_conf_py()
        build_conf_cc()
        build_conf_lua()
        build_conf_data()
    elif sys.argv[1].lower().strip() == 'proto':
        #build_proto()
        print 'do not support proto now'
    elif sys.argv[1].lower().strip() == 'conf':
        if len(sys.argv) < 3 or sys.argv[2].lower().strip() == 'all':
            build_conf_py()
            build_conf_cc()
            build_conf_lua()
            build_conf_data()
        elif sys.argv[2].lower().strip() == 'py':
            build_conf_py()
            #build_conf_data()
        elif sys.argv[2].lower().strip() == 'cc':
            build_conf_cc()
            #build_conf_data()
        elif sys.argv[2].lower().strip() == 'lua':
            build_conf_lua()
            #build_conf_data()
        elif sys.argv[2].lower().strip() == 'data':
            build_conf_data()
            
    cp_conf_res()
    #cp_proto_res()
    
    sys.excepthook = exhook

if __name__ == '__main__':
    build()
