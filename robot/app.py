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
            App.instance = self
            logging.config.fileConfig('config/log.conf')
            self.logger = logging.getLogger('root')
            self.dispatcher = Dispatcher()
            self.game = Game()
            self.__start()
        except Exception, ex:
            self.__handle_except(ex)

    def __del__(self):
        self.__close()
        App.instance = None
        
    def run(self):
        while self.running:
            start = time.time()
            self.dispatcher.dispatch()
            self.game.update()
            end = time.time()
            slp = 0.06 - (end - start)
            time.sleep(slp if slp > 0 else 0.001)
        self.___close()

    def quit(self):
        self.running = False
        
    def __handle_except(self, ex):
        msg = traceback.format_exc()
        if hasattr(self, 'logger'):
            self.logger.critical("exception caught: " + msg)
        else:
            raise Exception, ex

    def __load_data(self):
        ConfFact.build()

    def __start(self):
        self.__load_data()
        self.game.start()
        self.running = True
        self.logger.info('robot start running...')

    def __close(self):
        self.logger.info('robot end running')
        self.game.close()
        self.dispatcher.shutdown()
        logging.shutdown()
