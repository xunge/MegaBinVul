#include <stddef.h>
#include <math.h>
#include <string.h>

#define JSI_MAX_NUMBER_STRING 64

typedef double Jsi_Number;
typedef long long Jsi_Wide;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;

struct Jsi_Interp {
    int logMsgDepth;
};

struct Jsi_Value {
    int vt;
    union {
        struct {
            char *str;
        } s;
        int val;
        double num;
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    int ot;
    union {
        struct {
            char *str;
        } s;
        int val;
        double num;
    } d;
};

enum {
    JSI_VT_UNDEF,
    JSI_VT_NULL,
    JSI_VT_BOOL,
    JSI_VT_NUMBER,
    JSI_VT_STRING,
    JSI_VT_OBJECT
};

enum {
    JSI_OT_STRING,
    JSI_OT_BOOL,
    JSI_OT_NUMBER
};

extern char* jsi_KeyFind(Jsi_Interp *interp, const char *ntxt, int flag, int *isKey);
extern void Jsi_ValueReset(Jsi_Interp *interp, Jsi_Value **v);
extern void Jsi_ValueMakeStringDup(Jsi_Interp *interp, Jsi_Value **v, const char *s);
extern const char* Jsi_ValueString(Jsi_Interp *interp, Jsi_Value *v, int *lenPtr);
extern void Jsi_ValueMakeStringKey(Jsi_Interp *interp, Jsi_Value **v, char *key);
extern void Jsi_ValueMakeString(Jsi_Interp *interp, Jsi_Value **v, const char *s);
extern void Jsi_LogBug(const char *fmt, ...);
extern size_t Jsi_Strlen(const char *s);
extern int Jsi_NumberIsInteger(Jsi_Number n);
extern int Jsi_NumberIsNormal(Jsi_Number n);
extern int Jsi_NumberIsNaN(Jsi_Number n);
extern int Jsi_NumberIsInfinity(Jsi_Number n);
extern void Jsi_NumberItoA10(Jsi_Wide n, char *buf, size_t len);
extern void Jsi_NumberDtoA(Jsi_Interp *interp, Jsi_Number n, char *buf, size_t len, int flags);