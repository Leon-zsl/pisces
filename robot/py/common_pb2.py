# Generated by the protocol buffer compiler.  DO NOT EDIT!

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)



DESCRIPTOR = descriptor.FileDescriptor(
  name='common.proto',
  package='proto',
  serialized_pb='\n\x0c\x63ommon.proto\x12\x05proto\"<\n\x0cRequestError\x12\r\n\x05\x65rrop\x18\x01 \x01(\x05\x12\r\n\x05\x65rror\x18\x02 \x01(\x05\x12\x0e\n\x06\x65rrmsg\x18\x03 \x01(\t')




_REQUESTERROR = descriptor.Descriptor(
  name='RequestError',
  full_name='proto.RequestError',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='errop', full_name='proto.RequestError.errop', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='error', full_name='proto.RequestError.error', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='errmsg', full_name='proto.RequestError.errmsg', index=2,
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
  serialized_start=23,
  serialized_end=83,
)

DESCRIPTOR.message_types_by_name['RequestError'] = _REQUESTERROR

class RequestError(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _REQUESTERROR
  
  # @@protoc_insertion_point(class_scope:proto.RequestError)

# @@protoc_insertion_point(module_scope)
