#include <stddef.h>

typedef struct Jsi_Interp {
    int maxArrayList;
} Jsi_Interp;

typedef struct Jsi_Obj {
    // Placeholder for object structure
} Jsi_Obj;

typedef struct Jsi_Value {
    struct {
        Jsi_Obj* obj;
    } d;
} Jsi_Value;

typedef int Jsi_RC;

#define JSI_OK 0

int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj* obj);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *arr, int i);
int Jsi_ValueIsArray(Jsi_Interp *interp, Jsi_Value *t);
int Jsi_ValueIsUndef(Jsi_Interp *interp, Jsi_Value *t);
void Jsi_ObjArrayAdd(Jsi_Interp *interp, Jsi_Obj* nobj, Jsi_Value *t);
Jsi_RC Jsi_LogError(const char *msg);