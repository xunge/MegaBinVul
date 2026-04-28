#include <stdint.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef enum Jsi_RC {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

typedef double Jsi_Number;

#define JSI_CMP_EXACT 0

Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_LogError(const char *format, ...);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *numberPtr);
void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_ValueCmp(Jsi_Interp *interp, Jsi_Value *v1, Jsi_Value *v2, int flags);
void Jsi_ValueMakeBool(Jsi_Interp *interp, Jsi_Value **ret, int boolVal);
void Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Number num);

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    uint32_t arrCnt;
    Jsi_Value **arr;
};