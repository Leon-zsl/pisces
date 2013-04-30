__COMPLETER_all_completions# -*- coding:utf-8 -*-

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

import pickle
import inspect

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
       the child class must have the expire prop
       the child class must have the uid prop
       the child class must have the model prop
       default key is uid, default uid is id
    """

    def __init__(self):
        self.orm = None

    def __getattr__(self, name):
        if not getattr(self, 'orm'):
            return None

        return getattr(self.orm, name)
 
    @classmethod
    def _create_from_orm(cls, md):
        """md is sqlalchemy obj"""
        obj = cls()
        obj.orm = md
        return obj

    @property
    def uid(self):
        if hasattr(self, 'orm')
            return self.orm.id
        else:
            return None

    def get_obj_dic(self):
        dic = {}
        cs = type(self)
        for n, v in inspect.getmembers(cs):
            if isinstance(v, Column) and hasattr(self, n):
                dic[v] = getattr(self, n)
        return dic

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
        return db().query(cls).count()

    @classmethod
    def get(cls, uid):
        ck = cls.get_cache_key(uid)
        data = cls.get_cache(ck)

        md = None
        if data:
            md = pickle.loads(data)
        else:
            md = db().query(cls).get(uid)
            cls.add_cache(ck, pickle.dumps(md))
        return cls._create_from_orm(md)

    @classmethod
    def add(cls, obj):
        cls.add_by_uid(v.uid, v)

    @classmethod
    def add_by_uid(cls, uid, obj):
        db().add(obj.orm)
        db().flush()

        ck = cls.get_cache_key(uid)
        cls.add_cache(ck, pickle.dumps(v.orm))

    @classmethod
    def delete(cls, obj):
        cls.del_by_uid_obj(obj.uid, obj)

    @classmethod
    def del_by_uid(cls, uid):
        md = db().query(cls).get(uid)

        db().delete(md)
        db().flush()

        ck = cls.get_cache_key(uid)
        cls.del_cache(ck)

    @classmethod
    def del_by_uid_obj(cls, uid, obj):
        db().delete(obj.orm)
        db().flush()

        ck = cls.get_cache_key(uid)
        cls.del_cache(ck)

    @classmethod
    def update_by_uid_value(cls, uid, obj):
        dic = obj.get_prop_dic()
        db().query(cls).get(uid).update(dic)
        db().flush()

        ck = cls.get_cache_key(uid)
        cls.set_cache(ck, pickle.dumps(obj.orm))

    def update(self):
        self.update_by_key_value(self.uid, self)
