#!/usr/bin/env python
# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class Account(model.Base):
    __tablename__ = "account"

    uid = Column(BigInteger, primary_key = True)
    name = Column(String(64))
    pwd = Column(String(16))

    def __init__(self, uid, name, pwd):
        self.uid = uid
        self.name = name
        self.pwd = pwd
