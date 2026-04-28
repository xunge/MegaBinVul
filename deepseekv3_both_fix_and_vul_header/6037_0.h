#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_Func Jsi_Func;

typedef enum {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef enum {
    JSI_OK
} Jsi_RC;

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_Value **arr;
    int arrCnt;
};

int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, double num);
void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **ret);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *arr, int index);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *v);
void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);