#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef int status;
typedef unsigned char u8;
typedef uint32_t UA_UInt32;

#define UA_JSON_ENCODING_MAX_RECURSION 100
#define UA_STATUSCODE_BADENCODINGERROR 1
#define UA_STATUSCODE_GOOD 0

typedef struct {
    int depth;
    bool *commaNeeded;
} CtxJson;

typedef struct {
    size_t memSize;
} UA_DataType;

status encodeJsonArray(CtxJson *ctx, void* array, UA_UInt32 length, const UA_DataType *type);
status writeJsonArrStart(CtxJson *ctx);
status writeJsonCommaIfNeeded(CtxJson *ctx);
status writeJsonArrEnd(CtxJson *ctx);