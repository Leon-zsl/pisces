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
    if not rsp.status:
        mod_character.request_getinfo()
    else:
        log_error(msg.opcode, rsp.status)
