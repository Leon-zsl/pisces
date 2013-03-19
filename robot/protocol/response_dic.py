# -*_ coding:utf-8 -*-

from opcode_response import *

from modules import common
from modules import account
from modules import profile
from modules import character

dic = {
    REQUEST_ERROR : common.handle_request_error,

    REGISTER_RESPONSE : account.handle_register_response,
    LOGIN_RESPONSE : account.handle_login_response,

    GET_PROFILE_INFO_RESPONSE : profile.handle_getinfo_response,

    GET_CHARACTER_INFO_RESPONSE : character.handle_getinfo_response,
}
