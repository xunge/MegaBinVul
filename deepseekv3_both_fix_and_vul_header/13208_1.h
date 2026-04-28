#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_Func Jsi_Func;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef enum Jsi_ObjType {
    JSI_OT_ARRAY
} Jsi_ObjType;

typedef enum Jsi_RC {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

typedef enum Jsi_FuncType {
    FC_BUILDIN
} Jsi_FuncType;

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_ObjType type;
    int arrCnt;
    Jsi_Value **arr;
    struct {
        struct {
            Jsi_Func *func;
        } *fobj;
    } d;
    struct {
        int argCnt;
    } *argnames;
};

struct Jsi_Func {
    Jsi_FuncType type;
    struct {
        int argCnt;
    } *argnames;
};

struct Jsi_Interp {
    Jsi_Value *NullValue;
};

static int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj) { return 0; }
static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj) { return 0; }
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index) { return NULL; }
static int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *func) { return 0; }
static Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp) { return NULL; }
static void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj) {}
static Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type) { return NULL; }
static int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int size) { return 0; }
static void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj) {}
static Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp *interp, Jsi_Value **items, int count, int flags) { return NULL; }
static void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *val) {}
static Jsi_RC Jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *args, Jsi_Value **ret, Jsi_Value *thisVal) { return JSI_OK; }
static void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *val) {}
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len) {}
static void Jsi_ValueMakeNull(Jsi_Interp *interp, Jsi_Value **ret) {}
static Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp *interp, double num) { return NULL; }
static Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, const char *key, Jsi_Obj *obj) { return NULL; }
static Jsi_RC Jsi_LogError(const char *format, ...) { return JSI_ERROR; }