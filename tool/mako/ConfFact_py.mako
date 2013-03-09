# -*- coding:utf-8 -*-

% for cls in class_list:
import ${cls}
% endfor

def build():
% for cls in class_list:
    ${cls}.build()
% endfor
