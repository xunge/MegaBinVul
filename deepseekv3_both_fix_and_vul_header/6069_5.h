#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef int status;
typedef unsigned char u8;
typedef bool UA_Boolean;

typedef struct CtxJson {
    size_t depth;
} CtxJson;

typedef struct ParseCtx {
    // Minimal definition since actual members are unknown
} ParseCtx;

typedef struct UA_DataType UA_DataType;
typedef struct UA_DataTypeMember UA_DataTypeMember;
typedef struct DecodeEntry DecodeEntry;

typedef status (*decodeJsonSignature)(void*, const UA_DataType*, CtxJson*, ParseCtx*, UA_Boolean);

#define UA_JSON_ENCODING_MAX_RECURSION 100
#define UA_STATUSCODE_BADENCODINGERROR 0
#define UA_STATUSCODE_GOOD 0

#define UA_TYPES NULL
#define UA_STACKARRAY(type, name, size) type name[size]

extern status (*decodeJsonJumpTable[])(void*, const UA_DataType*, CtxJson*, ParseCtx*, UA_Boolean);
extern status Array_decodeJson(void*, const UA_DataType*, CtxJson*, ParseCtx*, UA_Boolean);
extern status decodeFields(CtxJson*, ParseCtx*, DecodeEntry*, size_t, const UA_DataType*);

struct DecodeEntry {
    const UA_DataType *type;
    const char *fieldName;
    void *fieldPointer;
    decodeJsonSignature function;
    UA_Boolean found;
};

struct UA_DataType {
    size_t membersSize;
    size_t typeIndex;
    UA_DataTypeMember *members;
    size_t memSize;
    int typeKind;
};

struct UA_DataTypeMember {
    UA_Boolean isArray;
    size_t padding;
    const char *memberName;
    size_t memberTypeIndex;
    UA_Boolean namespaceZero;
};