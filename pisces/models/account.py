# -*- coding:utf-8 -*-

import model
from sqlalchemy import *

class ORMAccount(model.Base):
    __tablename__ = 'account'
    
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


class Account(model.ModelMixin):
    cls_orm = ORMAccount
    enable_cache = False
    expire = 0

    @classmethod
    def create(cls, id, name, pwd, lg_time):
        obj = cls()
        obj.orm = ORMAccount(id, name, pwd, lg_time)
        cls.add(obj)
        return obj
        
    @classmethod
    def get_by_name(cls, n):
        query = model.db().query(ORMAccount)
        orm = query.filter_by(name = n).first()
        if not orm:
            return None
        return cls._create_from_orm(orm)
