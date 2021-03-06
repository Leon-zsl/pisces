# -*- coding:utf-8 -*-

from ConfigParser import ConfigParser
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

from config import *

class DBMgr(object):
    def __init__(self, conf):
        parser = ConfigParser()
        parser.read(conf)
        conf_name = 'db_game'
        url = 'mysql+mysqldb://'                       \
          + parser.get(conf_name, 'username')          \
          + ':' + parser.get(conf_name, 'password')    \
          + '@' + parser.get(conf_name, 'host')        \
          + ':' + parser.get(conf_name, 'port')        \
          + '/' + parser.get(conf_name, 'database')    \
          + '?charset=utf8'

        self.db_name = conf_name
        self.engine = create_engine(url,
                                    encoding='utf8', 
                                    echo=SQLALCHEMY_ECHO)
        self.session_cls = sessionmaker(bind = self.engine)
        #model.Base.metadata.create_all(self.engine)
    
    def __del__(self):
        self.close()

    def close(self):
        self.close_session()

    def open_session(self):
        self.session = self.session_cls()

    def close_session(self):
        if getattr(self, 'session'):
            self.session.close()

    def query(self, clas):
        return self.session.query(clas)

    def add(self, obj):
        self.session.add(obj)

    def delete(self, obj):
        self.session.delete(obj)

    def flush(self):
        self.session.flush()

    def commit(self):
        self.session.commit()

    def rollback(self):
        self.session.rollback()

    def create_tables(self, orm):
        orm.metadata.create_all(self.engine)
