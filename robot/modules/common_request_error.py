# -*- coding:utf-8 -*-

from common import *
import account as mod_account

def illeagal_usrid(reqerr):
    print 'error found: illeagal usrid'
    log_request_error(reqerr)

def account_not_exist(reqerr):
    print 'error found: account not exist'
    log_request_error(reqerr)
