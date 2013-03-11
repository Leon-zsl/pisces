#!/usr/bin/env python
# -*- coding:utf-8 -*-

import httplib, urllib
import base64
import google.protobuf as protobuf
from opcode_request import *
from opcode_response import *
from request_pb2 import *
from response_pb2 import *

def main():
    while True:
        conn = httplib.HTTPConnection('127.0.0.1:8080')
        #conn = httplib.HTTPConnection('127.0.0.1:8001')
        obj = Login()
        obj.name = 'leon'
        obj.pwd = 'leon'
        val = obj.SerializeToString()
        s = base64.encodestring(val)
        msg = "msg=" + str(LOGIN) + ":" + s
        print msg
        
        params = urllib.urlencode({'msg': str(LOGIN) + ":" + s,})
        headers = {"Content-type": "application/x-www-form-urlencoded",
                   "Accept": "text/plain"}
        conn.request("POST", "/pisces", params, headers)
        #conn.request("GET", "/pisces")
        
        resp = conn.getresponse()
        val = resp.read()
        print val
        
        rs = val.split('|')
        for val in rs:
            if not val.strip():
                continue
            kv = [kv.strip() for kv in val.split(':')]
            if not kv:
                continue
            print kv[0], " : ", base64.decodestring(kv[1])
            if int(kv[0]) == LOGINSUCCESS:
                succ = LoginSuccess()
                succ.ParseFromString(base64.decodestring(kv[1]))
                print succ.userid
            else:
                print 'unknown op: ' + kv[0]

        resp.close()                
        raw_input()
    
if __name__ == '__main__':
    main()
