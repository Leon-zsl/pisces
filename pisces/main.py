#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys
import os
import os.path
import profile
import pstats

from app import App

def main():
    App().run()

if __name__ == '__main__':
    main()
