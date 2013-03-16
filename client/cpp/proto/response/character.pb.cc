// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "character.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto {
namespace response {
namespace character {

namespace {

const ::google::protobuf::Descriptor* GetCharacterInfoResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetCharacterInfoResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_character_2eproto() {
  protobuf_AddDesc_character_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "character.proto");
  GOOGLE_CHECK(file != NULL);
  GetCharacterInfoResponse_descriptor_ = file->message_type(0);
  static const int GetCharacterInfoResponse_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, confid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, level_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, hp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, mp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, attack_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, defense_),
  };
  GetCharacterInfoResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetCharacterInfoResponse_descriptor_,
      GetCharacterInfoResponse::default_instance_,
      GetCharacterInfoResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetCharacterInfoResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GetCharacterInfoResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_character_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetCharacterInfoResponse_descriptor_, &GetCharacterInfoResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_character_2eproto() {
  delete GetCharacterInfoResponse::default_instance_;
  delete GetCharacterInfoResponse_reflection_;
}

void protobuf_AddDesc_character_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017character.proto\022\030proto.response.charac"
    "ter\"\202\001\n\030GetCharacterInfoResponse\022\016\n\006stat"
    "us\030\001 \001(\005\022\016\n\006confid\030\002 \001(\005\022\r\n\005level\030\003 \001(\005\022"
    "\n\n\002hp\030\004 \001(\005\022\n\n\002mp\030\005 \001(\005\022\016\n\006attack\030\006 \001(\005\022"
    "\017\n\007defense\030\007 \001(\005", 176);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "character.proto", &protobuf_RegisterTypes);
  GetCharacterInfoResponse::default_instance_ = new GetCharacterInfoResponse();
  GetCharacterInfoResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_character_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_character_2eproto {
  StaticDescriptorInitializer_character_2eproto() {
    protobuf_AddDesc_character_2eproto();
  }
} static_descriptor_initializer_character_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int GetCharacterInfoResponse::kStatusFieldNumber;
const int GetCharacterInfoResponse::kConfidFieldNumber;
const int GetCharacterInfoResponse::kLevelFieldNumber;
const int GetCharacterInfoResponse::kHpFieldNumber;
const int GetCharacterInfoResponse::kMpFieldNumber;
const int GetCharacterInfoResponse::kAttackFieldNumber;
const int GetCharacterInfoResponse::kDefenseFieldNumber;
#endif  // !_MSC_VER

GetCharacterInfoResponse::GetCharacterInfoResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void GetCharacterInfoResponse::InitAsDefaultInstance() {
}

GetCharacterInfoResponse::GetCharacterInfoResponse(const GetCharacterInfoResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void GetCharacterInfoResponse::SharedCtor() {
  _cached_size_ = 0;
  status_ = 0;
  confid_ = 0;
  level_ = 0;
  hp_ = 0;
  mp_ = 0;
  attack_ = 0;
  defense_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GetCharacterInfoResponse::~GetCharacterInfoResponse() {
  SharedDtor();
}

void GetCharacterInfoResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GetCharacterInfoResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetCharacterInfoResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GetCharacterInfoResponse_descriptor_;
}

const GetCharacterInfoResponse& GetCharacterInfoResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_character_2eproto();  return *default_instance_;
}

GetCharacterInfoResponse* GetCharacterInfoResponse::default_instance_ = NULL;

GetCharacterInfoResponse* GetCharacterInfoResponse::New() const {
  return new GetCharacterInfoResponse;
}

void GetCharacterInfoResponse::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    status_ = 0;
    confid_ = 0;
    level_ = 0;
    hp_ = 0;
    mp_ = 0;
    attack_ = 0;
    defense_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GetCharacterInfoResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 status = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &status_)));
          set_has_status();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_confid;
        break;
      }
      
      // optional int32 confid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_confid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &confid_)));
          set_has_confid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_level;
        break;
      }
      
      // optional int32 level = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_level:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &level_)));
          set_has_level();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_hp;
        break;
      }
      
      // optional int32 hp = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_hp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &hp_)));
          set_has_hp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_mp;
        break;
      }
      
      // optional int32 mp = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_mp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &mp_)));
          set_has_mp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_attack;
        break;
      }
      
      // optional int32 attack = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_attack:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &attack_)));
          set_has_attack();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_defense;
        break;
      }
      
      // optional int32 defense = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_defense:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &defense_)));
          set_has_defense();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void GetCharacterInfoResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 status = 1;
  if (has_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->status(), output);
  }
  
  // optional int32 confid = 2;
  if (has_confid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->confid(), output);
  }
  
  // optional int32 level = 3;
  if (has_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->level(), output);
  }
  
  // optional int32 hp = 4;
  if (has_hp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->hp(), output);
  }
  
  // optional int32 mp = 5;
  if (has_mp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->mp(), output);
  }
  
  // optional int32 attack = 6;
  if (has_attack()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->attack(), output);
  }
  
  // optional int32 defense = 7;
  if (has_defense()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->defense(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* GetCharacterInfoResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 status = 1;
  if (has_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->status(), target);
  }
  
  // optional int32 confid = 2;
  if (has_confid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->confid(), target);
  }
  
  // optional int32 level = 3;
  if (has_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->level(), target);
  }
  
  // optional int32 hp = 4;
  if (has_hp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->hp(), target);
  }
  
  // optional int32 mp = 5;
  if (has_mp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->mp(), target);
  }
  
  // optional int32 attack = 6;
  if (has_attack()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->attack(), target);
  }
  
  // optional int32 defense = 7;
  if (has_defense()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->defense(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int GetCharacterInfoResponse::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 status = 1;
    if (has_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->status());
    }
    
    // optional int32 confid = 2;
    if (has_confid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->confid());
    }
    
    // optional int32 level = 3;
    if (has_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->level());
    }
    
    // optional int32 hp = 4;
    if (has_hp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->hp());
    }
    
    // optional int32 mp = 5;
    if (has_mp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->mp());
    }
    
    // optional int32 attack = 6;
    if (has_attack()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->attack());
    }
    
    // optional int32 defense = 7;
    if (has_defense()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->defense());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetCharacterInfoResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GetCharacterInfoResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GetCharacterInfoResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GetCharacterInfoResponse::MergeFrom(const GetCharacterInfoResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_status()) {
      set_status(from.status());
    }
    if (from.has_confid()) {
      set_confid(from.confid());
    }
    if (from.has_level()) {
      set_level(from.level());
    }
    if (from.has_hp()) {
      set_hp(from.hp());
    }
    if (from.has_mp()) {
      set_mp(from.mp());
    }
    if (from.has_attack()) {
      set_attack(from.attack());
    }
    if (from.has_defense()) {
      set_defense(from.defense());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GetCharacterInfoResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetCharacterInfoResponse::CopyFrom(const GetCharacterInfoResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetCharacterInfoResponse::IsInitialized() const {
  
  return true;
}

void GetCharacterInfoResponse::Swap(GetCharacterInfoResponse* other) {
  if (other != this) {
    std::swap(status_, other->status_);
    std::swap(confid_, other->confid_);
    std::swap(level_, other->level_);
    std::swap(hp_, other->hp_);
    std::swap(mp_, other->mp_);
    std::swap(attack_, other->attack_);
    std::swap(defense_, other->defense_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GetCharacterInfoResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GetCharacterInfoResponse_descriptor_;
  metadata.reflection = GetCharacterInfoResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace character
}  // namespace response
}  // namespace proto

// @@protoc_insertion_point(global_scope)
