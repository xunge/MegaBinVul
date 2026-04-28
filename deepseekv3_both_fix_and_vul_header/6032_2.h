#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Func Jsi_Func;

typedef enum {
    JSI_VT_OBJECT
} Jsi_ValueType;

typedef struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        struct {
            void *obj;
        } d;
    };
} Jsi_Value;

typedef int Jsi_RC;
#define JSI_OK 0

int Jsi_ObjGetLength(Jsi_Interp *interp, void *obj);
int Jsi_ObjIsArray(Jsi_Interp *interp, void *obj);
int Jsi_LogError(const char *msg);
void Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value **ret, int num);