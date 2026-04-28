#include <stdint.h>

typedef struct txMachine txMachine;
typedef struct txSlot txSlot;
typedef struct mxResult mxResult;

struct txSlot {
    uint32_t flag;
    uint32_t ID;
    union {
        void* reference;
        int boolean;
    } value;
    txSlot* next;
};

struct mxResult {
    int kind;
    union {
        int boolean;
    } value;
};

struct txMachine {
    int argc;
    txSlot* argv;
    txSlot* stack;
    txSlot* this;
    txSlot** aliasArray;
    mxResult mxResult;  // Changed from pointer to direct member
};

#define XS_BOOLEAN_KIND 1
#define XS_INTERNAL_FLAG 0x100
#define mxArgc the->argc
#define mxArgv(i) (&the->argv[i])
#define mxThis (the->this)
#define mxID(id) id
#define _prototype 1
#define _boundFunction 2
#define mxResult (&the->mxResult)  // Added macro to access mxResult

extern txSlot* fxGetInstance(txMachine* the, txSlot* slot);
extern txSlot* mxFunctionInstanceHome(void* reference);
extern void mxPushSlot(txSlot* slot);
extern void mxGetID(uint32_t id);
extern void mxPop(void);
extern void mxTypeError(const char* message);
extern void mxPushNull(void);
extern int mxBehaviorGetPrototype(txMachine* the, txSlot* instance, txSlot* stack);