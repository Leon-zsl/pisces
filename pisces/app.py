#!/usr/bin/env python
# -*- coding:utf-8 -*-

#buildin modules
import os
import sys
import traceback

#3rd party modules
import tornado
import tornado.httpserver
import tornado.ioloop
import tornado.web
import tornado.gen
import tornado.options
from tornado.options import options, define

#self modules
from config import *

from log import LoggerMgr
from router import Router
from db import DBMgr

from data import ConfFact

define("listen_port", default=default_listen_port)
define("db_host", default=default_db_host)

class App(object):
    instance = None
        
    def __init__(self):
        try:
            self.logger = LoggerMgr()
            self.db = DBMgr()
            self.router = Router()
            App.instance = self
        except Exception, e:
            self.handle_except(e)

    def __del__(self):
        self.close()

    def close(self):
        if getattr(self, "router"):
            self.router.close()
        if getattr(self, "db"):
            self.db.close()
        if getattr(self, "logger"):
            self.logger.close()            

    def run(self):
        try:
            self.load_data()
            self.start_tornado()
        except Exception, e:
            self.handle_except(e)
            
    def handle_except(self, ex):
        msg = traceback.format_exc()
        if hasattr(self, 'logger'):
            self.logger.root.critical("exception caught: " + msg)
        else:
            raise Exception, ex
        #self.close()
        if hasattr(self.db, "session"):
            self.db.rollback()
        self.db.close_session()

    def load_data(self):
        self.logger.root.info('load data begin...')
        ConfFact.build()
        self.logger.root.info('load data end')
        
    def start_tornado(self):
        #tornado.options.parse_config_file("config/sys.conf")
        tornado.options.parse_command_line()

        self.logger.root.info("init tornado conf "
                             + "port: " + str(options.listen_port))
        
        web_app = tornado.web.Application([
            (r"/pisces", MainHandler),
            ])
        http_server = tornado.httpserver.HTTPServer(web_app)
        http_server.listen(options.listen_port)
        tornado.ioloop.IOLoop.instance().start()
    
class MainHandler(tornado.web.RequestHandler):
    # @tornado.web.asynchronous
    # @tornado.gen.engine
    def get(self):
        info = "main handler get request: "
        info += self.request.remote_ip
        App.instance.logger.root.info(info)
        
        #response = App.instance.router.dispatch(self)
        self.write("pisces work now: get request")
        
    # @tornado.web.asynchronous
    # @tornado.gen.engine
    def post(self):
        info = "main handler post request: "
        info += self.request.remote_ip
        App.instance.logger.root.info(info)

        response = App.instance.router.dispatch(self)
        self.write(response)
