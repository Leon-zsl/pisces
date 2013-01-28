#!/usr/bin/env python
# -*- coding:utf-8 -*-

from ConfigParser import ConfigParser
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

import model

class DBMgr(object):
    def __init__(self):
        parser = ConfigParser()
        parser.read("config/db.conf")
        conf_name = "db_game"
        url = "mysql+mysqldb://"                       \
          + parser.get(conf_name, "username")          \
          + ":" + parser.get(conf_name, "password")    \
          + "@" + parser.get(conf_name, "host")        \
          + ":" + parser.get(conf_name, "port")        \
          + "/" + parser.get(conf_name, "database")

        self.engine = create_engine(url, echo = True)
        self.session_cls = sessionmaker(bind = self.engine)
        model.build_tables(self.engine)
    
    def __del__(self):
        self.close()

    def close(self):
        self.close_session()

    def open_session(self):
        self.session = self.session_cls()

    def close_session(self):
        if getattr(self, "session"):
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
