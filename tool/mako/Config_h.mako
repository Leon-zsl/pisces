<%def name="type_of_arr(arr)">
<%
tp = arr.strip('[]')
%>
${tp}
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
%elif type.startswith("string"):
    std::string
%elif type.startswith("double"):
    double
%else:
    void
%endif
</%def>

#include <map>
#include <vector>
#include <string>

class StreamReader;
class ${class_name}
{
public:
    static std::map<int, ${class_name}*> dic;
    static std::vector<${class_name}*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    ${class_name}(\
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
);
    ~${class_name}();

% for i in range(len(client_list)):
% if client_list[i].count('c') or client_list[i].count('s'):
% if arr_list[i]:
    ${type_of_arr(std_type(type_list[i]))}* \
    ${name_list[i]};
% else:
    ${std_type(type_list[i])} \
    ${name_list[i]};
% endif
% endif
% endfor
};
