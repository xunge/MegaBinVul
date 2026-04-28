#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_Value Jsi_Value;

#define JSI_OK 0
#define JSI_ERROR 1
#define JSI_VT_OBJECT 1

struct Jsi_Obj {
    Jsi_Value **arr;
    int arrCnt;
    int arrMaxSize;
};

struct Jsi_Value {
    int vt;
};

typedef int Jsi_RC;

void Assert(int condition);
int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int n);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *value);
void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *value);
void jsi_ObjInsertObjCheck(Jsi_Interp *interp, Jsi_Obj *obj, Jsi_Value *value, int flag);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
void Jsi_ObjSetLength(Jsi_Interp *interp, Jsi_Obj *obj, int length);