// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mem_config.proto

#include "mem_config.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace MyMessage {
class MemoryConfigDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<MemoryConfig> _instance;
} _MemoryConfig_default_instance_;
}  // namespace MyMessage
static void InitDefaultsscc_info_MemoryConfig_mem_5fconfig_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::MyMessage::_MemoryConfig_default_instance_;
    new (ptr) ::MyMessage::MemoryConfig();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::MyMessage::MemoryConfig::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_MemoryConfig_mem_5fconfig_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_MemoryConfig_mem_5fconfig_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_mem_5fconfig_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_mem_5fconfig_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_mem_5fconfig_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_mem_5fconfig_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::MyMessage::MemoryConfig, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::MyMessage::MemoryConfig, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::MyMessage::MemoryConfig, memorykey_),
  PROTOBUF_FIELD_OFFSET(::MyMessage::MemoryConfig, memorysize_),
  PROTOBUF_FIELD_OFFSET(::MyMessage::MemoryConfig, resshift_),
  PROTOBUF_FIELD_OFFSET(::MyMessage::MemoryConfig, semaporekey_),
  0,
  1,
  2,
  3,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::MyMessage::MemoryConfig)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::MyMessage::_MemoryConfig_default_instance_),
};

const char descriptor_table_protodef_mem_5fconfig_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020mem_config.proto\022\tMyMessage\"~\n\014MemoryC"
  "onfig\022\031\n\tMemoryKey\030\001 \001(\005:\006123456\022\034\n\nMemo"
  "rySize\030\002 \001(\005:\01012582912\022\032\n\010ResShift\030\003 \001(\005"
  ":\01010485760\022\031\n\013SemaporeKey\030\004 \001(\005:\0041234"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_mem_5fconfig_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_mem_5fconfig_2eproto_sccs[1] = {
  &scc_info_MemoryConfig_mem_5fconfig_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_mem_5fconfig_2eproto_once;
static bool descriptor_table_mem_5fconfig_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mem_5fconfig_2eproto = {
  &descriptor_table_mem_5fconfig_2eproto_initialized, descriptor_table_protodef_mem_5fconfig_2eproto, "mem_config.proto", 157,
  &descriptor_table_mem_5fconfig_2eproto_once, descriptor_table_mem_5fconfig_2eproto_sccs, descriptor_table_mem_5fconfig_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_mem_5fconfig_2eproto::offsets,
  file_level_metadata_mem_5fconfig_2eproto, 1, file_level_enum_descriptors_mem_5fconfig_2eproto, file_level_service_descriptors_mem_5fconfig_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_mem_5fconfig_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_mem_5fconfig_2eproto), true);
namespace MyMessage {

// ===================================================================

void MemoryConfig::InitAsDefaultInstance() {
}
class MemoryConfig::_Internal {
 public:
  using HasBits = decltype(std::declval<MemoryConfig>()._has_bits_);
  static void set_has_memorykey(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_memorysize(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_resshift(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_semaporekey(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
};

MemoryConfig::MemoryConfig()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MyMessage.MemoryConfig)
}
MemoryConfig::MemoryConfig(const MemoryConfig& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&memorykey_, &from.memorykey_,
    static_cast<size_t>(reinterpret_cast<char*>(&semaporekey_) -
    reinterpret_cast<char*>(&memorykey_)) + sizeof(semaporekey_));
  // @@protoc_insertion_point(copy_constructor:MyMessage.MemoryConfig)
}

void MemoryConfig::SharedCtor() {
  memorykey_ = 123456;
  memorysize_ = 12582912;
  resshift_ = 10485760;
  semaporekey_ = 1234;
}

MemoryConfig::~MemoryConfig() {
  // @@protoc_insertion_point(destructor:MyMessage.MemoryConfig)
  SharedDtor();
}

void MemoryConfig::SharedDtor() {
}

void MemoryConfig::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const MemoryConfig& MemoryConfig::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_MemoryConfig_mem_5fconfig_2eproto.base);
  return *internal_default_instance();
}


void MemoryConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:MyMessage.MemoryConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    memorykey_ = 123456;
    memorysize_ = 12582912;
    resshift_ = 10485760;
    semaporekey_ = 1234;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* MemoryConfig::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int32 MemoryKey = 1 [default = 123456];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_memorykey(&has_bits);
          memorykey_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 MemorySize = 2 [default = 12582912];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_memorysize(&has_bits);
          memorysize_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 ResShift = 3 [default = 10485760];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_resshift(&has_bits);
          resshift_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 SemaporeKey = 4 [default = 1234];
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_semaporekey(&has_bits);
          semaporekey_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* MemoryConfig::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:MyMessage.MemoryConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 MemoryKey = 1 [default = 123456];
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_memorykey(), target);
  }

  // optional int32 MemorySize = 2 [default = 12582912];
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_memorysize(), target);
  }

  // optional int32 ResShift = 3 [default = 10485760];
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_resshift(), target);
  }

  // optional int32 SemaporeKey = 4 [default = 1234];
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(4, this->_internal_semaporekey(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MyMessage.MemoryConfig)
  return target;
}

size_t MemoryConfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:MyMessage.MemoryConfig)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    // optional int32 MemoryKey = 1 [default = 123456];
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_memorykey());
    }

    // optional int32 MemorySize = 2 [default = 12582912];
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_memorysize());
    }

    // optional int32 ResShift = 3 [default = 10485760];
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_resshift());
    }

    // optional int32 SemaporeKey = 4 [default = 1234];
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_semaporekey());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MemoryConfig::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:MyMessage.MemoryConfig)
  GOOGLE_DCHECK_NE(&from, this);
  const MemoryConfig* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<MemoryConfig>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:MyMessage.MemoryConfig)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:MyMessage.MemoryConfig)
    MergeFrom(*source);
  }
}

void MemoryConfig::MergeFrom(const MemoryConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:MyMessage.MemoryConfig)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      memorykey_ = from.memorykey_;
    }
    if (cached_has_bits & 0x00000002u) {
      memorysize_ = from.memorysize_;
    }
    if (cached_has_bits & 0x00000004u) {
      resshift_ = from.resshift_;
    }
    if (cached_has_bits & 0x00000008u) {
      semaporekey_ = from.semaporekey_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void MemoryConfig::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:MyMessage.MemoryConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MemoryConfig::CopyFrom(const MemoryConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:MyMessage.MemoryConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MemoryConfig::IsInitialized() const {
  return true;
}

void MemoryConfig::InternalSwap(MemoryConfig* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(memorykey_, other->memorykey_);
  swap(memorysize_, other->memorysize_);
  swap(resshift_, other->resshift_);
  swap(semaporekey_, other->semaporekey_);
}

::PROTOBUF_NAMESPACE_ID::Metadata MemoryConfig::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace MyMessage
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::MyMessage::MemoryConfig* Arena::CreateMaybeMessage< ::MyMessage::MemoryConfig >(Arena* arena) {
  return Arena::CreateInternal< ::MyMessage::MemoryConfig >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
