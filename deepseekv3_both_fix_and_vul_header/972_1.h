#include <stddef.h>

typedef int Jsi_RC;
#define JSI_OK 0
#define JSI_VT_OBJECT 1

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Func Jsi_Func;

typedef struct Jsi_Value {
    int vt;
    union {
        struct Jsi_Obj *obj;
    } d;
} Jsi_Value;

typedef struct Jsi_Obj {
    int modifying;
} Jsi_Obj;

int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, int num);
int Jsi_ValueGetLength(Jsi_Interp *interp, Jsi_Value *args);
int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
void Jsi_LogBug(const char *msg);
Jsi_Value* Jsi_ValueNew(Jsi_Interp *interp);
void Jsi_ValueInsertArray(Jsi_Interp *interp, Jsi_Value *_this, int index, Jsi_Value *ov, int flags);
int Jsi_LogError(const char *msg);