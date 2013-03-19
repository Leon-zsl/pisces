# -*- coding:utf-8 -*-

class Msg(object):
    def __init__(self, op, data):
        self.opcode = op
        self.data = data
