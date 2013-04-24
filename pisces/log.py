# -*- coding:utf-8 -*-

from config import *

import logging
import logging.config

import time
from datetime import date 

class Recorder(object):
    def __init__(self, lg):
        self.lg = lg

    def record(self, tag, msg_dic):
        msg = self.fmt_msg(tag, msg_dic)
        self.lg.info(msg)
        
    def fmt_msg(self, tag, msg_dic):
        t = time.gmtime()
        t = '[%d:%d:%d:%d:%d:%d]' % (t.tm_year, t.tm_mon, t.tm_mday,
                                     t.tm_hour, t.tm_min, t.tm_sec)
        tags = '[' + tag + ']'
        msgs = '['
        for k in msg_dic:
            msgs += str(k) + ':' + str(msg_dic[k]) + ','
        msgs = msgs.strip(',') + ']'
        return t + tags + msgs

class LoggerMgr(object):
    def __init__(self, conf):
        logging.config.fileConfig(conf)

        self.root = logging.getLogger('root')
        self.record = Recorder(logging.getLogger('record'))
        
    def __del__(self):
        self.close()

    def close(self):
        logging.shutdown()        
