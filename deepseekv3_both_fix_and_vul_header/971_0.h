#include <stddef.h>

typedef int Jsi_RC;
typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;
typedef double Jsi_Number;

#define JSI_OK 0
#define JSI_ERROR 1
#define JSI_VT_OBJECT 1

struct Jsi_Value {
    int vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    int modifying;
    Jsi_Value **arr;
};

static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
static Jsi_RC Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *number);
static int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ValueCopy(Jsi_Interp *interp, Jsi_Value *dst, Jsi_Value *src);
static Jsi_Value* Jsi_ValueDup(Jsi_Interp *interp, Jsi_Value *value);
static void Jsi_ValueMove(Jsi_Interp *interp, Jsi_Value **dst, Jsi_Value *src);
static Jsi_RC Jsi_LogError(const char *msg);