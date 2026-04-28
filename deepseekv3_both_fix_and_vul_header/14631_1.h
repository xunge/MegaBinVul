#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef int Jsi_RC;
#define JSI_OK 0

typedef double Jsi_Number;

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
};

Jsi_RC Jsi_LogError(const char *msg);
int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
Jsi_RC Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *number);
int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ValueCopy(Jsi_Interp *interp, Jsi_Value *dst, Jsi_Value *src);
Jsi_Value* Jsi_ValueDup(Jsi_Interp *interp, Jsi_Value *value);
void Jsi_ValueMove(Jsi_Interp *interp, Jsi_Value **dst, Jsi_Value *src);

struct Jsi_Obj {
    Jsi_Value **arr;
};