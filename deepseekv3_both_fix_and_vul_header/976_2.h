#include <stddef.h>

#define JSI_VT_OBJECT 0
#define JSI_OK 0

typedef int Jsi_RC;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;

struct Jsi_Value {
    int vt;
    union {
        struct Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    int modifying;
    struct Jsi_Value **arr;
    int arrCnt;
};

static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, int num);
static int Jsi_LogError(const char *msg);
static int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **ret);
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *arr, int index);
static void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *v);
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);