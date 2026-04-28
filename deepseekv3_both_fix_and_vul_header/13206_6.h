#include <stdint.h>
#include <stddef.h>

typedef unsigned int uint;

typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Interp {
    Jsi_Value *NullValue;
} Jsi_Interp;

typedef double Jsi_Number;

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
    FC_BUILDIN,
    FC_NORMAL
} Jsi_FuncType;

typedef struct Jsi_ArgNames {
    int argCnt;
} Jsi_ArgNames;

typedef struct Jsi_Func {
    Jsi_FuncType type;
    Jsi_ArgNames *argnames;
} Jsi_Func;

typedef struct Jsi_FuncObj {
    Jsi_Func *func;
} Jsi_FuncObj;

typedef struct Jsi_Obj {
    Jsi_Value **arr;
    uint arrCnt;
    struct {
        Jsi_FuncObj *fobj;
    } d;
} Jsi_Obj;

typedef struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
} Jsi_Value;

typedef int Jsi_RC;
#define JSI_OK 0

extern Jsi_RC Jsi_LogError(const char *msg);
extern int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
extern Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
extern int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *func);
extern Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp);
extern void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
extern Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp *interp, Jsi_Number num);
extern Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, const char *key, Jsi_Obj *obj);
extern Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp *interp, Jsi_Value **elems, int count, int flags);
extern void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *val);
extern Jsi_RC Jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *args, Jsi_Value **ret, Jsi_Value *thisVal);
extern void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *val);
extern int Jsi_ValueIsTrue(Jsi_Interp *interp, Jsi_Value *val);
extern void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **val);
extern void Jsi_ValueCopy(Jsi_Interp *interp, Jsi_Value *dst, Jsi_Value *src);
extern void Jsi_ValueMakeBool(Jsi_Interp *interp, Jsi_Value **ret, int val);
extern void Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Number num);