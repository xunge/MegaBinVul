#include <assert.h>
#include <stddef.h>

typedef int Jsi_RC;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Hash Jsi_Hash;
typedef struct Jsi_HashEntry Jsi_HashEntry;
typedef struct Jsi_HashSearch {
    int dummy;
} Jsi_HashSearch;

typedef struct Jsi_UserObj {
    void* data;
    Jsi_HashEntry* hPtr;
} Jsi_UserObj;

typedef struct Jsi_Obj {
    int ot;
    union {
        Jsi_UserObj* uobj;
    } d;
} Jsi_Obj;

typedef struct UserObjReg {
    Jsi_Hash* hashPtr;
    struct {
        void (*freefun)(Jsi_Interp*, void*);
    } *reg;
} UserObjReg;

#define SIGASSERT(ptr, type)
#define JSI_OK 0
#define JSI_OT_USEROBJ 1
#define USER_REG 1
#define OBJ 1

void* Jsi_HashValueGet(Jsi_HashEntry* hPtr);
Jsi_HashEntry* Jsi_HashSearchFirst(Jsi_Hash* tblPtr, Jsi_HashSearch* search);
Jsi_HashEntry* Jsi_HashSearchNext(Jsi_HashSearch* search);
void Jsi_HashEntryDelete(Jsi_HashEntry* hPtr);
void Jsi_HashDelete(Jsi_Hash* tblPtr);
void Jsi_Free(void* ptr);