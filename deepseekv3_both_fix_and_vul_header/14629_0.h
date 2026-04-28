#include <stdint.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum {
    JSI_VT_OBJECT,
    // Add other enum values as needed
} Jsi_ValueType;

typedef enum {
    JSI_OK,
    JSI_ERROR,
    // Add other enum values as needed
} Jsi_RC;

typedef enum {
    JSI_CMP_EXACT,
    // Add other enum values as needed
} Jsi_CmpFlags;

typedef double Jsi_Number;

#define JSI_OK 0
#define JSI_ERROR 1

Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_LogError(const char *format, ...);
int jsi_SizeOfArray(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_GetNumberFromValue(Jsi_Interp *interp, Jsi_Value *value, Jsi_Number *numberPtr);
void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
int Jsi_ValueCmp(Jsi_Interp *interp, Jsi_Value *v1, Jsi_Value *v2, Jsi_CmpFlags flags);
void Jsi_ValueMakeBool(Jsi_Interp *interp, Jsi_Value **ret, int boolVal);
void Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Number num);

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
        // Add other union members as needed
    } d;
};

struct Jsi_Obj {
    uint32_t arrCnt;
    Jsi_Value **arr;
    // Add other members as needed
};