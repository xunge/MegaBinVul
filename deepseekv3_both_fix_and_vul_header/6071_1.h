#include <stdint.h>
#include <stddef.h>

typedef int status;
typedef unsigned char u8;

typedef struct CtxJson {
    int depth;
} CtxJson;

typedef struct UA_DataTypeMember UA_DataTypeMember;

typedef struct UA_DataType {
    size_t membersSize;
    size_t typeIndex;
    int typeKind;
    size_t memSize;
    UA_DataTypeMember *members;
} UA_DataType;

struct UA_DataTypeMember {
    const char *memberName;
    int namespaceZero;
    size_t memberTypeIndex;
    int isArray;
    size_t padding;
};

#define UA_JSON_ENCODING_MAX_RECURSION 100
#define UA_STATUSCODE_BADENCODINGERROR (-1)
#define UA_STATUSCODE_GOOD 0

extern const UA_DataType UA_TYPES[];
extern status (*encodeJsonJumpTable[])(const void *, const UA_DataType *, CtxJson *);
extern status writeJsonObjStart(CtxJson *);
extern status writeJsonKey(CtxJson *, const char *);
extern status writeJsonObjEnd(CtxJson *);
extern status encodeJsonArray(CtxJson *, void *, size_t, const UA_DataType *);