local io = io
local tonumber = tonumber
local print = print
local string = string

module "FReadStream"

local _file = nil
local _rd = {}

local function read_short()
   return string.byte((_file:read(2)), 1, -1)
end

local function read_int()
   return string.byte(_file:read(4), 1, -1)
end

local function read_float()
   return string.byte(_file:read(4), 1, -1)
end

local function read_bool()
   return string.byte(_file:read(1), 1) ~= 0
end

local function read_char()
   return string.byte(_file:read(1), 1)
end

local function read_string()
   local len = read_short()
   if len == 0 then
	  return ""
   end
   return _file:read(len)
end

function init(file_name)
   _file = io.open(file_name, "rb")
   if _file == nil then
	  print('open file failed')
	  return nil
   end

   _rd["read_bool"] = read_bool
   _rd["read_char"] = read_char
   _rd["read_short"] = read_short
   _rd["read_int"] = read_int
   _rd["read_float"] = read_float
   _rd["read_string"] = read_string
   return _rd
end

function close()
   if _file ~= nil then
	  _file:close()
	  _file = nil
   end
end