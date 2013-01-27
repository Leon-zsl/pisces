#!/user/bin/env python 
# -*- coding:utf-8 -*-

from sqlalchemy import Column, Integer, String, ForeignKey
from model import Base

from models.character import Character

class User(Base):
    __tablename__ = "user"

    id = Column(Integer, primary_key = True)
    name = Column(String(64))
    characterid = Column(Integer)
