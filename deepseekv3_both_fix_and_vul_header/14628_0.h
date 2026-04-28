#include <stdlib.h>
#include <stdio.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;
typedef double Jsi_Number;

typedef enum {
    JSI_VT_OBJECT,
    JSI_VT_NULL
} Jsi_ValueType;

typedef enum {
    JSI_OT_ARRAY
} Jsi_ObjType;

typedef enum {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

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
};

static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
static int Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *number);
static Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type);
static void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj);
static int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
static int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int size);
static void Jsi_ValueDup2(Jsi_Interp *interp, Jsi_Value **dest, Jsi_Value *src);
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int length);
static Jsi_RC Jsi_LogError(const char *format, ...);