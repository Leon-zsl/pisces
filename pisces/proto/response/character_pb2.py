# Generated by the protocol buffer compiler.  DO NOT EDIT!

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)



DESCRIPTOR = descriptor.FileDescriptor(
  name='character.proto',
  package='proto.response.character',
  serialized_pb='\n\x0f\x63haracter.proto\x12\x18proto.response.character\"\x82\x01\n\x18GetCharacterInfoResponse\x12\x0e\n\x06status\x18\x01 \x01(\x05\x12\x0e\n\x06\x63onfid\x18\x02 \x01(\x05\x12\r\n\x05level\x18\x03 \x01(\x05\x12\n\n\x02hp\x18\x04 \x01(\x05\x12\n\n\x02mp\x18\x05 \x01(\x05\x12\x0e\n\x06\x61ttack\x18\x06 \x01(\x05\x12\x0f\n\x07\x64\x65\x66\x65nse\x18\x07 \x01(\x05')




_GETCHARACTERINFORESPONSE = descriptor.Descriptor(
  name='GetCharacterInfoResponse',
  full_name='proto.response.character.GetCharacterInfoResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='status', full_name='proto.response.character.GetCharacterInfoResponse.status', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='confid', full_name='proto.response.character.GetCharacterInfoResponse.confid', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='level', full_name='proto.response.character.GetCharacterInfoResponse.level', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='hp', full_name='proto.response.character.GetCharacterInfoResponse.hp', index=3,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='mp', full_name='proto.response.character.GetCharacterInfoResponse.mp', index=4,
      number=5, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='attack', full_name='proto.response.character.GetCharacterInfoResponse.attack', index=5,
      number=6, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='defense', full_name='proto.response.character.GetCharacterInfoResponse.defense', index=6,
      number=7, type=5, cpp_type=1, label=1,
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
  serialized_start=46,
  serialized_end=176,
)

DESCRIPTOR.message_types_by_name['GetCharacterInfoResponse'] = _GETCHARACTERINFORESPONSE

class GetCharacterInfoResponse(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _GETCHARACTERINFORESPONSE
  
  # @@protoc_insertion_point(class_scope:proto.response.character.GetCharacterInfoResponse)

# @@protoc_insertion_point(module_scope)