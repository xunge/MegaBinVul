#include <stddef.h>

#define C_NULL NULL
#define XS_INSTANCE_KIND 0
#define XS_REFERENCE_KIND 0
#define XS_HOST_KIND 0
#define XS_INTERNAL_FLAG 0
#define XS_HOST_HOOKS_FLAG 0

typedef struct txSlot txSlot;

struct txSlot {
    int kind;
    int flag;
    union {
        struct {
            void* garbage;
            txSlot* prototype;
        } instance;
        struct {
            void* data;
            union {
                void (*destructor)(void);
                void* hooks;
            } variant;
        } host;
        txSlot* reference;
    } value;
    txSlot* next;
};

typedef struct txMachine {
    txSlot* stack;
} txMachine;

txSlot* fxGetInstance(txMachine* the, txSlot* slot);
txSlot* fxNewSlot(txMachine* the);
void fxReleaseSharedChunk(void);