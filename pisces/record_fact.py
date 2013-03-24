# -*- coding:utf-8 -*-

from sqlalchemy import *

import record
from records import *

import app

def create_all():
    app.App.instance.db_record.create_tables(record.Base)
