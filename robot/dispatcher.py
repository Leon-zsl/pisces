# -*- coding:utf-8 -*-

import time
import Queue
import thread
import httplib, urllib
import base64

from config import *
from protocol import response_dic
from msg import Msg

from app import App

def logger():
    return App.instance.logger()

def join_request_msg(msg_list):
    if not msg_list:
        return ''
    send_msg = ''
    for msg in msg_list:
        send_msg += '' + msg.opcode + ':' \
          + base64.encodestring(msg.data) + '|'
    return send_msg.strip('|')

def slice_response_msg(rcv_msg):
    if not rcv_msg:
        return []
    data_list = rcv_msg.split('|')

    msg_list = []
    for data in data_list:
        kvp = data.split(':')
        if len(kvp) != 2:
            logger().critical('parse msg err: ' + data)
            continue
        if kvp[0] == 0:
            logger().critical('invalid op: ' + data)
            continue
        msg_list.append(Msg(int(kvp[0]), base64.decodestring(kvp[1])))

def http_request(req_data, token):
    con = httplib.HTTPConnection(SERVER_ADDR)
    params = urllib.urlencode({'msg' : req_data, 'token' : token})
    headers = {'Content-type' : 'application/x-www-form-urlencoded',
               'Accept' : 'text/plain'}
    con.request('POST', SERVER_ROUTER, params, headers)
    resp = con.getresponse()
    resp_data = resp.read()
    resp.close()
    con.close()
    return resp_data
    
def http_thread(owner, interval):
    while owner and owner.running:
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
        if (not msg) or (not msg.opcode):
            logger().critical('invalid msg or msg op')
            return
        func = response_dic.get(msg.opcode)
        if not func:
            logger().critical('unknown msg code: ' + msg.opcode)
            return
        func(msg)
