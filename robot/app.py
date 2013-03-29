# -*- coding:utf-8 -*-

import time
import os
import sys
import traceback
import logging
import logging.config

from config import *
from data import ConfFact

from dispatcher import Dispatcher
from game import Game

from exception import PiscesException

def _excepthook(exctype, value, tb):
    print "Exception Caught!"
    print "type: " + str(exctype)
    print "value: " + str(value)
    traceback.print_tb(tb)
    raw_input("press Enter to continue...")
    exit()

class App(object):
    instance = None
    def __init__(self):
        try:
            sys.excepthook = _excepthook
            App.instance = self
            logging.config.fileConfig('config/log.conf')
            self.logger = logging.getLogger('root')
            self.dispatcher = Dispatcher()
            self.game = Game()
            self.__start()
        except PiscesException, ex:
            self.__handle_pisces_except(ex)

    def __del__(self):
        self.__close()
        App.instance = None
        
    def run(self):
        try:
            while self.running:
                start = time.time()
                self.dispatcher.dispatch()
                self.game.update()
                end = time.time()
                slp = 0.06 - (end - start)
                time.sleep(slp if slp > 0 else 0.001)
            self.__close()
        except PiscesException, ex:
            self.__handle_pisces_except(ex)

    def quit(self):
        self.running = False
        
    def __handle_pisces_except(self, ex):
        if hasattr(self, 'logger'):
            if type(ex) is PiscesException:
                self.logger.critical("pisces exception caught: %s",
                                     ex.msg)
            else:
                msg = traceback.format_exc()
                self.logger.critical("exception caught: %s\n%s",
                                     str(ex), msg)
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
