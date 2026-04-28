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

typedef int Jsi_RC;
#define JSI_OK 0
#define JSI_ERROR -1

typedef double Jsi_Number;

static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
static int Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *numPtr);
static void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj);
static Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type);
static int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
static int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int size);
static void Jsi_ValueDup2(Jsi_Interp *interp, Jsi_Value **dest, Jsi_Value *src);
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);
static void Jsi_ValueMakeNull(Jsi_Interp *interp, Jsi_Value **ret);
static Jsi_RC Jsi_LogError(const char *format, ...);

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_ObjType type;
    Jsi_Value **arr;
    // Add other members as needed
};