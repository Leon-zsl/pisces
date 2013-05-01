# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class ORMCharacter(model.Base):
    __tablename__ = 'character'

    id = Column(Integer, 
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

    def __init__(self, id, characterid, confid, 
                 level, hp, mp, attack, defense):
        self.id = id
        self.characterid = characterid
        self.confid = confid
        self.level = level
        self.hp = hp
        self.mp = mp
        self.attack = attack
        self.defense = defense

class Character(model.ModelMixin):
    cls_orm = ORMCharacter
    enable_cache = True
    expire = 0

    @classmethod
    def create(cls, id, characterid, confid, 
               level, hp, mp, attack, defense):
        obj = cls()
        obj.orm = ORMCharacter(id, characterid, confid, 
                               level, hp, mp, attack, defense)
        cls.add(obj)
        return obj

