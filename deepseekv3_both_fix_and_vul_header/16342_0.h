#include <stdint.h>

typedef int txBoolean;
typedef uintptr_t txID;
typedef unsigned int txIndex;
typedef unsigned int txFlag;

typedef struct txMachine txMachine;
typedef struct txSlot txSlot;

struct txSlot {
    txSlot* next;
    int kind;
    txFlag flag;
    union {
        void* closure;
        void* value;
    } value;
};

#define XS_CLOSURE_KIND 0
#define XS_UNINITIALIZED_KIND 0
#define XS_ACCESSOR_FLAG 0
#define XS_DONT_SET_FLAG 0

txSlot* fxGetIndexProperty(txMachine* the, txSlot* instance, txIndex index);
txBoolean fxOrdinaryDefineOwnProperty(txMachine* the, txSlot* instance, txID id, txIndex index, txSlot* descriptor, txFlag mask);