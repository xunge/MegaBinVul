#include <stdint.h>
#include <stddef.h>

typedef unsigned int uint;
typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_FuncObj Jsi_FuncObj;
typedef int Jsi_RC;

#define JSI_VT_OBJECT 1
#define JSI_OK 0
#define FC_BUILDIN 1

struct Jsi_Value {
    int vt;
    union {
        struct Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_Value **arr;
    uint arrCnt;
    struct {
        struct Jsi_FuncObj *fobj;
    } d;
};

struct Jsi_Func {
    struct {
        int argCnt;
    } *argnames;
    int type;
};

struct Jsi_FuncObj {
    struct Jsi_Func *func;
};

struct Jsi_Interp {
    Jsi_Value *NullValue;
};

int Jsi_ObjIsArray(Jsi_Interp*, Jsi_Obj*);
Jsi_RC Jsi_LogError(const char*);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp*, Jsi_Value*, int);
int Jsi_ValueIsFunction(Jsi_Interp*, Jsi_Value*);
Jsi_Value* Jsi_ValueNew1(Jsi_Interp*);
void Jsi_ObjListifyArray(Jsi_Interp*, Jsi_Obj*);
Jsi_Value* Jsi_ValueNewNumber(Jsi_Interp*, uint);
Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp*, void*, Jsi_Obj*);
Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp*, Jsi_Value**, int, int);
void Jsi_IncrRefCount(Jsi_Interp*, Jsi_Value*);
Jsi_RC Jsi_FunctionInvoke(Jsi_Interp*, Jsi_Value*, Jsi_Value*, Jsi_Value**, Jsi_Value*);
void Jsi_DecrRefCount(Jsi_Interp*, Jsi_Value*);