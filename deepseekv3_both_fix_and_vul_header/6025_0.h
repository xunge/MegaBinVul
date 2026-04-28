#include <string.h>
#include <stdlib.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_DString {
    char *str;
    int maxlen;
    int len;
} Jsi_DString;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef struct Jsi_Obj {
    int length;
} Jsi_Obj;

typedef struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
    } d;
} Jsi_Value;

typedef int Jsi_RC;
#define JSI_OK 0

int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_ObjGetLength(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_ValueGetLength(Jsi_Interp *interp, Jsi_Value *args);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
const char* Jsi_ValueToString(Jsi_Interp *interp, Jsi_Value *value, void *ptr);
void Jsi_DSAppend(Jsi_DString *dStr, const char *str, void *ptr);
char* Jsi_DSValue(Jsi_DString *dStr);
void Jsi_DSFree(Jsi_DString *dStr);
int Jsi_LogError(const char *format, ...);
int Jsi_ValueMakeStringDup(Jsi_Interp *interp, Jsi_Value **ret, const char *str);