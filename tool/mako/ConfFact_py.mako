# -*- coding:utf-8 -*-

% for cls in class_list:
require ${cls}
% endfor

def build():
% for cls in class_list:
    ${cls}.build()
% endfor
