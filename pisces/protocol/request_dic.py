#!/usr/bin/env python
# -*- coding:utf-8 -*-

import handlers
import handlers.login
import handlers.character
from opcode_request import *

dic = {
    LOGIN : handlers.login.login,
    LOGOUT : handlers.login.logout,

    SETHP : handlers.character.set_hp,
    SETMP : handlers.character.set_mp,
}
