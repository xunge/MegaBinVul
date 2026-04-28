#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

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

int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, int num);
int Jsi_ValueGetLength(Jsi_Interp *interp, Jsi_Value *args);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
void Jsi_LogBug(const char *msg);
Jsi_Value* Jsi_ValueNew(Jsi_Interp *interp);
void Jsi_ValueInsertArray(Jsi_Interp *interp, Jsi_Value *arr, int index, Jsi_Value *val, int flags);