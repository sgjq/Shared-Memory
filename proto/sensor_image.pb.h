// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sensor_image.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_sensor_5fimage_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_sensor_5fimage_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_sensor_5fimage_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_sensor_5fimage_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_sensor_5fimage_2eproto;
namespace MyMessage {
class Image;
class ImageDefaultTypeInternal;
extern ImageDefaultTypeInternal _Image_default_instance_;
}  // namespace MyMessage
PROTOBUF_NAMESPACE_OPEN
template<> ::MyMessage::Image* Arena::CreateMaybeMessage<::MyMessage::Image>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace MyMessage {

enum Image_ImageType : int {
  Image_ImageType_RGB8 = 0,
  Image_ImageType_BGR8 = 1,
  Image_ImageType_MONO8 = 2
};
bool Image_ImageType_IsValid(int value);
constexpr Image_ImageType Image_ImageType_ImageType_MIN = Image_ImageType_RGB8;
constexpr Image_ImageType Image_ImageType_ImageType_MAX = Image_ImageType_MONO8;
constexpr int Image_ImageType_ImageType_ARRAYSIZE = Image_ImageType_ImageType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Image_ImageType_descriptor();
template<typename T>
inline const std::string& Image_ImageType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Image_ImageType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Image_ImageType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Image_ImageType_descriptor(), enum_t_value);
}
inline bool Image_ImageType_Parse(
    const std::string& name, Image_ImageType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Image_ImageType>(
    Image_ImageType_descriptor(), name, value);
}
// ===================================================================

class Image :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:MyMessage.Image) */ {
 public:
  Image();
  virtual ~Image();

  Image(const Image& from);
  Image(Image&& from) noexcept
    : Image() {
    *this = ::std::move(from);
  }

