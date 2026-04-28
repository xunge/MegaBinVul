#include <math.h>
#include <string.h>
#include <stdint.h>

typedef struct txMachine txMachine;
typedef int64_t txInteger;
typedef double txNumber;
typedef size_t txSize;
typedef uint8_t txU8;

typedef union {
    txNumber number;
    char* string;
} txValue;

typedef struct txSlot {
    int kind;
    txValue value;
} txSlot;

typedef char* txString;

#define ICACHE_FLASH_ATTR
#define C_FP_INFINITE FP_INFINITE
#define C_FP_NAN FP_NAN
#define C_FP_ZERO FP_ZERO
#define C_MAX_SAFE_INTEGER 9007199254740991
#define c_fpclassify fpclassify
#define c_floor floor
#define c_log log
#define c_fmod fmod
#define c_memmove memmove
#define c_read8(ptr) (*(ptr))

#define XS_STRING_KIND 1

#define mxThis ((void*)0)
#define mxArgc 0
#define mxArgv(i) ((void*)0)
#define mxIsUndefined(x) (0)
#define mxResult ((txSlot*)0)
#define mxTypeError(msg)
#define mxRangeError(msg)

txSlot* fxCheckNumber(txMachine* the, void* this);
txInteger fxToInteger(txMachine* the, void* arg);
void fxStringX(txMachine* the, txSlot* result, const char* str);
void fxToString(txMachine* the, txSlot* result);
txString fxNewChunk(txMachine* the, txSize size);
txString fxRenewChunk(txMachine* the, txString chunk, txSize size);