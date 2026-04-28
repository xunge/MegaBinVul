#include <stddef.h>

typedef struct txMachine txMachine;
typedef int txBoolean;
typedef long txInteger;

enum {
    XS_REFERENCE_KIND,
    XS_ARRAY_BUFFER_KIND,
    XS_HOST_KIND
};

struct txBufferInfo {
    long length;
    long maxLength;
};

struct txDataView {
    long offset;
    long size;
};

struct txSlot {
    int kind;
    union {
        struct {
            struct txSlot* reference;
        };
        struct txBufferInfo bufferInfo;
        struct txDataView dataView;
    } value;
    struct txSlot* next;
};

extern struct txSlot* mxTarget;
extern struct txSlot* mxResult;
extern int mxArgc;
extern struct txSlot* (*mxArgv)(int);
extern struct txSlot mxDataViewPrototype;

int mxIsUndefined(struct txSlot*);
void mxTypeError(const char*);
void mxRangeError(const char*, ...);
txInteger fxArgToByteLength(txMachine*, int, int);
struct txSlot* fxGetBufferInfo(txMachine*, struct txSlot*);
void mxPushSlot(struct txSlot*);
void fxGetPrototypeFromConstructor(txMachine*, struct txSlot*);
struct txSlot* fxNewDataViewInstance(txMachine*);
void mxPullSlot(struct txSlot*);

#define txSlot struct txSlot