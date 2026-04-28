#include <stddef.h>

typedef enum {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_FObj Jsi_FObj;
typedef struct jsi_OpCodes jsi_OpCodes;
typedef jsi_OpCodes jsi_OpCode;

struct Jsi_Value {
    struct {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    struct {
        Jsi_FObj *fobj;
    } d;
};

struct Jsi_FObj {
    Jsi_Func *func;
};

struct Jsi_Func {
    jsi_OpCodes *opcodes;
};

struct jsi_OpCodes {
    void *codes;
};

struct Jsi_Interp {
    jsi_OpCodes *curIp;
};

int Jsi_InterpGone(Jsi_Interp *interp);
Jsi_RC jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *args, Jsi_Value **ret, Jsi_Value *_this);