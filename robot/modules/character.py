# -*- coding:utf-8 -*-

from common import *
import proto.character_pb2 as pro_character

def request_getinfo():
    app.App.instance.game.end_modules()

def getinfo_response(msg):
    pass
