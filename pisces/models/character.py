#!/usr/bin/env python
# -*- coding:utf-8 -*-

from sqlalchemy import Column, Integer, BigInteger, String, ForeignKey
from model import Base

from models.job import Job
from models.level import Level

class Character(Base):
    __tablename__ = "character"

    id = Column(BigInteger, primary_key = True)
    name = Column(String(64))
    gender = Column(String(64))
    jobid = Column(BigInteger)
    levelid = Column(BigInteger)
