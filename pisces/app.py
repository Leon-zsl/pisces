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
from log import LoggerMgr
from router import Router
from db import DBMgr

define("listen_port", default=8001)
define("db_host", default="127.0.0.1:3306")

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
            self.start_tornado()
        except Exception, e:
            self.handle_except(e)
            
    def handle_except(self, ex):
        msg = traceback.format_exc()
        self.logger.root.critical("exception caught: " + msg)
        #self.close()
        if hasattr(self.db, "session"):
            self.db.rollback()
        self.db.close_session()
        
    def start_tornado(self):
        self.logger.root.info("init tornado conf "
                             + "port: " + str(options.listen_port))
        tornado.options.parse_config_file("config/sys.conf")
        
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
