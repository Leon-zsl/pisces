#!/usr/bin/env python
# -*- coding:utf-8 -*-

import handlers
import handlers.account
import handlers.character
from opcode_request import *

dic = {
    LOGIN : handlers.account.login,
    LOGOUT : handlers.account.logout,

    SETHP : handlers.character.set_hp,
    SETMP : handlers.character.set_mp,
}
