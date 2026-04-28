#include <string.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef enum {
    JSI_OK
} Jsi_RC;

#define Jsi_LogError(msg) 0
#define Jsi_LogBug(msg) 0
#define Jsi_ValueGetLength(interp, args) 0
#define jsi_SizeOfArray(interp, obj) 0
#define Jsi_ValueMakeNumber(interp, ret, num) 
#define Jsi_ObjIsArray(interp, obj) 0
#define Jsi_ObjListifyArray(interp, obj) 
#define Jsi_ObjArraySizer(interp, obj, size) 0
#define Jsi_ValueArrayIndex(interp, args, idx) NULL
#define Jsi_IncrRefCount(interp, val) 
#define Jsi_ObjSetLength(interp, obj, len) 

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    int modifying;
    Jsi_Value **arr;
    int arrCnt;
};