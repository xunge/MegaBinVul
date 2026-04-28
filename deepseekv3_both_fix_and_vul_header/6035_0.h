#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum {
    JSI_VT_OBJECT,
    // Add other enum values as needed
} Jsi_ValueType;

typedef enum {
    JSI_OT_ARRAY,
    // Add other enum values as needed
} Jsi_ObjType;

typedef enum {
    JSI_OK,
    JSI_ERROR
    // Add other enum values as needed
} Jsi_RC;

typedef double Jsi_Number;

static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
static int Jsi_ValueGetLength(Jsi_Interp *interp, Jsi_Value *args);
static int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type);
static void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj);
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);
static Jsi_RC Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *num);
static void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
static int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int newlen);
static void Jsi_ValueDup2(Jsi_Interp *interp, Jsi_Value **dest, Jsi_Value *src);
static void Jsi_ValueMakeUndef(Jsi_Interp *interp, Jsi_Value **ret);
static void Jsi_ValueMakeNull(Jsi_Interp *interp, Jsi_Value **ret);
static Jsi_RC Jsi_LogError(const char *msg);

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_Value **arr;
    // Add other members as needed
};