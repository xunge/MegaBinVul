#include <stdint.h>
#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;

#define JSI_VT_OBJECT 1

struct Jsi_Value {
    int vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    int isarrlist;
    unsigned int arrCnt;
    Jsi_Value **arr;
};

void Jsi_LogBug(const char *msg);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *v);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *v, int index);
void Jsi_ValueReset(Jsi_Interp *interp, Jsi_Value **v);
void Jsi_ValueCopy(Jsi_Interp *interp, Jsi_Value *dst, Jsi_Value *src);
void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);

typedef unsigned int uint;