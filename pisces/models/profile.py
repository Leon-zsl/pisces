#!/usr/bin/env python
# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class Profile(model.Base):
    __tablename__ = "base_info"

    usrid = Column(Integer, primary_key = True)
    name = Column(String(64))
    lev = Column(SmallInteger)
    exp = Column(Integer)
    gold = Column(Integer)
    diamond = Column(Integer)

    def __init__(self, usrid, name, exp, gold, diamond)
        self.usrid = usrid
        self.usrid = usrid
        self.name = name
        self.exp = exp
        self.gold = gold
        self.diamond = diamond
