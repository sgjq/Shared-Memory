# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: mem_config.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='mem_config.proto',
  package='MyMessage',
  syntax='proto2',
  serialized_options=None,
  serialized_pb=b'\n\x10mem_config.proto\x12\tMyMessage\"~\n\x0cMemoryConfig\x12\x19\n\tMemoryKey\x18\x01 \x01(\x05:\x06\x31\x32\x33\x34\x35\x36\x12\x1c\n\nMemorySize\x18\x02 \x01(\x05:\x08\x31\x32\x35\x38\x32\x39\x31\x32\x12\x1a\n\x08ResShift\x18\x03 \x01(\x05:\x08\x31\x30\x34\x38\x35\x37\x36\x30\x12\x19\n\x0bSemaporeKey\x18\x04 \x01(\x05:\x04\x31\x32\x33\x34'
)




_MEMORYCONFIG = _descriptor.Descriptor(
  name='MemoryConfig',
  full_name='MyMessage.MemoryConfig',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='MemoryKey', full_name='MyMessage.MemoryConfig.MemoryKey', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=123456,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='MemorySize', full_name='MyMessage.MemoryConfig.MemorySize', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=12582912,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ResShift', full_name='MyMessage.MemoryConfig.ResShift', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=10485760,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='SemaporeKey', full_name='MyMessage.MemoryConfig.SemaporeKey', index=3,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=1234,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=31,
  serialized_end=157,
)

DESCRIPTOR.message_types_by_name['MemoryConfig'] = _MEMORYCONFIG
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

MemoryConfig = _reflection.GeneratedProtocolMessageType('MemoryConfig', (_message.Message,), {
  'DESCRIPTOR' : _MEMORYCONFIG,
  '__module__' : 'mem_config_pb2'
  # @@protoc_insertion_point(class_scope:MyMessage.MemoryConfig)
  })
_sym_db.RegisterMessage(MemoryConfig)


# @@protoc_insertion_point(module_scope)
