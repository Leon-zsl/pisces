# -*- coding:utf-8 -*-

from config import *

import logging
import logging.config

from datetime import date 

class LoggerMgr(object):
    def __init__(self, conf):
        logging.config.fileConfig(conf)

        self.root = logging.getLogger('root')
        if DEV_LEV == 'product':
            self.root.setLevel(logging.INFO)
        elif DEV_LEV == 'develop':
            self.root.setLevel(logging.INFO)
        else:
            self.root.setLevel(logging.DEBUG)

#        self.record = logging.getLogger('record')
        
    def __del__(self):
        self.close()

    def close(self):
        logging.shutdown()        
