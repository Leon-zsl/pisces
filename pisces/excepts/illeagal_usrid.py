# -*- coding:utf-8 -*-

from exception import PiscesException

class IlleagalUsridExcept(PiscesException):
    def __init__(self, op, msg):
        self.op = op
        super.__init__(self, msg)
