# -*- coding:utf-8 -*-

import time
import traceback
import logging
import logging.config

from config import *
from data import ConfFact

from dispatcher import Dispatcher
from game import Game

class App(object):
    instance = None
    def __init__(self):
        try:
            logging.config.fileConfig('config/log.conf')
            self.logger = logging.getLogger('root')
            self.dispatcher = Dispatcher()
            self.game = Game()
            App.instance = self
        except Exception, ex:
            self.handle_except(ex)

    def __del__(self):
        self.game.close()
        self.dispatcher.shutdown()
        logging.shutdown()

    def logger(self):
        return self.logger

    def dispatcher(self):
        return self.dispatcher

    def run(self):
        start = time.time()
        self.dispatcher.dispatch()
        self.game.update()
        end = time.time()
        slp = 0.06 - (end - start)
        time.sleep(slp if slp > 0 else 0.001)
        
    def load_data(self):
        ConfFact.build()

    def handle_except(self, ex):
        msg = traceback.format_exc()
        if hasattr(self, 'logger'):
            self.logger.critical("exception caught: " + msg)
        else:
            raise Exception, ex
