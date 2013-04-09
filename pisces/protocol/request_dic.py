# -*- coding:utf-8 -*-

from controllers import *

dic = {
    "register" : account.register,
    "login"    : account.login,

    "get_profile_info" : profile.get_info,
    "create_profile" : profile.create_profile,
    
    "get_character_info" : character.get_info,
}

token_omit = ["register", "login"]

request_info_require = ["login"]
