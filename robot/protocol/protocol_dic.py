# -*_ coding:utf-8 -*-

import sys

from opcode_request import *
from opcode_response import *
from error_code import *

from modules import *

response_dic = {
    REQUEST_ERROR : common.request_error_response,

    REGISTER_RESPONSE : account.register_response,
    LOGIN_RESPONSE : account.login_response,

    GET_PROFILE_INFO_RESPONSE : profile.getinfo_response,
    CREATE_PROFILE_RESPONSE : profile.create_profile_response,

    GET_CHARACTER_INFO_RESPONSE : character.getinfo_response,
}

request_error_dic = {
    ILLEAGAL_USRID : {
        GET_PROFILE_INFO : profile.getinfo_error_invalid_usrid,
        "default" : common_request_error.illeagal_usrid,
    },

    ACCOUNT_EXIST : {
        REGISTER : account.register_error_account_exist,
    },

    ACCOUNT_NOT_EXIST : {
        LOGIN : account.login_error_account_not_exist,
        'default' : common_request_error.account_not_exist,
    },

    'default' : common.default_error_response,
}
