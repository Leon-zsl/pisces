# Generated by the protocol buffer compiler.  DO NOT EDIT!

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)



DESCRIPTOR = descriptor.FileDescriptor(
  name='request.proto',
  package='',
  serialized_pb='\n\rrequest.proto\"\"\n\x05Login\x12\x0c\n\x04name\x18\x02 \x01(\t\x12\x0b\n\x03pwd\x18\x03 \x01(\t\"\x18\n\x06Logout\x12\x0e\n\x06userid\x18\x01 \x01(\x05\"\x13\n\x05SetHP\x12\n\n\x02hp\x18\x01 \x01(\x02\"\x13\n\x05SetMP\x12\n\n\x02mp\x18\x01 \x01(\x02')




_LOGIN = descriptor.Descriptor(
  name='Login',
  full_name='Login',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='name', full_name='Login.name', index=0,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='pwd', full_name='Login.pwd', index=1,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=17,
  serialized_end=51,
)


_LOGOUT = descriptor.Descriptor(
  name='Logout',
  full_name='Logout',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='userid', full_name='Logout.userid', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=53,
  serialized_end=77,
)


_SETHP = descriptor.Descriptor(
  name='SetHP',
  full_name='SetHP',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='hp', full_name='SetHP.hp', index=0,
      number=1, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=79,
  serialized_end=98,
)


_SETMP = descriptor.Descriptor(
  name='SetMP',
  full_name='SetMP',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='mp', full_name='SetMP.mp', index=0,
      number=1, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=100,
  serialized_end=119,
)

DESCRIPTOR.message_types_by_name['Login'] = _LOGIN
DESCRIPTOR.message_types_by_name['Logout'] = _LOGOUT
DESCRIPTOR.message_types_by_name['SetHP'] = _SETHP
DESCRIPTOR.message_types_by_name['SetMP'] = _SETMP

class Login(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _LOGIN
  
  # @@protoc_insertion_point(class_scope:Login)

class Logout(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _LOGOUT
  
  # @@protoc_insertion_point(class_scope:Logout)

class SetHP(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _SETHP
  
  # @@protoc_insertion_point(class_scope:SetHP)

class SetMP(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _SETMP
  
  # @@protoc_insertion_point(class_scope:SetMP)

# @@protoc_insertion_point(module_scope)
