#include <stdint.h>
#include <string.h>

typedef int Jsi_RC;
typedef unsigned int uint;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_String Jsi_String;
typedef struct Jsi_Obj Jsi_Obj;

#define JSI_VT_NUMBER 0
#define JSI_VT_OBJECT 0
#define JSI_OK 0
#define JSI_ERROR 1
#define JSI_HAS___PROTO__ 0

struct Jsi_Interp {
    uint maxArrayList;
};

struct Jsi_Value {
    int vt;
    union {
        double num;
        struct Jsi_Obj *obj;
    } d;
};

struct Jsi_String {
    const char *str;
};

struct Jsi_Obj {
    Jsi_Value *__proto__;
    Jsi_Value **arr;
};

static int Jsi_NumberIsInteger(double num);
static Jsi_String* jsi_ValueString(Jsi_Value *val);
static const char* Jsi_ValueToString(Jsi_Interp *interp, Jsi_Value *val, void *ptr);
static int Jsi_Strcmp(const char *s1, const char *s2);
static Jsi_Value* Jsi_ValueDup(Jsi_Interp *interp, Jsi_Value *val);
static int Jsi_ValueInsert(Jsi_Interp *interp, Jsi_Value *target, const char *key, Jsi_Value *val, int flag);
static void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *val);
static Jsi_RC jsi_ObjArraySetDup(Jsi_Interp *interp, Jsi_Obj *obj, Jsi_Value *val, int index);