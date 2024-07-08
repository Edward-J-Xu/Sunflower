// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: signaturepb/signature.proto
// Protobuf C++ Version: 5.26.1

#include "signaturepb/signature.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace signaturepb {

inline constexpr Signature::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : publickey_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        signature_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Signature::Signature(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct SignatureDefaultTypeInternal {
  PROTOBUF_CONSTEXPR SignatureDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~SignatureDefaultTypeInternal() {}
  union {
    Signature _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 SignatureDefaultTypeInternal _Signature_default_instance_;
}  // namespace signaturepb
static ::_pb::Metadata file_level_metadata_signaturepb_2fsignature_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_signaturepb_2fsignature_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_signaturepb_2fsignature_2eproto = nullptr;
const ::uint32_t
    TableStruct_signaturepb_2fsignature_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::signaturepb::Signature, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::signaturepb::Signature, _impl_.publickey_),
        PROTOBUF_FIELD_OFFSET(::signaturepb::Signature, _impl_.signature_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::signaturepb::Signature)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::signaturepb::_Signature_default_instance_._instance,
};
const char descriptor_table_protodef_signaturepb_2fsignature_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\033signaturepb/signature.proto\022\013signature"
    "pb\"1\n\tSignature\022\021\n\tpublicKey\030\001 \001(\014\022\021\n\tsi"
    "gnature\030\002 \001(\014b\006proto3"
};
static ::absl::once_flag descriptor_table_signaturepb_2fsignature_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_signaturepb_2fsignature_2eproto = {
    false,
    false,
    101,
    descriptor_table_protodef_signaturepb_2fsignature_2eproto,
    "signaturepb/signature.proto",
    &descriptor_table_signaturepb_2fsignature_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_signaturepb_2fsignature_2eproto::offsets,
    file_level_metadata_signaturepb_2fsignature_2eproto,
    file_level_enum_descriptors_signaturepb_2fsignature_2eproto,
    file_level_service_descriptors_signaturepb_2fsignature_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_signaturepb_2fsignature_2eproto_getter() {
  return &descriptor_table_signaturepb_2fsignature_2eproto;
}
namespace signaturepb {
// ===================================================================

class Signature::_Internal {
 public:
};

Signature::Signature(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:signaturepb.Signature)
}
inline PROTOBUF_NDEBUG_INLINE Signature::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : publickey_(arena, from.publickey_),
        signature_(arena, from.signature_),
        _cached_size_{0} {}

Signature::Signature(
    ::google::protobuf::Arena* arena,
    const Signature& from)
    : ::google::protobuf::Message(arena) {
  Signature* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:signaturepb.Signature)
}
inline PROTOBUF_NDEBUG_INLINE Signature::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : publickey_(arena),
        signature_(arena),
        _cached_size_{0} {}

inline void Signature::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Signature::~Signature() {
  // @@protoc_insertion_point(destructor:signaturepb.Signature)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Signature::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.publickey_.Destroy();
  _impl_.signature_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Signature::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(Signature, _impl_._cached_size_),
              false,
          },
          &Signature::MergeImpl,
          &Signature::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void Signature::Clear() {
// @@protoc_insertion_point(message_clear_start:signaturepb.Signature)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.publickey_.ClearToEmpty();
  _impl_.signature_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Signature::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 0, 2> Signature::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Signature_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::signaturepb::Signature>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // bytes signature = 2;
    {::_pbi::TcParser::FastBS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(Signature, _impl_.signature_)}},
    // bytes publicKey = 1;
    {::_pbi::TcParser::FastBS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Signature, _impl_.publickey_)}},
  }}, {{
    65535, 65535
  }}, {{
    // bytes publicKey = 1;
    {PROTOBUF_FIELD_OFFSET(Signature, _impl_.publickey_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBytes | ::_fl::kRepAString)},
    // bytes signature = 2;
    {PROTOBUF_FIELD_OFFSET(Signature, _impl_.signature_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBytes | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
  }},
};

::uint8_t* Signature::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:signaturepb.Signature)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // bytes publicKey = 1;
  if (!this->_internal_publickey().empty()) {
    const std::string& _s = this->_internal_publickey();
    target = stream->WriteBytesMaybeAliased(1, _s, target);
  }

  // bytes signature = 2;
  if (!this->_internal_signature().empty()) {
    const std::string& _s = this->_internal_signature();
    target = stream->WriteBytesMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:signaturepb.Signature)
  return target;
}

::size_t Signature::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:signaturepb.Signature)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes publicKey = 1;
  if (!this->_internal_publickey().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                    this->_internal_publickey());
  }

  // bytes signature = 2;
  if (!this->_internal_signature().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                    this->_internal_signature());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Signature::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Signature*>(&to_msg);
  auto& from = static_cast<const Signature&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:signaturepb.Signature)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_publickey().empty()) {
    _this->_internal_set_publickey(from._internal_publickey());
  }
  if (!from._internal_signature().empty()) {
    _this->_internal_set_signature(from._internal_signature());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Signature::CopyFrom(const Signature& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:signaturepb.Signature)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Signature::IsInitialized() const {
  return true;
}

void Signature::InternalSwap(Signature* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.publickey_, &other->_impl_.publickey_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.signature_, &other->_impl_.signature_, arena);
}

::google::protobuf::Metadata Signature::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_signaturepb_2fsignature_2eproto_getter,
                                   &descriptor_table_signaturepb_2fsignature_2eproto_once,
                                   file_level_metadata_signaturepb_2fsignature_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace signaturepb
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_signaturepb_2fsignature_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"
