#!/usr/bin/env python
# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class Card(mode.Base):
    __tablename__ = 'card'

    usrid = Column(Integer, primary_key = True)
    cardid = Column(SmallInteger, primary_key = True)
    confid = Column(Integer)
    level = Column(SmallInteger)
    hp = Column(Integer)
    mp = Column(Integer)
    attack = Column(Integer)
    defense = Column(Integer)

    def __init__(self, usrid, cardid, confid, level, hp, mp, 
                 attack, defense):
        self.usrid = usrid
        self.cardid = cardid
        self.confid = confid
        self.level = level
        self.hp = hp
        self.mp = mp
        self.attack = attack
        self.defense = defense
    
    
