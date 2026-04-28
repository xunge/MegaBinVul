#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum {
    JSI_VT_OBJECT,
    JSI_VT_NULL,
    JSI_VT_UNDEFINED,
    JSI_VT_BOOL,
    JSI_VT_NUMBER,
    JSI_VT_STRING,
    JSI_VT_FUNC
} Jsi_ValueType;

typedef enum {
    JSI_OT_ARRAY,
    JSI_OT_OBJECT,
    JSI_OT_FUNCTION
} Jsi_ObjType;

struct Jsi_Obj {
    Jsi_ObjType type;
    int arrCnt;
    Jsi_Value **arr;
    struct {
        struct {
            Jsi_Func *func;
        } *fobj;
    } d;
};

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
        double num;
        int b;
    } d;
};

struct Jsi_Func {
    Jsi_Func *func;
    struct {
        int argCnt;
    } *argnames;
};

typedef int Jsi_RC;
#define JSI_OK 0
#define JSI_ERROR 1

int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_RC Jsi_LogError(const char *format, ...);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *value);
Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int length);
void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type);
int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int size);
void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj);
Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp *interp, Jsi_Value **values, int count, int flags);
Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp *interp, double num);
Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj);
void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *value);
Jsi_RC Jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *args, Jsi_Value **ret, Jsi_Value *thisVal);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *value);
void Jsi_ValueMakeNull(Jsi_Interp *interp, Jsi_Value **ret);