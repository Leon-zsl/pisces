# -*_ coding:utf-8 -*-

import record
from sqlalchemy import *

class LoginRecord(record.Base):
    __tablename__ = 'login_record'

    usrid = Column(Integer,
                   primary_key=True,
                   nullable=False)
    
    name = Column(String(64),
                  nullable=False,
                  unique=True)
    
    login_time = Column(String(64),
                        nullable=False)
    
    last_login_time = Column(String(64),
                             nullable=False)
    
    login_count = Column(Integer,
                         nullable=False)

    continuous_login_days = Column(SmallInteger,
                                   nullable=False)

    total_login_days = Column(SmallInteger,
                              nullable=False)

    def __init__(self, usrid, name, login_time, last_login_time,
                 login_count, continuous_login_days, total_login_days):
        self.usrid = usrid
        self.name = name
        self.login_time = login_time
        self.last_login_time = last_login_time
        self.login_count = login_count
        self.continuous_login_days = continuous_login_days
        self.total_login_days = total_login_days
