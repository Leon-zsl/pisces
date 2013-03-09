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
CONF_CODE_PATH = os.path.join(SRC_PATH, 'data')
CONF_BIN_PATH = os.path.join(ROOT_PATH, 'data')
CONF_CSV_PATH = os.path.join(ROOT_PATH, 'csv')
CONF_FACT_PY = "ConfFact.py"
CONF_MAKO_PY = "Config_py.mako"
CONF_FACT_MAKO_PY = "ConfFact_py.mako"