  inline Image& operator=(const Image& from) {
    CopyFrom(from);
    return *this;
  }
  inline Image& operator=(Image&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Image& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Image* internal_default_instance() {
    return reinterpret_cast<const Image*>(
               &_Image_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Image& a, Image& b) {
    a.Swap(&b);
  }
  inline void Swap(Image* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Image* New() const final {
    return CreateMaybeMessage<Image>(nullptr);
  }

  Image* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Image>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Image& from);
  void MergeFrom(const Image& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Image* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "MyMessage.Image";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_sensor_5fimage_2eproto);
    return ::descriptor_table_sensor_5fimage_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef Image_ImageType ImageType;
  static constexpr ImageType RGB8 =
    Image_ImageType_RGB8;
  static constexpr ImageType BGR8 =
    Image_ImageType_BGR8;
  static constexpr ImageType MONO8 =
    Image_ImageType_MONO8;
  static inline bool ImageType_IsValid(int value) {
    return Image_ImageType_IsValid(value);
  }
  static constexpr ImageType ImageType_MIN =
    Image_ImageType_ImageType_MIN;
  static constexpr ImageType ImageType_MAX =
    Image_ImageType_ImageType_MAX;
  static constexpr int ImageType_ARRAYSIZE =
    Image_ImageType_ImageType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  ImageType_descriptor() {
    return Image_ImageType_descriptor();
  }
  template<typename T>
  static inline const std::string& ImageType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, ImageType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function ImageType_Name.");
    return Image_ImageType_Name(enum_t_value);
  }
  static inline bool ImageType_Parse(const std::string& name,
      ImageType* value) {
    return Image_ImageType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kFrameIdFieldNumber = 1,
    kDataFieldNumber = 7,
    kMeasurementTimeFieldNumber = 3,
    kFormatFieldNumber = 2,
    kHeightFieldNumber = 4,
    kWidthFieldNumber = 5,
    kStepFieldNumber = 6,
  };
  // required string frame_id = 1;
  bool has_frame_id() const;
  private:
  bool _internal_has_frame_id() const;
  public:
  void clear_frame_id();
  const std::string& frame_id() const;
  void set_frame_id(const std::string& value);
  void set_frame_id(std::string&& value);
  void set_frame_id(const char* value);
  void set_frame_id(const char* value, size_t size);
  std::string* mutable_frame_id();
  std::string* release_frame_id();
  void set_allocated_frame_id(std::string* frame_id);
  private:
  const std::string& _internal_frame_id() const;
  void _internal_set_frame_id(const std::string& value);
  std::string* _internal_mutable_frame_id();
  public:

  // required bytes data = 7;
  bool has_data() const;
  private:
  bool _internal_has_data() const;
  public:
  void clear_data();
  const std::string& data() const;
  void set_data(const std::string& value);
  void set_data(std::string&& value);
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  std::string* mutable_data();
  std::string* release_data();
  void set_allocated_data(std::string* data);
  private:
  const std::string& _internal_data() const;
  void _internal_set_data(const std::string& value);
  std::string* _internal_mutable_data();
  public:

  // required double measurement_time = 3;
  bool has_measurement_time() const;
  private:
  bool _internal_has_measurement_time() const;
  public:
  void clear_measurement_time();
  double measurement_time() const;
  void set_measurement_time(double value);
  private:
  double _internal_measurement_time() const;
  void _internal_set_measurement_time(double value);
  public:

  // required .MyMessage.Image.ImageType format = 2;
  bool has_format() const;
  private:
  bool _internal_has_format() const;
  public:
  void clear_format();
  ::MyMessage::Image_ImageType format() const;
  void set_format(::MyMessage::Image_ImageType value);
  private:
  ::MyMessage::Image_ImageType _internal_format() const;
  void _internal_set_format(::MyMessage::Image_ImageType value);
  public:

  // required uint32 height = 4;
  bool has_height() const;
  private:
  bool _internal_has_height() const;
  public:
  void clear_height();
  ::PROTOBUF_NAMESPACE_ID::uint32 height() const;
  void set_height(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_height() const;
  void _internal_set_height(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 width = 5;
  bool has_width() const;
  private:
  bool _internal_has_width() const;
  public:
  void clear_width();
  ::PROTOBUF_NAMESPACE_ID::uint32 width() const;
  void set_width(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_width() const;
  void _internal_set_width(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 step = 6;
  bool has_step() const;
  private:
  bool _internal_has_step() const;
  public:
  void clear_step();
  ::PROTOBUF_NAMESPACE_ID::uint32 step() const;
  void set_step(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_step() const;
  void _internal_set_step(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:MyMessage.Image)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr frame_id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_;
  double measurement_time_;
  int format_;
  ::PROTOBUF_NAMESPACE_ID::uint32 height_;
  ::PROTOBUF_NAMESPACE_ID::uint32 width_;
  ::PROTOBUF_NAMESPACE_ID::uint32 step_;
  friend struct ::TableStruct_sensor_5fimage_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Image

// required string frame_id = 1;
inline bool Image::_internal_has_frame_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Image::has_frame_id() const {
  return _internal_has_frame_id();
}
inline void Image::clear_frame_id() {
  frame_id_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Image::frame_id() const {
  // @@protoc_insertion_point(field_get:MyMessage.Image.frame_id)
  return _internal_frame_id();
}
inline void Image::set_frame_id(const std::string& value) {
  _internal_set_frame_id(value);
  // @@protoc_insertion_point(field_set:MyMessage.Image.frame_id)
}
inline std::string* Image::mutable_frame_id() {
  // @@protoc_insertion_point(field_mutable:MyMessage.Image.frame_id)
  return _internal_mutable_frame_id();
}
inline const std::string& Image::_internal_frame_id() const {
  return frame_id_.GetNoArena();
}
inline void Image::_internal_set_frame_id(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  frame_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Image::set_frame_id(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  frame_id_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:MyMessage.Image.frame_id)
}
inline void Image::set_frame_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  frame_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:MyMessage.Image.frame_id)
}
inline void Image::set_frame_id(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  frame_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:MyMessage.Image.frame_id)
}
inline std::string* Image::_internal_mutable_frame_id() {
  _has_bits_[0] |= 0x00000001u;
  return frame_id_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Image::release_frame_id() {
  // @@protoc_insertion_point(field_release:MyMessage.Image.frame_id)
  if (!_internal_has_frame_id()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return frame_id_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Image::set_allocated_frame_id(std::string* frame_id) {
  if (frame_id != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  frame_id_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), frame_id);
  // @@protoc_insertion_point(field_set_allocated:MyMessage.Image.frame_id)
}

// required .MyMessage.Image.ImageType format = 2;
inline bool Image::_internal_has_format() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool Image::has_format() const {
  return _internal_has_format();
}
inline void Image::clear_format() {
  format_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::MyMessage::Image_ImageType Image::_internal_format() const {
  return static_cast< ::MyMessage::Image_ImageType >(format_);
}
inline ::MyMessage::Image_ImageType Image::format() const {
  // @@protoc_insertion_point(field_get:MyMessage.Image.format)
  return _internal_format();
}
inline void Image::_internal_set_format(::MyMessage::Image_ImageType value) {
  assert(::MyMessage::Image_ImageType_IsValid(value));
  _has_bits_[0] |= 0x00000008u;
  format_ = value;
}
inline void Image::set_format(::MyMessage::Image_ImageType value) {
  _internal_set_format(value);
  // @@protoc_insertion_point(field_set:MyMessage.Image.format)
}

// required double measurement_time = 3;
inline bool Image::_internal_has_measurement_time() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool Image::has_measurement_time() const {
  return _internal_has_measurement_time();
}
inline void Image::clear_measurement_time() {
  measurement_time_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline double Image::_internal_measurement_time() const {
  return measurement_time_;
}
inline double Image::measurement_time() const {
  // @@protoc_insertion_point(field_get:MyMessage.Image.measurement_time)
  return _internal_measurement_time();
}
inline void Image::_internal_set_measurement_time(double value) {
  _has_bits_[0] |= 0x00000004u;
  measurement_time_ = value;
}
inline void Image::set_measurement_time(double value) {
  _internal_set_measurement_time(value);
  // @@protoc_insertion_point(field_set:MyMessage.Image.measurement_time)
}

// required uint32 height = 4;
inline bool Image::_internal_has_height() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool Image::has_height() const {
  return _internal_has_height();
}
inline void Image::clear_height() {
  height_ = 0u;
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Image::_internal_height() const {
  return height_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Image::height() const {
  // @@protoc_insertion_point(field_get:MyMessage.Image.height)
  return _internal_height();
}
inline void Image::_internal_set_height(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000010u;
  height_ = value;
}
inline void Image::set_height(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_height(value);
  // @@protoc_insertion_point(field_set:MyMessage.Image.height)
}

// required uint32 width = 5;
inline bool Image::_internal_has_width() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool Image::has_width() const {
  return _internal_has_width();
}
inline void Image::clear_width() {
  width_ = 0u;
  _has_bits_[0] &= ~0x00000020u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Image::_internal_width() const {
  return width_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Image::width() const {
  // @@protoc_insertion_point(field_get:MyMessage.Image.width)
  return _internal_width();
}
inline void Image::_internal_set_width(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000020u;
  width_ = value;
}
inline void Image::set_width(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_width(value);
  // @@protoc_insertion_point(field_set:MyMessage.Image.width)
}

// required uint32 step = 6;
inline bool Image::_internal_has_step() const {
  bool value = (_has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool Image::has_step() const {
  return _internal_has_step();
}
inline void Image::clear_step() {
  step_ = 0u;
  _has_bits_[0] &= ~0x00000040u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Image::_internal_step() const {
  return step_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Image::step() const {
  // @@protoc_insertion_point(field_get:MyMessage.Image.step)
  return _internal_step();
}
inline void Image::_internal_set_step(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000040u;
  step_ = value;
}
inline void Image::set_step(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_step(value);
  // @@protoc_insertion_point(field_set:MyMessage.Image.step)
}

// required bytes data = 7;
inline bool Image::_internal_has_data() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Image::has_data() const {
  return _internal_has_data();
}
inline void Image::clear_data() {
  data_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Image::data() const {
  // @@protoc_insertion_point(field_get:MyMessage.Image.data)
  return _internal_data();
}
inline void Image::set_data(const std::string& value) {
  _internal_set_data(value);
  // @@protoc_insertion_point(field_set:MyMessage.Image.data)
}
inline std::string* Image::mutable_data() {
  // @@protoc_insertion_point(field_mutable:MyMessage.Image.data)
  return _internal_mutable_data();
}
inline const std::string& Image::_internal_data() const {
  return data_.GetNoArena();
}
inline void Image::_internal_set_data(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Image::set_data(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  data_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:MyMessage.Image.data)
}
inline void Image::set_data(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:MyMessage.Image.data)
}
inline void Image::set_data(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  data_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:MyMessage.Image.data)
}
inline std::string* Image::_internal_mutable_data() {
  _has_bits_[0] |= 0x00000002u;
  return data_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Image::release_data() {
  // @@protoc_insertion_point(field_release:MyMessage.Image.data)
  if (!_internal_has_data()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return data_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Image::set_allocated_data(std::string* data) {
  if (data != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  data_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:MyMessage.Image.data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace MyMessage

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::MyMessage::Image_ImageType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::MyMessage::Image_ImageType>() {
  return ::MyMessage::Image_ImageType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_sensor_5fimage_2eproto