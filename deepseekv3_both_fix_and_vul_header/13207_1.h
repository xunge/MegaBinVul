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
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

struct Jsi_Interp {
    Jsi_Value* NullValue;
};

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        struct Jsi_Obj* obj;
    } d;
};

struct Jsi_Obj {
    Jsi_Value** arr;
    int arrCnt;
    union {
        struct Jsi_FuncObj* fobj;
    } d;
};

struct Jsi_FuncObj {
    Jsi_Func* func;
};

struct Jsi_Func {
    struct {
        int argCnt;
    } *argnames;
    int type;
};

#define FC_BUILDIN 0

static Jsi_RC Jsi_LogError(const char* msg) { return JSI_ERROR; }
static int Jsi_ObjIsArray(Jsi_Interp* interp, Jsi_Obj* obj) { return 1; }
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp* interp, Jsi_Value* args, int index) { return NULL; }
static int Jsi_ValueIsFunction(Jsi_Interp* interp, Jsi_Value* val) { return 1; }
static Jsi_Value* Jsi_ValueNew1(Jsi_Interp* interp) { return NULL; }
static void Jsi_ObjListifyArray(Jsi_Interp* interp, Jsi_Obj* obj) {}
static Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp* interp, int num) { return NULL; }
static Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp* interp, void* unused, Jsi_Obj* obj) { return NULL; }
static Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp* interp, Jsi_Value** vals, int cnt, int unused) { return NULL; }
static void Jsi_IncrRefCount(Jsi_Interp* interp, Jsi_Value* val) {}
static Jsi_RC Jsi_FunctionInvoke(Jsi_Interp* interp, Jsi_Value* func, Jsi_Value* args, Jsi_Value** ret, void* unused) { return JSI_OK; }
static void Jsi_DecrRefCount(Jsi_Interp* interp, Jsi_Value* val) {}
static void Jsi_ValueCopy(Jsi_Interp* interp, Jsi_Value* dest, Jsi_Value* src) {}