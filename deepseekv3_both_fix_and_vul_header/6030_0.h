#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT,
    JSI_VT_NULL
} Jsi_ValueType;

typedef enum Jsi_ObjType {
    JSI_OT_ARRAY
} Jsi_ObjType;

typedef enum Jsi_RC {
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
    int arrMaxSize;
    Jsi_Value **arr;
};

Jsi_RC Jsi_LogError(const char *format, ...);
int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_ValueGetLength(Jsi_Interp *interp, Jsi_Value *args);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int len);
void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, Jsi_ObjType type);
int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int size);
void Jsi_ValueDup2(Jsi_Interp *interp, Jsi_Value **dest, Jsi_Value *src);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
void Jsi_ValueMakeArrayObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *obj);
void Jsi_ValueMakeNull(Jsi_Interp *interp, Jsi_Value **ret);