# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class Account(model.Base):
    __tablename__ = "account"

    usrid = Column(Integer,
                   primary_key=True,
                   nullable=False)
    
    name = Column(String(64),
                  nullable=False,
                  unique=True)
    
    pwd = Column(String(32),
                 nullable=False)

    def __init__(self, usrid, name, pwd):
        self.usrid = usrid
        self.name = name
        self.pwd = pwd
