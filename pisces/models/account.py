# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class Account(model.Base, model.ModelMixin):
    __tablename__ = 'account'
    
    enable_cache = False

    id = Column(Integer,
                primary_key=True,
                nullable=False)
    
    name = Column(String(64),
                  nullable=False,
                  unique=True)
    
    pwd = Column(String(64),
                 nullable=False)

    login_time = Column(String(64),
                        nullable = False)

    def __init__(self, id, name, pwd, lg_time):
        self.id = id
        self.name = name
        self.pwd = pwd
        self.login_time = lg_time

    @classmethod
    def get_by_name(cls, n):
        query = model.db().query(cls)
        return query.filter_by(name = n).first()
