<%def name="read_func(reader, type)">
%if type.startswith("bool"):
    ${reader}:read_bool()
%elif type.startswith("byte"):
    $reader}:read_char()
%elif type.startswith("short"):
    ${reader}:read_short()
%elif type.startswith("int"):
    ${reader}:read_int()
%elif type.startswith("long"):
    ${reader}:read_long()
%elif type.startswith("float"):
    ${reader}:read_float()
%elif type.startswith("double"):
    ${reader}:read_double()
%elif type.startswith("string"):
    ${reader}:read_string()
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

--require "FReadStream"

--local io = io
--local FReadStream = FReadStream
--local print = print
--local type = type

--module "${class_name}"

dic = {}
list = {}

local function log(msg)
   io.write(msg .. "\n")
end

local function create_reader(file_name)
   return FReadStream(file_name)
end

local function destroy_reader(reader)
   if reader ~= nil then
	  reader = nil
   end
   --reader.close()
end

local function add_item(reader, idx)
   local new_obj_${class_name} = {}
% for i in range(last_item_index):
% if client_list[i].count('c') or client_list[i].count('s'):
% if arr_list[i]:
    local arr_item_len_${class_name} = reader:read_short()
    ${name_list[i]} = {}
	if arr_item_len_${class_name} > 0 then
	   for j = 1, arr_item_len_${class_name} do
		  ${name_list[i]}[j] = (${read_func("reader", type_list[i])})
		  if type(${name_list[i]}[j]) == "number" or type(${name_list[i]}[j] == "string") then
		  --print("${name_list[i]}[i]: " .. j .. "" .. ${name_list[i]}[j])
		  end
	   end
	end
% else:
    ${name_list[i]} = ${read_func("reader", type_list[i])}
	if type(${name_list[i]}) == "number" or type(${name_list[i]}) == "string" then
	   --print("${name_list[i]}: " .. ${name_list[i]})
	end
% endif
	new_obj_${class_name}["${name_list[i]}"] = ${name_list[i]}
% endif
% endfor
    
    if ${name_list[0]} == 0 then
	   log("invalid key: ${class_name}" .. "\t" .. ${name_list[0]})
	   return -1
	end

	if dic[${name_list[0]}] ~= nil then
	   log("duplicate key: ${class_name}" .. "\t" .. ${name_list[0]})
	   return -1
	end

    dic[${name_list[0]}] = new_obj_${class_name}
    list[idx] = new_obj_${class_name}

	return 0
end

function ${class_name}_build()
   local file_name = "${bin_file_name}"
   local reader = create_reader(file_name)
   --print(file_name)

   local filelen = reader:read_int()
   local flag = reader:read_string()
   if flag ~= "${class_name}" then
	  log("file flag illeagal: " .. file_name)
	  destroy_reader()
	  return -1
   end

   local col_cnt = reader:read_short()
   if col_cnt ~= ${item_count} then
	  log("file column count illeagal: " .. file_name)
	  destroy_reader()
	  return -1
   end

   local row_cnt = reader:read_int()
   for idx = 1, row_cnt do
	  local v = add_item(reader, idx)
	  if v ~= 0 then
		 destroy_reader()
		 return v
	  end
   end

   destroy_reader()
   return 0
end
