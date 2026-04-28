#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;

typedef double Jsi_Number;
typedef int Jsi_RC;

#define JSI_OK 0
#define JSI_OT_NUMBER 1

struct Jsi_Value {
    union {
        Jsi_Number num;
        struct {
            int ot;
            union {
                Jsi_Number num;
            } d;
        } *obj;
    } d;
};

Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
int Jsi_ValueToNumber(Jsi_Interp *interp, Jsi_Value *v);
int Jsi_ValueToObject(Jsi_Interp *interp, Jsi_Value *v);
int Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Number n);
int Jsi_ValueDup2(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Value *v);
int Jsi_FunctionIsConstructor(Jsi_Func *funcPtr);