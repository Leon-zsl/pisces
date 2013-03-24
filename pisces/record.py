# -*- coding:utf-8 -*-

#import sqlalchemy
from sqlalchemy.ext.declarative import declarative_base

from sqlalchemy import MetaData
from sqlalchemy import Table
from sqlalchemy import Column
from sqlalchemy import ForeignKey

from sqlalchemy import String
from sqlalchemy import Integer
from sqlalchemy import BigInteger
from sqlalchemy import SmallInteger
from sqlalchemy import Float
from sqlalchemy import Boolean
from sqlalchemy import Enum
from sqlalchemy import CHAR
from sqlalchemy import DateTime

from sqlalchemy.dialects import mysql

Base = declarative_base()
