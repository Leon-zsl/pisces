# -*- coding:utf-8 -*-

class PiscesException(Exception):
    def __init__(self, msg):
        self.msg = msg

    def __str__(self):
        return repr(self.msg)
