#!/usr/bin/env python
# -*- coding:utf-8 -*-

#import sqlalchemy
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import MetaData, Table, Column, Integer, ForeignKey, String

Base = declarative_base()

#import all models
from models import *

def build_tables(engine):
    Base.metadata.create_all(engine)
