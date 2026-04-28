#include <string.h>

typedef int Jsi_RC;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_Regex Jsi_Regex;
typedef struct Jsi_DString {
    char *str;
    int len;
    int maxlen;
} Jsi_DString;

enum Jsi_ValueType {
    JSI_VT_OBJECT
};

enum Jsi_ObjType {
    JSI_OT_REGEXP
};

struct Jsi_Value {
    int vt;
    union {
        struct Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    int ot;
    union {
        Jsi_Regex *robj;
    } d;
};

#define JSI_OK 0
#define JSI_ERROR 1

int Jsi_FunctionIsConstructor(Jsi_Func *funcPtr);
Jsi_Obj* Jsi_ObjNewType(Jsi_Interp *interp, int type);
void Jsi_ValueMakeObject(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Obj *o);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
const char* Jsi_ValueString(Jsi_Interp *interp, Jsi_Value *v, void *ptr);
void Jsi_ValueCopy(Jsi_Interp *interp, Jsi_Value *target, Jsi_Value *v);
void Jsi_DSAppend(Jsi_DString *dStr, const char *str, ...);
char* Jsi_DSValue(Jsi_DString *dStr);
void Jsi_DSFree(Jsi_DString *dStr);
Jsi_Regex* Jsi_RegExpNew(Jsi_Interp *interp, const char *pattern, int flags);