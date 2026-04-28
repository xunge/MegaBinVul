#include <stddef.h>

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

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_Value **arr;
};

Jsi_RC Jsi_LogError(const char *msg);
int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
Jsi_RC Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *number);
int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ValueCopy(Jsi_Interp *interp, Jsi_Value *dst, Jsi_Value *src);
Jsi_Value* Jsi_ValueDup(Jsi_Interp *interp, Jsi_Value *value);
void Jsi_ValueMove(Jsi_Interp *interp, Jsi_Value **dst, Jsi_Value *src);