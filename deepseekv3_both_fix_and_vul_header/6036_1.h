#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef enum Jsi_RC {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        struct Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_Value **arr;
    int arrCnt;
    struct {
        struct {
            Jsi_Func *func;
        } *fobj;
    } d;
};

struct Jsi_Func {
    struct {
        int argCnt;
    } *argnames;
};

static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_RC Jsi_LogError(const char *msg);
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
static int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *func);
static Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp);
static int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);
static void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp *interp, double num);
static Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, void *ptr, Jsi_Obj *obj);
static Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp *interp, Jsi_Value **items, int count, int flags);
static void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *val);
static Jsi_RC Jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *args, Jsi_Value **ret, void *ptr);
static void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *val);
static void Jsi_ValueCopy(Jsi_Interp *interp, Jsi_Value *dest, Jsi_Value *src);