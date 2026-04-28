#include <stdlib.h>
#include <string.h>

typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Interp Jsi_Interp;

typedef enum {
    JSI_VT_UNDEF,
    JSI_VT_NULL,
    JSI_VT_BOOL,
    JSI_VT_NUMBER,
    JSI_VT_STRING,
    JSI_VT_OBJECT,
    JSI_VT_FUNC
} Jsi_ValueType;

typedef enum {
    JSI_OT_OBJECT,
    JSI_OT_ARRAY,
    JSI_OT_FUNCTION
} Jsi_ObjType;

typedef enum {
    FC_BUILDIN,
    FC_USER
} Jsi_FuncType;

typedef struct Jsi_ArgNames {
    int argCnt;
    char **argnames;
} Jsi_ArgNames;

typedef struct Jsi_Func {
    Jsi_FuncType type;
    Jsi_ArgNames *argnames;
} Jsi_Func;

typedef struct Jsi_Obj {
    int arrCnt;
    Jsi_ValueType vt;
    Jsi_Value **arr;
    union {
        struct Jsi_FuncObj *fobj;
    } d;
} Jsi_Obj;

typedef struct Jsi_FuncObj {
    Jsi_Func *func;
} Jsi_FuncObj;

typedef struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
} Jsi_Value;

typedef struct Jsi_Interp {
    Jsi_Value *NullValue;
} Jsi_Interp;

typedef int Jsi_RC;
#define JSI_OK 0
#define JSI_ERROR 1

static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj) { return 0; }
static int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *val) { return 0; }
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index) { return NULL; }
static Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp) { return NULL; }
static int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj) { return 0; }
static void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj) {}
static Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type) { return NULL; }
static int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int size) { return 0; }
static void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj) {}
static Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp *interp, double num) { return NULL; }
static Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, Jsi_Value **target, Jsi_Obj *obj) { return NULL; }
static Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp *interp, Jsi_Value **elems, int count, int flags) { return NULL; }
static void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *val) {}
static void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *val) {}
static int Jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *args, Jsi_Value **ret, Jsi_Value *thisVal) { return 0; }
static int Jsi_ValueIsTrue(Jsi_Interp *interp, Jsi_Value *val) { return 0; }
static void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **val) {}
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len) {}
static void Jsi_ValueMakeNull(Jsi_Interp *interp, Jsi_Value **val) {}
static int Jsi_LogError(const char *fmt, ...) { return 0; }