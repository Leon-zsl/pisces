# -*- coding:utf-8 -*-

import logging
import logging.config

class LoggerMgr(object):
    def __init__(self):
        logging.config.fileConfig("config/log.conf")
        self.root = logging.getLogger("root")
        self.support  = logging.getLogger("support")
        self.debug = logging.getLogger("debug")
        
    def __del__(self):
        self.close()

    def close(self):
        logging.shutdown()        
