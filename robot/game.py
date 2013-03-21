# -*- coding:utf-8 -*-

from config import *
import app
import modules.account as account

class Game(object):
    def __init__(self):
        pass

    def start(self):
        self.start_modules()
        
    def close(self):
        pass

    def update(self):
        pass

    def start_modules(self):
        account.request_register()

    def end_modules(self):
        if LOOP_MODULES:
            self.start_modules()
        else:
            app.App.instance.quit()
