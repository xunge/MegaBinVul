#include <stddef.h>
#include <stdint.h>

typedef struct Jsi_Interp {
    int strict;
    int maxArrayList;
} Jsi_Interp;

typedef struct Jsi_Value {
    int vt;
    union {
        struct Jsi_Obj *obj;
    } d;
} Jsi_Value;

typedef struct Jsi_Obj {
    int isarrlist;
} Jsi_Obj;

typedef int Jsi_RC;

#define JSI_VT_OBJECT 0
#define JSI_ERROR 1
#define JSI_OK 0
#define JSI_MAX_NUMBER_STRING 32

void Jsi_LogWarn(const char *msg);
void Jsi_ObjArraySet(Jsi_Interp *interp, Jsi_Obj *obj, Jsi_Value *val, int key);
void Jsi_ObjInsert(Jsi_Interp *interp, Jsi_Obj *obj, const char *key, Jsi_Value *val, int flags);
void Jsi_NumberItoA10(int num, char *buf, size_t bufSize);

typedef unsigned int uint;