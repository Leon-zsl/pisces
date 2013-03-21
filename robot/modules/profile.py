# -*- coding:utf-8 -*-

from common import *
import proto.profile_pb2 as pro_profile
import character as mod_character

def request_getinfo():
    gi = pro_profile.GetProfileInfo()
    data = gi.SerializeToString()
    dispatcher().send_msg(Msg(GET_PROFILE_INFO, data))

def getinfo_response(msg):
    rsp = pro_profile.GetProfileInfoResponse()
    rsp.ParseFromString(msg.data)
    print 'profile getinfo succ'
    mod_character.request_getinfo()

def getinfo_error_invalid_usrid(err):
    print 'invalid usr info'
    request_create_profile()

def request_create_profile():
    req = pro_profile.CreateProfile()
    req.nickname = 'fox'
    req.character_id = 1
    data = req.SerializeToString()
    dispatcher().send_msg(Msg(CREATE_PROFILE, data))

def create_profile_response(msg):
    req = pro_profile.CreateProfileResponse()
    req.ParseFromString(msg.data)
    print 'create profile succ'
    mod_character.request_getinfo()
