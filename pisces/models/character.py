# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class Character(model.Base):
    __tablename__ = 'character'

    usrid = Column(Integer, 
                   primary_key=True,
                   nullable=False)
    
    characterid = Column(SmallInteger,
                         primary_key = True,
                         nullable=False)
    
    confid = Column(SmallInteger,
                    nullable=False)
    
    level = Column(SmallInteger,
                   nullable=False)
    
    hp = Column(Integer,
                nullable=False)
    
    mp = Column(Integer,
                nullable=False)
    
    attack = Column(Integer,
                    nullable=False)
    
    defense = Column(Integer,
                     nullable=False)

    def __init__(self, usrid, characterid, confid, 
                 level, hp, mp, attack, defense):
        self.usrid = usrid
        self.characterid = characterid
        self.confid = confid
        self.level = level
        self.hp = hp
        self.mp = mp
        self.attack = attack
        self.defense = defense
