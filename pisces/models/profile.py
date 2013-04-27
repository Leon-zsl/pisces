# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class Profile(model.Base, model.ModelMixin):
    enable_cache = True
    expire = 0
    
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
