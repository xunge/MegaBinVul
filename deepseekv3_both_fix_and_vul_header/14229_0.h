#include <stddef.h>

typedef int txID;
typedef int txIndex;
typedef int txFlag;
typedef int txKind;

typedef struct txSlot txSlot;
typedef struct txMachine txMachine;

struct txSlot {
    txID ID;
    txSlot* next;
    union {
        txSlot* closure;
        void* value;
    } value;
    txKind kind;
};

struct txMachine {
    txSlot** aliasArray;
};

#define C_NULL NULL
#define XS_REFERENCE_ERROR 0
void mxDebugID(int error, const char* message, txID id);