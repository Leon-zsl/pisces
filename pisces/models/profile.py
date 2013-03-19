# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class Profile(model.Base):
    __tablename__ = "profile"

    usrid = Column(Integer, 
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

    def __init__(self, usrid, name, lev, exp, gold, gem):
        self.usrid = usrid
        self.name = name
        self.lev = lev
        self.exp = exp
        self.gold = gold
        self.gem = gem
