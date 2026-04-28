#include <stdlib.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_UserObj Jsi_UserObj;
typedef struct Jsi_UserObjReg Jsi_UserObjReg;
typedef struct Jsi_HashEntry Jsi_HashEntry;

struct Jsi_UserObj {
    Jsi_Interp *interp;
    Jsi_UserObjReg *reg;
    void *data;
    Jsi_HashEntry *hPtr;
};

struct Jsi_UserObjReg {
    void (*freefun)(Jsi_Interp*, void*);
};

void Jsi_LogError(const char *msg);
void Jsi_HashEntryDelete(Jsi_HashEntry *hPtr);
void _JSI_MEMCLEAR(void *ptr);
void Jsi_Free(void *ptr);