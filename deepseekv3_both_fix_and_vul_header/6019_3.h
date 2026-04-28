#include <stdint.h>
#include <string.h>

typedef unsigned int uint;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;

#define JSI_VT_NUMBER 1
#define JSI_VT_OBJECT 2
#define JSI_OM_ISSTRKEY 1
#define MAX_ARRAY_LIST 1000

struct Jsi_Value {
    int vt;
    union {
        double num;
        struct Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_Value *__proto__;
    Jsi_Value **arr;
};

struct Jsi_Interp {
    unsigned int maxArrayList;
};

Jsi_Value* jsi_ObjArraySetDup(Jsi_Interp *interp, Jsi_Obj *obj, Jsi_Value *value, int index);
const char* Jsi_ValueToString(Jsi_Interp *interp, Jsi_Value *value, void *ptr);
int Jsi_NumberIsInteger(double num);
int Jsi_Strcmp(const char *s1, const char *s2);
Jsi_Value* Jsi_ValueDup(Jsi_Interp *interp, Jsi_Value *value);
Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp);
void Jsi_ValueCopy(Jsi_Interp *interp, Jsi_Value *dest, Jsi_Value *src);
void jsi_ValueObjSet(Jsi_Interp *interp, Jsi_Value *target, const char *key, Jsi_Value *value, int flag, int options);
int Jsi_ValueIsStringKey(Jsi_Interp *interp, Jsi_Value *key);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *value);