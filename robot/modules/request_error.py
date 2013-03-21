# -*- coding:utf-8 -*-

from common import *
import account as mod_account

def account_exist(reqerr):
    if reqerr.errop == REGISTER:
        mod_account.request_login()
    else:
        log_request_error(reqerr)
