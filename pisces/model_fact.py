# -*- coding:utf-8 -*-

from sqlalchemy import *

import model
from models import *

import app

def create_all():
    app.App.instance.db.create_tables(model.Base)
