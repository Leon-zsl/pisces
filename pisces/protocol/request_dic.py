# -*- coding:utf-8 -*-

from controllers import *

from opcode_request import *

dic = {
    REGISTER : account.register,
    LOGIN    : account.login,

    GET_PROFILE_INFO : profile.get_info,

    GET_CHARACTER_INFO : character.get_info,
}
