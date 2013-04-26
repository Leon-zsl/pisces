# -*- coding:utf-8 -*-

from ConfigParser import ConfigParser
import pylibmc

class CacheMgr(object):
    def __init__(self, conf):
        parser = ConfigParser()
        parser.read(conf)
        label = 'cache_memcached'
        ip = str(parser.get(label, 'cache_ip'))
        port = str(parser.get(label, 'cache_port'))
        self.mc = pylibmc.Client([ip + ':' + port],
                                 binary = True,
                                 behaviors = {'tcp_nodelay' : True,
                                              'ketama' : True,
                                              'cas' : True})
    def __del__(self):
        self.close()
        
    def close(self):
        self.mc.disconnect_all()
