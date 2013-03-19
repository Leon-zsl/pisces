# -*_ coding:utf-8 -*-

from opcode_response import *

from modules import common
from modules import account
from modules import profile
from modules import character

dic = {
    REQUEST_ERROR : common.request_error_response,

    REGISTER_RESPONSE : account.register_response,
    LOGIN_RESPONSE : account.login_response,

    GET_PROFILE_INFO_RESPONSE : profile.getinfo_response,

    GET_CHARACTER_INFO_RESPONSE : character.getinfo_response,
}
