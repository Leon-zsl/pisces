#!/usr/bin/env python
# -*- coding:utf-8 -*-

from sqlalchemy import Column, Integer, String, ForeignKey
from model import Base

from models.job import Job
from models.level import Level

class Character(Base):
    __tablename__ = "character"

    id = Column(Integer, primary_key = True)
    name = Column(String(64))
    gender = Column(String(64))
    jobid = Column(Integer)
    levelid = Column(Integer)
