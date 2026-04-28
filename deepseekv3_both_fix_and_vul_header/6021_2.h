#include <stdint.h>

typedef struct Jsi_Interp {
    uint32_t maxArrayList;
} Jsi_Interp;

typedef struct Jsi_Obj Jsi_Obj;

typedef struct Jsi_Value {
    union {
        Jsi_Obj *obj;
    } d;
} Jsi_Value;

typedef enum Jsi_RC {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

typedef unsigned int uint;

int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *arr, int index);
int Jsi_ValueIsArray(Jsi_Interp *interp, Jsi_Value *v);
int Jsi_ValueIsUndef(Jsi_Interp *interp, Jsi_Value *v);
void Jsi_ObjArrayAdd(Jsi_Interp *interp, Jsi_Obj *obj, Jsi_Value *v);
int Jsi_LogError(const char *msg);