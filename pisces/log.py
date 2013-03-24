# -*- coding:utf-8 -*-

import logging
import logging.config

class LoggerMgr(object):
    def __init__(self, conf, app_name):
        logging.config.fileConfig(conf)
        self.root = logging.getLogger("root")
        self.debug = logging.getLogger("debug")
        
    def __del__(self):
        self.close()

    def close(self):
        logging.shutdown()        
