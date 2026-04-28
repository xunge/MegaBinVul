#include <stdlib.h>
#include <string.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Func Jsi_Func;

typedef enum {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef enum {
    JSI_OK
} Jsi_RC;

typedef struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        struct Jsi_Obj *obj;
    } d;
} Jsi_Value;

typedef struct Jsi_Obj {
    Jsi_Value **arr;
    int arrCnt;
} Jsi_Obj;

#define Jsi_LogError(msg) (0)
#define Jsi_LogBug(msg) (0)
#define Jsi_ObjIsArray(interp, obj) (1)
#define Jsi_ValueGetLength(interp, args) (0)
#define Jsi_ObjGetLength(interp, obj) (0)
#define Jsi_ObjSetLength(interp, obj, len) (0)
#define Jsi_ValueMakeNumber(interp, ret, num) (0)
#define Jsi_ObjListifyArray(interp, obj) (0)
#define Jsi_ObjArraySizer(interp, obj, len) (0)
#define Jsi_ValueArrayIndex(interp, args, idx) (NULL)
#define Jsi_IncrRefCount(interp, val) (0)