<%def name="read_func(reader, type)">
%if type.startswith("bool"):
    ${reader}.read_bool()
%elif type.startswith("byte"):
    $reader}.read_byte()
%elif type.startswith("short"):
    ${reader}.read_short()
%elif type.startswith("int"):
    ${reader}.read_int()
%elif type.startswith("long"):
    ${reader}.read_long()
%elif type.startswith("float"):
    ${reader}.read_float()
%elif type.startswith("double"):
    ${reader}.read_double()
%elif type.startswith("string"):
    ${reader}.read_string()
%else:
    "unknown_read_type()"
%endif
</%def>

<%def name="type_of_arr(arr)">
<%
tp = arr.strip('[]')
%>
${tp}
</%def>

<%
last_item_index = 0
for i in range(len(client_list)):
    if client_list[i].count('c') or client_list[i].count('s'):
        last_item_index = i + 1
%>

<%
item_count = 0
for i in range(len(client_list)):
    if client_list[i].count('c') or client_list[i].count('s'):
        item_count += 1
%>

<%
has_array_item = False
for i in range(len(client_list)):
    if client_list[i].count('c') or client_list[i].count('s'):
        if arr_list[i]:
            has_array_item = True
            break
%>

import os.path

import app
#import log
from exception import PiscesException
from util.streamreader import StreamReader

def logger():
    return app.App.instance.logger.root

dic = {}
list = []

def build():
    try:
        data_path = "../exp/conf/data"
        path = os.path.join(data_path, "${bin_file_name}")
        reader = StreamReader(path)
        
        filelen = reader.read_int()
        flag = reader.read_string()
        if flag != "${class_name}":
            raise PiscesException("invalid flag")
        
        col_cnt = reader.read_short()
        if col_cnt != ${item_count}:
            raise PiscesException("col cnt invalid")
        
        row_cnt = reader.read_int()
        for i in range(0, row_cnt):
            add_item(reader)
    except PiscesException as pe:
        logger().critical("pisces excection: ${bin_file_name}" + pe.msg)
    finally:
        reader.close()

def add_item(reader):
% for i in range(last_item_index):
% if client_list[i].count('c') or client_list[i].count('s'):
% if arr_list[i]:
    arr_item_len_${class_name} = reader.read_short()
    ${name_list[i]} = []
    for idx in range(0, arr_item_len_${class_name}):
        ${name_list[i]}.append(${read_func("reader", type_list[i])})
% else:
    ${name_list[i]} = \${read_func("reader", type_list[i])}
% endif
% endif
% endfor
        
    new_obj_${class_name} = ${class_name}(\
% for i in range(last_item_index - 1):
% if client_list[i].count('c') or client_list[i].count('s'):
${name_list[i]}, \
% endif
% endfor
${name_list[last_item_index - 1]}\
)
    if not ${name_list[0]}:
        logger().warning("invalid key: " + ${name_list[0]})
        return
    if dic.has_key(${name_list[0]}):
        logger().warning("duplicate key: " + ${name_list[0]})
        return

    dic[${name_list[0]}] = new_obj_${class_name}
    list.append(new_obj_${class_name})

class ${class_name}:
    def __init__(self, \
% for i in range(last_item_index - 1):
% if client_list[i].count('c') or client_list[i].count('s'):
${name_list[i]}, \
% endif
% endfor
${name_list[last_item_index - 1]}\
):
% for i in range(last_item_index):
% if client_list[i].count('c') or client_list[i].count('s'):
        self.${name_list[i]} = ${name_list[i]}
% endif
% endfor
