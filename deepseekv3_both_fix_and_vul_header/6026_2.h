#include <stdint.h>
#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_FuncObj Jsi_FuncObj;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef enum Jsi_RC {
    JSI_OK
} Jsi_RC;

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        struct Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    int arrCnt;
    Jsi_Value **arr;
    union {
        struct {
            struct Jsi_FuncObj *fobj;
        } d;
    };
};

struct Jsi_Func {
    struct {
        int argCnt;
    } *argnames;
};

struct Jsi_FuncObj {
    struct Jsi_Func *func;
};

typedef unsigned int uint;

Jsi_RC Jsi_LogError(const char *msg);
int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *func);
Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int length);
void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp *interp, uint i);
Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, void *ptr, Jsi_Obj *obj);
Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp *interp, Jsi_Value **vobjs, int maa, int flags);
void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *vpargs);
Jsi_RC Jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *vpargs, Jsi_Value **ret, Jsi_Value *sthis);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *nthis);