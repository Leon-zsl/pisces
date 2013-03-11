<%def name="read_func(reader, type)">
%if type.startswith("bool"):
    ${reader}->read_bool();
%elif type.startswith("byte"):
    $reader}->read_byte();
%elif type.startswith("short"):
    ${reader}->read_short();
%elif type.startswith("int"):
    ${reader}->read_int();
%elif type.startswith("long"):
    ${reader}->read_long();
%elif type.startswith("float"):
    ${reader}->read_float();
%elif type.startswith("double"):
    ${reader}->read_double();
%elif type.startswith("string"):
    ${reader}->read_string();
%else:
    "unknown_read_type()"
%endif
</%def>

<%def name="std_type(type)">
%if type.startswith("bool"):
    bool
%elif type.startswith("byte"):
    unsigned char
%elif type.startswith("short"):
    short
%elif type.startswith("int"):
    int
%elif type.startswith("long"):
    long long
%elif type.startswith("float"):
    float
%elif type.startswith("double"):
    double
%elif type.startswith("string"):
    std::string
%else:
    void
%endif
</%def>

<%def name="type_of_arr(arr)">
<%
tp = arr.strip('[]')
%>
${tp}
</%def>

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

#include "StreamReader.h"
#include "${class_name}.h"

using namespace std;

std::map<int, ${class_name}*> ${class_name}::dic;
std::vector<${class_name}*> ${class_name}::list;

${class_name}::${class_name}(\
% for i in range(len(client_list) - 1):
% if client_list[i].count('c') or client_list[i].count('s'):
% if arr_list[i]:
${type_of_arr(std_type(type_list[i]))}* \
${name_list[i]}_,\
% else:
${std_type(type_list[i])} \
${name_list[i]}_, \
% endif
% endif
% endfor
% if arr_list[len(client_list) - 1]:
${type_of_arr(std_type(type_list[len(client_list) - 1]))}* \
${name_list[len(client_list) - 1]}_\
% else:
${std_type(type_list[len(client_list) - 1])} \
${name_list[len(client_list) - 1]}_\
% endif
)
{
% for i in range(len(client_list)):
% if client_list[i].count('c') or client_list[i].count('s'):
    ${name_list[i]} = ${name_list[i]}_;
% endif
% endfor
}

${class_name}::~${class_name}()
{
% for i in range(len(client_list)):
% if client_list[i].count('c') or client_list[i].count('s'):
% if arr_list[i]:
    delete[] ${name_list[i]};
% endif
% endif
% endfor
}
    
void ${class_name}::build()
{
    //std::string path = "./data/";
    //path += "${bin_file_name}";
    std::string path = "${bin_file_name}";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "${class_name}")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != ${item_count})
    {
        printf("col cnt invalid %d : %d", col_cnt, ${item_count});
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void ${class_name}::add_item(StreamReader* rs)
{
% if has_array_item:
    int arr_item_len_${class_name};
% endif

% for i in range(len(client_list)):
% if client_list[i].count('c') or client_list[i].count('s'):
% if arr_list[i]:
    arr_item_len_${class_name} = rs->read_short();
    ${type_of_arr(std_type(type_list[i]))}* \
    ${name_list[i]}_ = \
    new ${type_of_arr(std_type(type_list[i]))} \
    [arr_item_len_${class_name}];

    for(int i = 0; i < arr_item_len_${class_name}; ++i)
        ${name_list[i]}_[i] = \
        ${read_func("rs", type_list[i])}
% else:
    ${std_type(type_list[i])} \
    ${name_list[i]}_ = \
    ${read_func("rs", type_list[i])}
% endif
% endif
% endfor
        
    if(${name_list[0]}_ == 0)
    {
        printf("invalid key: %d", ${name_list[0]}_);
        return;
    }
    if(dic.find(${name_list[0]}_) != dic.end())
    {
        printf("duplicate key: %d", ${name_list[0]}_);
        return;
    }

    ${class_name}* new_obj_${class_name} = new ${class_name}(\
% for i in range(len(client_list) - 1):
% if client_list[i].count('c') or client_list[i].count('s'):
${name_list[i]}_, \
% endif
% endfor
${name_list[len(client_list) - 1]}_\
);

    dic[${name_list[0]}_] = new_obj_${class_name};
    list.push_back(new_obj_${class_name});
}

void ${class_name}::destroy()
{
    for(std::vector<${class_name}*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
