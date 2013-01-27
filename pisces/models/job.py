#!/usr/bin/env python
# -*- coding:utf-8 -*-

from sqlalchemy import Column, Integer, String, ForeignKey
from model import Base

class Job(Base):
    __tablename__ = "job"

    id = Column(Integer, primary_key = True)
    name = Column(String(64))
