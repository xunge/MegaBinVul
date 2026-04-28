#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;
typedef int Jsi_RC;
#define JSI_OK 0

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;

enum Jsi_ValueType {
    JSI_VT_OBJECT
};

enum Jsi_ObjType {
    JSI_OT_STRING
};

struct Jsi_Obj {
    int ot;
    int isstrkey;
    union {
        struct {
            char *str;
            int len;
        } s;
    } d;
};

struct Jsi_Value {
    enum Jsi_ValueType vt;
    union {
        struct Jsi_Obj *obj;
    } d;
};

int Jsi_FunctionIsConstructor(Jsi_Func *funcPtr);
int Jsi_ValueGetLength(Jsi_Interp *interp, Jsi_Value *args);
Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
const char* Jsi_ValueToString(Jsi_Interp *interp, Jsi_Value *value, int *lenPtr);
char* Jsi_StrdupLen(const char *str, int len);
void Jsi_Free(void *ptr);
void jsi_ValueMakeBlobDup(Jsi_Interp *interp, Jsi_Value **value, uchar *data, int len);
void Jsi_ValueDup2(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Value *value);
void Jsi_ValueMakeStringDup(Jsi_Interp *interp, Jsi_Value **ret, const char *str);