# Generated by the protocol buffer compiler.  DO NOT EDIT!

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)



DESCRIPTOR = descriptor.FileDescriptor(
  name='profile.proto',
  package='proto.response.profile',
  serialized_pb='\n\rprofile.proto\x12\x16proto.response.profile\"^\n\x16GetProfileInfoResponse\x12\x0e\n\x06status\x18\x01 \x01(\x05\x12\x0c\n\x04name\x18\x02 \x01(\t\x12\x0b\n\x03\x65xp\x18\x03 \x01(\x05\x12\x0c\n\x04gold\x18\x04 \x01(\x05\x12\x0b\n\x03gem\x18\x05 \x01(\x05')




_GETPROFILEINFORESPONSE = descriptor.Descriptor(
  name='GetProfileInfoResponse',
  full_name='proto.response.profile.GetProfileInfoResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='status', full_name='proto.response.profile.GetProfileInfoResponse.status', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='name', full_name='proto.response.profile.GetProfileInfoResponse.name', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='exp', full_name='proto.response.profile.GetProfileInfoResponse.exp', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='gold', full_name='proto.response.profile.GetProfileInfoResponse.gold', index=3,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='gem', full_name='proto.response.profile.GetProfileInfoResponse.gem', index=4,
      number=5, type=5, cpp_type=1, label=1,
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
  serialized_start=41,
  serialized_end=135,
)

DESCRIPTOR.message_types_by_name['GetProfileInfoResponse'] = _GETPROFILEINFORESPONSE

class GetProfileInfoResponse(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _GETPROFILEINFORESPONSE
  
  # @@protoc_insertion_point(class_scope:proto.response.profile.GetProfileInfoResponse)

# @@protoc_insertion_point(module_scope)
