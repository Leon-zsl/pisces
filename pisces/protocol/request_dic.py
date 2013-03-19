# -*- coding:utf-8 -*-

from controllers import account
from controllers import profile
from controllers import character

from opcode_request import *

dic = {
    REGISTER : account.register,
    LOGIN    : account.login,

    GET_PROFILE_INFO : profile.get_info,

    GET_CHARACTER_INFO : character.get_info,
}
