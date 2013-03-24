# -*- coding:utf-8 -*-

from config import *

import logging
import logging.config

class LoggerMgr(object):
    def __init__(self, conf):
        logging.config.fileConfig(conf)
        self.root = logging.getLogger("root")
        self.debug = logging.getLogger("debug")
        if DEV_LEV == 'product':
            self.root.setLevel(logging.INFO)
            self.debug.setLevel(logging.ERROR)
        else:
            self.root.setLevel(logging.INFO)
            self.debug.setLevel(logging.DEBUG)
        
    def __del__(self):
        self.close()

    def close(self):
        logging.shutdown()        
