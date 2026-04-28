#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define jsi_callTraceFuncs 0x1
#define jsi_callTraceCmds 0x2
#define jsi_callTraceReturn 0x4

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_FObj Jsi_FObj;
typedef struct Jsi_CmdSpec Jsi_CmdSpec;
typedef struct Jsi_Pkg Jsi_Pkg;

typedef enum Jsi_RC {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef enum Jsi_FuncType {
    FC_BUILDIN,
    FC_NORMAL
} Jsi_FuncType;

#define SIGASSERT(ptr, type)

struct Jsi_Value {
    Jsi_ValueType vt;
    struct {
        struct Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    struct {
        struct Jsi_FObj *fobj;
    } d;
};

struct Jsi_FObj {
    Jsi_Func *func;
    void *scope;
};

struct Jsi_Func {
    Jsi_FuncType type;
    Jsi_CmdSpec *cmdSpec;
    int callCnt;
    char *name;
    void *opcodes;
    void *retType;
    Jsi_Pkg *pkg;
    Jsi_RC (*callback)(Jsi_Interp*, Jsi_Value*, Jsi_Value*, Jsi_Value**, Jsi_Func*);
};

struct Jsi_Interp {
    int maxDepth;
    int callDepth;
    bool deleting;
    Jsi_Value *nullFuncRet;
    Jsi_Value *nullFuncArg;
    Jsi_Func *activeFunc;
    int traceCall;
    void *ps;
};

struct Jsi_CmdSpec {
    int minArgs;
};

struct Jsi_Pkg {
    struct {
        struct {
            int traceCall;
        } modConf;
    } popts;
};

Jsi_RC Jsi_LogError(const char *fmt, ...);
int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *value);
Jsi_Value* Jsi_ValueNew(Jsi_Interp *interp);
void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *value);
void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **ret);
Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, void *obj, void *array);
void* Jsi_ObjNewArray(Jsi_Interp *interp, void *obj, int size, int flags);
int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueDup(Jsi_Interp *interp, Jsi_Value *value);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *value);
int Jsi_ValueGetLength(Jsi_Interp *interp, Jsi_Value *value);
Jsi_RC jsi_SharedArgs(Jsi_Interp *interp, Jsi_Value *args, Jsi_Func *funcPtr, int flag);
void jsi_InitLocalVar(Jsi_Interp *interp, Jsi_Value *args, Jsi_Func *funcPtr);
void jsi_SetCallee(Jsi_Interp *interp, Jsi_Value *args, Jsi_Value *tocall);
void jsi_TraceFuncCall(Jsi_Interp *interp, Jsi_Func *funcPtr, void *arg1, Jsi_Value *fthis, Jsi_Value *args, Jsi_Value *ret, int tc);
Jsi_RC jsi_evalcode(void *ps, Jsi_Func *funcPtr, void *opcodes, void *scope, Jsi_Value *args, Jsi_Value *fthis, Jsi_Value **ret);
Jsi_RC jsi_ArgTypeCheck(Jsi_Interp *interp, void *retType, Jsi_Value *ret, const char *msg, char *name, int argnum, Jsi_Func *funcPtr, int isarg);