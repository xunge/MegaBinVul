#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct txMachine txMachine;
typedef struct txSlot txSlot;
typedef struct txReference txReference;
typedef long txInteger;
typedef unsigned char txByte;

#define C_NULL NULL
#define XS_REFERENCE_KIND 1
#define XS_ARRAY_BUFFER_KIND 2

struct txReference {
    txSlot* next;
};

struct txSlot {
    int kind;
    union {
        struct {
            txSlot* next;
        };
        struct {
            txReference* reference;
        };
        struct {
            struct {
                txInteger length;
                txByte* address;
            } bufferInfo;
        };
        struct {
            txByte* address;
        } arrayBuffer;
    } value;
    txSlot* next;
};

extern txSlot* mxThis;
extern txInteger mxArgc;
extern txSlot* (*mxArgv)(txInteger);
extern txSlot* mxResult;

void mxTypeError(const char* format, ...);

txSlot* fxCheckArrayBufferInstance(txMachine* the, txSlot* instance);
txInteger fxAddChunkSizes(txMachine* the, txInteger a, txInteger b);
void fxConstructArrayBufferResult(txMachine* the, txSlot* slot, txInteger length);

#define c_memcpy memcpy