# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class ORMProfile(model.Base):
    __tablename__ = 'profile'

    id = Column(Integer, 
                primary_key=True,
                nullable=False)
    
    name = Column(String(64), 
                  nullable=False)
    
    lev = Column(SmallInteger, 
                 nullable=False)
    
    exp = Column(Integer, 
                 nullable=False)
    
    gold = Column(Integer, 
                  nullable=False)
    
    gem = Column(Integer, 
                 nullable=False)

    def __init__(self, id, name, lev, exp, gold, gem):
        self.id = id
        self.name = name
        self.lev = lev
        self.exp = exp
        self.gold = gold
        self.gem = gem

class Profile(model.ModelMixin):
    cls_orm = ORMProfile
    enable_cache = True
    expire = 0

    @classmethod
    def create(cls, id, name, lev, exp, gold, gem):
        obj = cls()
        obj.orm = ORMProfile(id, name, lev, exp, gold, gem)
        cls.add(obj)
        return obj

