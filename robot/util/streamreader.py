# -*- coding:utf-8 -*-

import struct

def logger():
    return app.App.instance.logger.root

byte_order = '<'

class StreamReader(object):
    def __init__(self, file_path):
        self.f = open(file_path, "rb")

    def close(self):
        self.f.close()

    def read_int(self):
        return struct.unpack(byte_order + 'i', self.f.read(4))[0]

    def read_short(self):
        return struct.unpack(byte_order + 'h', self.f.read(2))[0]

    def read_long(self):
        return struct.unpack(byte_order + 'q', self.f.read(8))[0]

    def read_float(self):
        return struct.unpack(byte_order + 'f', self.f.read(4))[0]

    def read_double(self):
        return struct.unpack(byte_order + 'd', self.f.read(8))[0]

    def read_bool(self):
        val = struct.unpack(byte_order + 'b', self.f.read(1))[0]
        return val != 0

    def read_byte(self):
        return struct.unpack(byte_order + 'b', self.f.read(1))[0]

    def read_string(self):
        len = self.read_short()
        if not len:
            return ""
        return struct.unpack(byte_order + str(len) + 's', 
                             self.f.read(int(len)))[0]
    
