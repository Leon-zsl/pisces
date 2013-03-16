#!/usr/bin/env python
# -*- coding:utf-8 -*-

from handlers import account

from opcode_request import *

dic = {
    LOGIN    : account.login,
    LOGOUT   : account.logout,
    REGISTER : account.register,
}
