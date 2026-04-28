#include <stddef.h>
#include <stdarg.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Func Jsi_Func;

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
    // Add other enum values as needed
} Jsi_RC;

typedef double Jsi_Number;

typedef struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        struct Jsi_Obj *obj;
        // Add other union members as needed
    } d;
    // Add other struct members as needed
} Jsi_Value;

typedef struct Jsi_Obj {
    Jsi_ObjType type;
    size_t arrCnt;
    Jsi_Value **arr;
    // Add other struct members as needed
} Jsi_Obj;

static int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
static int Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *num);
static int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int size);
static void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj);
static void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
static void Jsi_ValueDup2(Jsi_Interp *interp, Jsi_Value **dest, Jsi_Value *src);
static void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);
static int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
static Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type);
static Jsi_RC Jsi_LogError(const char *format, ...);