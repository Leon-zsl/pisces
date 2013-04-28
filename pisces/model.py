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

from config import *
import app

def log_root():
    return app.App.instance.logger.root

def log_rcd():
    return app.App.instance.logger.record

def cache():
    return app.App.instance.cache.mc

def db():
    return app.App.instance.db

def cache_key_prefix_by_db():
    return db().db_name + '_'

def cache_key_prefix_by_app():
    return 'pisces_' + APP_VERSION

class ModelMixin(object):
    """the child class must have the __tablename__ prop
       the child class must have the enable_cache prop
       the child class must have the id prop
       the child class must have the expire prop
       default key is id
    """
    @classmethod
    def is_cache_enable(cls):
        return SYS_ENABLE_CACHE and cls.enable_cache
    
    @classmethod
    def get_cache_key(cls, k):
        return cache_key_prefix_by_db() + cls.__tablename__ \
          + '_' + str(k)

    @classmethod
    def get_cache(cls, k):
        if cls.is_cache_enable() and k:
            return cache().get(k)
        else:
            return None

    @classmethod
    def set_cache(cls, k, v):
        if cls.is_cache_enable() and k and v:
            cache().set(k, v, cls.expire)

    @classmethod
    def add_cache(cls, k, v):
        if cls.is_cache_enable() and k and v:
            cache().add(k, v, cls.expire)

    @classmethod
    def del_cache(cls, k):
        if cls.is_cache_enable() and k:
            cache().delete(k)

    @classmethod
    def count(cls):
        query = db().query(cls)
        return query.count()

    @classmethod
    def get_by_key(cls, k):
        ck = cls.get_cache_key(k)
        val = cls.get_cache(ck)
        if val:
            return val

        query = db().query(cls)
        val = query.get(k)
        
        cls.add_cache(ck, val)
        return val

    @classmethod
    def get(cls, id):
        return cls.get_by_key(id)

    @classmethod
    def add_by_key(cls, k, v):
        db().add(v)
        db().commit()

        ck = cls.get_cache_key(k)
        cls.add_cache(ck, v)

    @classmethod
    def add(cls, v):
        cls.add_by_key(v.id, v)

    @classmethod
    def del_by_key(cls, k):
        query = db().query(cls)
        val = query.get(k)

        db().delete(val)
        db().commit()

        ck = cls.get_cache_key(k)
        cls.del_cache(ck)

    @classmethod
    def del_by_key_value(cls, k, v):
        db().delete(v)
        db().commit()

        ck = cls.get_cache_key(k)
        cls.del_cache(ck)

    @classmethod
    def delete(cls, v):
        cls.del_by_key_value(v.id, v)

    @classmethod
    def update_by_key_value(cls, k, v):
        db().commit()

        ck = cls.get_cache_key(k)
        cls.set_cache(ck, v)

    def update(self):
        db().commit()
        
        self.update_by_key_value(self.id, self)

    @classmethod
    def set_attrs_by_key(cls, key, dic):
        val = db().query(key)
        for k in dic:
            setattr(val, k, dic[k])

        cls.update_by_key_value(key, val)

    def sel_attrs(self, dic):
        self.set_attrs_by_key(self.id, dic)
