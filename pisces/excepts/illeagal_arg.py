# -*- coding:utf-8 -*-

from exception import PiscesException

class IlleagalArgExcept(PiscesException):
    def __init__(self, op, msg):
        self.op = op
        super.__init__(self, msg)
