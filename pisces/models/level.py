#!/usr/bin/env python
# -*- coding:utf-8 -*-

from sqlalchemy import Column, Integer, String, ForeignKey
from model import Base

class Level(Base):
    __tablename__ = "level"

    id = Column(Integer, primary_key = True)
    level = Column(Integer)
    exp = Column(Integer)
