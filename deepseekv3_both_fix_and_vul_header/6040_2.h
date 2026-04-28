#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum {
    JSI_VT_OBJECT,
    JSI_VT_NUMBER,
    JSI_VT_STRING,
    JSI_VT_BOOL,
    JSI_VT_NULL,
    JSI_VT_UNDEFINED
} Jsi_ValueType;

typedef enum {
    JSI_OT_ARRAY,
    JSI_OT_OBJECT,
    JSI_OT_FUNCTION
} Jsi_ObjType;

typedef enum {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        struct Jsi_Obj *obj;
        double num;
        char *str;
        int boolean;
    } d;
};

struct Jsi_Obj {
    Jsi_ObjType type;
    int arrCnt;
    Jsi_Value **arr;
    struct {
        struct Jsi_Func *fobj;
    } d;
};

struct Jsi_Func {
    struct Jsi_Func *func;
    struct {
        int argCnt;
    } *argnames;
};

int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_LogError(const char *fmt, ...);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *val);
Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);
void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type);
int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int size);
void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp *interp, int num);
Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, void *ptr, Jsi_Obj *obj);
Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp *interp, Jsi_Value **vobjs, int count, int flags);
void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *val);
int Jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *args, Jsi_Value **ret, Jsi_Value *this);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *val);
int Jsi_ValueIsTrue(Jsi_Interp *interp, Jsi_Value *val);
void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **val);
void Jsi_ValueMakeNull(Jsi_Interp *interp, Jsi_Value **ret);