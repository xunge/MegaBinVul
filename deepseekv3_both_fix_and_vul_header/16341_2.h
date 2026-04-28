#include <stdint.h>

typedef int32_t txInteger;
typedef uint32_t txID;

typedef enum {
    XS_UNDEFINED_KIND,
    XS_NULL_KIND, 
    XS_REFERENCE_KIND
} txKind;

typedef struct txSlot {
    txKind kind;
} txSlot;

typedef struct txMachine {
    txSlot* stack;
    txSlot* argv;
    txSlot result;
    int32_t argc;
    int32_t top;
} txMachine;

#define mxThis (&the->stack[0])
#define mxArgc (the->argc)
#define mxArgv(i) (&the->argv[i])
#define mxResult (&the->result)
#define mxPushSlot(slot) (the->stack[++the->top] = *(slot))
#define mxPushUndefined() (the->stack[++the->top].kind = XS_UNDEFINED_KIND)
#define mxCall() (fxCall(the))
#define mxTypeError(msg) (fxTypeError(the, msg))
#define mxRunCount(c) (fxRunCount(the, c))
#define mxPullSlot(slot) (*(slot) = the->stack[the->top--])

#define _length 0

txID mxID(txID id);

void fxCheckCallable(txMachine* the, txSlot* slot);
void fxToInstance(txMachine* the, txSlot* slot);
void fxGetID(txMachine* the, txID id);
txInteger fxToInteger(txMachine* the, txSlot* slot);
void fxCall(txMachine* the);
void fxTypeError(txMachine* the, const char* msg);
void fxRunCount(txMachine* the, txInteger count);