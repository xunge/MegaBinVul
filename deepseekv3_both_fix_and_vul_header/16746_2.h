#include <cstddef>
#include <cstdint>
#include <algorithm>

namespace protocol {
enum class TType {
    T_STRUCT
};
}

struct Protocol_ {
    size_t writeStructBegin(const char*);
    size_t writeFieldBegin(const char*, protocol::TType, int);
    size_t writeStructEnd();
    size_t writeFieldStop();
    size_t writeFieldEnd();
};

struct FieldInfo {
    int id;
    const char* name;
    struct TypeInfo* typeInfo;
    bool isUnqualified;
    size_t issetOffset;
};

struct StructInfo {
    const char* name;
    const FieldInfo* fieldInfos;
    int16_t numFields;
    struct UnionExt* unionExt;
};

struct UnionExt {
    size_t unionTypeOffset;
};

struct TypeInfo {
    protocol::TType type;
};

struct OptionalThriftValue {
    bool hasValue() const;
    int value() const;
};

using FieldID = int;

bool DCHECK(const void*);
bool UNLIKELY(bool);
bool fieldIsSet(const void*, size_t);
const void* getMember(const FieldInfo&, const void*);
OptionalThriftValue getValue(const TypeInfo&, const void*);
size_t writeField(Protocol_*, const FieldInfo&, int);
FieldID getActiveId(const void*, const StructInfo&);
FieldID activeUnionMemberId(const void*, size_t);