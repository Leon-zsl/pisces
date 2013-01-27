#!/usr/bin/env python
# -*- coding:utf-8 -*-

from sqlalchemy import Column, Integer, String, ForeignKey
from model import Base

from models.user import User

class Account(Base):
    __tablename__ = "account"

    name = Column(String(64), primary_key = True)
    pwd = Column(String(64))
    userid = Column(Integer)

    def __init__(self, name, pwd, userid):
        self.name = name
        self.pwd = pwd
        self.userid = userid
