#include <stdint.h>
#include <string.h>

typedef int txBoolean;
typedef int32_t txInteger;
typedef uint8_t txByte;
typedef char* txString;
typedef uintptr_t txID;

typedef enum {
    XS_UNDEFINED_KIND,
    XS_STRING_KIND
} txKind;

typedef struct txSlot {
    txKind kind;
    union {
        txString string;
    } value;
} txSlot;

typedef struct txMachine {
    char nameBuffer[256];
    txSlot* stack;
} txMachine;

#define c_read8(ptr) (*(ptr))
#define c_memcpy(dest, src, n) memcpy(dest, src, n)
#define mxPtrDiff(ptr) ((txInteger)(ptr))
#define mxIsReference(slot) (0)
#define mxIsUndefined(slot) ((slot)->kind == XS_UNDEFINED_KIND)
#define mxStringLength(str) strlen(str)
#define mxPushSlot(slot) 
#define mxPop()
#define mxGetID(id)
#define mxPushUndefined()
#define fxNewChunk(the, size) malloc(size)
#define fxAddChunkSizes(the, a, b) ((a) + (b))
#define fxFindName(the, name) (0)
#define fxToString(the, slot)
#define fxAbort(the, code)
#define fxJump(the)