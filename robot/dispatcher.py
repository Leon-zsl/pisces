# -*- coding:utf-8 -*-

import traceback
import time
import Queue
import thread
import httplib, urllib
import base64
import json

from config import *
from protocol import protocol_dic
from msg import Msg
import app

from exception import PiscesException

def logger():
    return app.App.instance.logger

def handle_except(ex):
    msg = traceback.format_exc()
    raise PiscesException('raw except: %s\nstack:\n%s', str(ex), msg)

def join_request_msg(msg_list):
    if not msg_list:
        return ''
    val_list = []
    for msg in msg_list:
        val_list.append({msg.op :
                         base64.encodestring(json.dumps(msg.msg))})
    return json.dumps(val_list)

def slice_response_msg(rcv_msg):
    if not rcv_msg:
        return []
    data_list = json.loads(rcv_msg)

    msg_list = []
    for data in data_list:
        if not data:
            continue
        msg_list.append(Msg(data.keys()[0],
                            json.loads(base64.decodestring(data.values()[0]))))
    return msg_list

def http_request(req_data, token):
    con = httplib.HTTPConnection(SERVER_ADDR)
    params = urllib.urlencode({'msg' : req_data, 'token' : token})
    headers = {'Content-type' : 'application/x-www-form-urlencoded',
               'Accept' : 'text/plain'}
    con.request('POST', SERVER_ROUTER, params, headers)
    resp = con.getresponse()
    if resp.status > 400:
        logger().error('http error status: %s\nerror reason:%s',
                       resp.status, resp.reason)
        return ''
    resp_data = resp.read()
    resp.close()
    con.close()
    return resp_data
    
def http_thread(owner, interval):
    while owner and owner.running:
        try:
            start = time.time()
            send_list = []

            while not owner.send_queue.empty():
                msg = owner.send_queue.get()
                send_list.append(msg)
                
            if send_list:
                send_data = join_request_msg(send_list)
                rcv_data = http_request(send_data, owner.token)
                rcv_list = slice_response_msg(rcv_data)
                for msg in rcv_list:
                    owner.recv_queue.put(msg)
                    
            end = time.time()
            slp = interval - (end - start)
            time.sleep(slp if slp > 0 else 0.001)
        except httplib.HTTPException, ex:
            logger().critical('http except caught! %s\nstack:\n%s',
                              str(ex), traceback.format_exc())
            raw_input('enter to continue')
        except Exception, ex:
            handle_except(ex)

class Dispatcher(object):
    def __init__(self):
        self.running = True
        self.token = ''
        self.send_queue = Queue.Queue()
        self.recv_queue = Queue.Queue()
        thread.start_new_thread(http_thread, (self, 0.06))

    def __del__(self):
        self.shutdown()

    def shutdown(self):
        self.running = False

    def dispatch(self):
        while not self.recv_queue.empty():
            msg = self.recv_queue.get()
            self.handle_msg(msg)

    def set_token(self, tk):
        self.token = tk

    def send_msg(self, msg):
        if not msg:
            return
        self.send_queue.put(msg)

    def handle_msg(self, msg):
        if (not msg) or (not msg.op):
            logger().critical('invalid msg or msg op')
            return
        func = protocol_dic.response_dic.get(msg.op)
        if not func:
            logger().critical('unknown msg code: ' + msg.op)
            return
        func(msg)
