#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef uint8_t txByte;
typedef int32_t txInteger;
typedef uint8_t txBoolean;
typedef char* txString;
typedef uint32_t txID;

typedef enum {
    XS_UNDEFINED_KIND,
    XS_STRING_KIND,
    XS_NOT_ENOUGH_MEMORY_EXIT
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
#define mxPtrDiff(ptr) (ptr)
#define mxIsReference(slot) (0)
#define mxIsUndefined(slot) ((slot)->kind == XS_UNDEFINED_KIND)
#define mxStringLength(str) strlen(str)
#define mxPushSlot(slot) (void)0
#define mxPop() (void)0
#define mxGetID(id) (void)0
#define mxPushUndefined() (void)0

void fxAbort(txMachine* the, int exitCode);
void fxJump(txMachine* the);
txID fxFindName(txMachine* the, const char* name);
void fxToString(txMachine* the, txSlot* slot);
void* fxNewChunk(txMachine* the, size_t size);
size_t fxAddChunkSizes(txMachine* the, size_t a, size_t b);