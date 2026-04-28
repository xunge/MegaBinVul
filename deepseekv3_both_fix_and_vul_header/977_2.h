#include <stdint.h>
#include <string.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef int Jsi_RC;
#define JSI_OK 0

typedef unsigned int uint;

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_Value **arr;
    int modifying;
};

static int Jsi_LogError(const char *msg);
static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
static uint jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **ret);
static void Jsi_ValueDup2(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Value *v);
static void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *v);
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, uint n);