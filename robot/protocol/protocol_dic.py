# -*_ coding:utf-8 -*-

import sys

from error_code import *

from modules import *

response_dic = {
    'request_error' : common.request_error_response,

    'register_response' : account.register_response,
    'login_response' : account.login_response,

    'get_profile_info_response' : profile.getinfo_response,
    'create_profile_response' : profile.create_profile_response,

    'get_character_info_response' : character.getinfo_response,
}

request_error_dic = {
    ILLEAGAL_USRID : {
        'get_profile_info' : profile.getinfo_error_invalid_usrid,
        "default" : common_request_error.illeagal_usrid,
    },

    ACCOUNT_EXIST : {
        'register' : account.register_error_account_exist,
    },

    ACCOUNT_NOT_EXIST : {
        'login' : account.login_error_account_not_exist,
        'default' : common_request_error.account_not_exist,
    },

    'default' : common.default_error_response,
}
