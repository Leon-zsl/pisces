# -*- coding:utf-8 -*-

from controllers import *

from opcode_request import *

dic = {
    REGISTER : account.register,
    LOGIN    : account.login,

    GET_PROFILE_INFO : profile.get_info,
    CREATE_PROFILE : profile.create_profile,
    
    GET_CHARACTER_INFO : character.get_info,
}

token_omit = [REGISTER, LOGIN]

request_info_require = [LOGIN]
