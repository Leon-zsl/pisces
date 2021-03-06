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
from cache import CacheMgr

import model_fact
from data import ConfFact

define('listen_port', default=DEFAULT_LISTEN_PORT)
#define('db_host', default=DEFAULT_DB_HOST)

class App(object):
    instance = None
        
    def __init__(self):
        try:
            sys.excepthook = _excepthook
            self.logger = LoggerMgr('config/log.conf')
            self.db = DBMgr('config/db.conf')
            self.cache = CacheMgr('config/cache.conf')
            self.router = Router()
            App.instance = self
        except Exception, e:
            self.handle_except(e)

    def __del__(self):
        self.close()

    def close(self):
        if getattr(self, 'router'):
            self.router.close()
        if getattr(self, 'cache'):
            self.cache.close()
        if getattr(self, 'db'):
            self.db.close()
        if getattr(self, 'logger'):
            self.logger.close()

    def run(self):
        try:
            self.load_data()
            self.create_db()
            self.start_tornado()
        except Exception, e:
            self.handle_except(e)
            
    def handle_except(self, ex):
        # if hasattr(self, 'logger'):
        #     self.logger.root.exception('unknown exception:' + ex.msg)
        # else:
        msg = traceback.format_exc()
        raise Exception(msg)
        
        #self.close()
        self.db.rollback()
        self.db.close_session()
        
    def create_db(self):
        self.logger.root.info('create db begin...')
        model_fact.create_all()
        self.logger.root.info('create db end')

    def load_data(self):
        self.logger.root.info('load data begin...')
        ConfFact.build()
        self.logger.root.info('load data end')
        
    def start_tornado(self):
        #tornado.options.parse_config_file('config/sys.conf')
        tornado.options.parse_command_line()

        self.logger.root.info('init tornado conf '
                             + 'port: ' + str(options.listen_port))

        settings = {'log_function' : _tornado_logger}
        web_app = tornado.web.Application(
            [(r'/pisces', MainHandler)],
            **settings)
        http_server = tornado.httpserver.HTTPServer(web_app)
        http_server.listen(options.listen_port)
        tornado.ioloop.IOLoop.instance().start()
    
class MainHandler(tornado.web.RequestHandler):
    # @tornado.web.asynchronous
    # @tornado.gen.engine
    def get(self):
        info = 'main handler get request: '
        info += self.request.remote_ip
        App.instance.logger.root.info(info)
        
        #response = App.instance.router.dispatch(self)
        self.write('pisces work now: get request')
        
    def post(self):
        response = App.instance.router.dispatch(self)
        self.write(response)

    # @tornado.gen.engine
    # @tornado.web.asynchronous
    # def post(self):
        # info = 'main handler post request: '
        # info += self.request.remote_ip
        # App.instance.logger.root.info(info)
        # self.async_callback(self.on_handle_request)
        # self.on_handle_request()

    # def on_handle_request(self):
    #     response = App.instance.router.dispatch(self)
    #     self.write(response)
    #     self.finish()        

def _excepthook(exctype, value, tb):
    print 'Exception Caught!'
    print 'type: ' + str(exctype)
    print 'value: ' + str(value)
    traceback.print_tb(tb)
    raw_input('press Enter to continue...')
    exit()

def _tornado_logger(handler):
    logger = App.instance.logger.root
    status = handler.get_status()
    if DEV_LEV == 'product':
        if status >= 500:
            logger.error('tornado: %d', status)
        elif status >= 400:
            logger.warning('tornado: %d', status)
    elif DEV_LEV == 'develop':
        if status >= 500:
            logger.error('tornado: %d %s %.3fms', status,
                        handler._request_summary(),
                        1000 * handler.request.request_time())
        elif status >= 400:
            logger.warning('tornado: %d %s %.3fms', status,
                        handler._request_summary(),
                        1000 * handler.request.request_time())
        else:
            logger.info('tornado: %d %s %.3fms', status, 
                        handler._request_summary(),
                        1000 * handler.request.request_time())
    else:
        print 'unknown dev lev'
