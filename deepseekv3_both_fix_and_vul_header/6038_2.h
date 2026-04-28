#include <stdint.h>
#include <string.h>
#include <assert.h>

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
    uint32_t arrCnt;
    Jsi_Value **arr;
} Jsi_Obj;

typedef unsigned int uint;

#define Jsi_LogError(msg) (0)
#define Jsi_ObjIsArray(interp, obj) (0)
#define Jsi_ObjListifyArray(interp, obj)
#define Jsi_ObjGetLength(interp, obj) (0)
#define Jsi_ValueMakeUndef(interp, ret)
#define Jsi_ValueDup2(interp, ret, v)
#define Jsi_DecrRefCount(interp, v)
#define Jsi_ObjSetLength(interp, obj, n)