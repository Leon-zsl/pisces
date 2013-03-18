# -*- coding:utf-8 -*-
"""path config
"""

import os

#gobal path config
CWD = os.path.normpath(os.path.abspath(os.getcwd()))

ROOT_PATH = os.path.normpath(os.path.abspath(os.path.join(CWD, '../')))
SRC_PATH = os.path.join(ROOT_PATH, 'pisces')
CONF_PATH = os.path.join(ROOT_PATH, 'conf')
TOOL_PATH = os.path.join(ROOT_PATH, 'tool')
MAKO_PATH = os.path.join(TOOL_PATH, 'mako')
EXP_PATH = os.path.join(ROOT_PATH, 'exp')
ROBOT_PATH = os.path.join(ROOT_PATH, 'robot')
PROTO_PATH = os.path.join(ROOT_PATH, 'proto')

EXP_CONF_PATH = os.path.join(EXP_PATH, 'conf')
CONF_CODE_PATH_PY = os.path.join(EXP_CONF_PATH, 'py')
CONF_CODE_PATH_C = os.path.join(EXP_CONF_PATH, 'cpp')
CONF_BIN_PATH = os.path.join(EXP_CONF_PATH, 'data')
CONF_CSV_PATH = os.path.join(EXP_CONF_PATH, 'csv')
CONF_FACT_PY = "ConfFact.py"
CONF_MAKO_PY = "Config_py.mako"
CONF_FACT_MAKO_PY = "ConfFact_py.mako"
CONF_FACT_C = "ConfFact.cpp"
CONF_FACT_H = "ConfFact.h"
CONF_MAKO_C = 'Config_cc.mako'
CONF_MAKO_H = 'Config_h.mako'
CONF_FACT_MAKO_C = 'ConfFact_cc.mako'
CONF_FACT_MAKO_H = 'ConfFact_h.mako'

EXP_PROTO_PATH = os.path.join(EXP_PATH, 'proto')
EXP_PROTO_PATH_PY = os.path.join(EXP_PROTO_PATH, 'py')
EXP_PROTO_PATH_C = os.path.join(EXP_PROTO_PATH, 'cpp')

DST_PROTO_PATH_PY = os.path.join(SRC_PATH, 'proto')
DST_PROTO_PATH_R = os.path.join(ROBOT_PATH, 'proto')
DST_CONF_CODE_PATH_PY = os.path.join(SRC_PATH, 'data')
DST_CONF_CODE_PATH_R = os.path.join(ROBOT_PATH, 'data')


