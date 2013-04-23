# -*- coding:utf-8 -*-

from ConfigParser import ConfigParser
import time
from datetime import date
import os
import os.path
import sys

class Recorder(object):
    def __init__(self, conf):
        parser = ConfigParser()
        parser.read(conf)
        p = parser.get('record', 'path')
        t = date.today()
        f = self.get_file_name(t) 
        self.record_path = p
        self.record_time = t
        self.record_file = open(os.path.join(p, f), 'ab')
        
    def close(self):
        self.record_file.flush()
        self.record_file.close()

    def record(self, tag, msg_dic):
        rcd = self.get_log()
        msg = self.fmt_msg(tag, msg_dic)
        rcd.write(msg)
        rcd.flush()

    def get_log(self):
        t = date.today()
        r = self.record_time
        if t.year != r.year or t.month != r.month or t.day != r.day:
            self.record_file.close()

            p = self.record_path
            f = self.get_file_name(t)

            self.record_time = t
            self.record_file = open(os.path.join(p, f), 'wb')

        return self.record_file

    def get_file_name(self, t):
        return 'record_' + str(os.getpid()) + '_' + \
          str(t.year) + '_' + str(t.month) + '_' + str(t.day) + \
          '.log'

    def fmt_msg(self, tag, msg_dic):
        # t = time.gmtime()
        # t = '[%d:%d:%d:%d:%d:%d]' % (t.tm_year, t.tm_mon, t.tm_mday,
        #                              t.tm_hour, t.tm_min, t.tm_sec)
        tags = '[' + tag + ']'
        msgs = '['
        for k in msg_dic:
            msgs += str(k) + ':' + str(msg_dic[k]) + ','
        msgs = msgs.strip(',') + ']'
        return tags + msgs + '\n'
