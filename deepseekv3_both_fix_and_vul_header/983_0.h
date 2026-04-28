#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;
typedef double Jsi_Number;

typedef enum {
    JSI_VT_BOOL,
    JSI_VT_NULL,
    JSI_VT_OBJECT,
    JSI_VT_UNDEF,
    JSI_VT_NUMBER,
    JSI_VT_STRING
} Jsi_ValueType;

typedef enum {
    JSI_OT_BOOL,
    JSI_OT_NUMBER,
    JSI_OT_STRING
} Jsi_ObjType;

typedef enum {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        int val;
        double num;
        struct {
            char *str;
        } s;
        Jsi_Obj *obj;
    } d;
};

struct Jsi_Obj {
    Jsi_ObjType ot;
    union {
        int val;
        double num;
        struct {
            char *str;
        } s;
    } d;
};

struct Jsi_Interp {
    Jsi_Value *NaNValue;
};

Jsi_Number Jsi_NumberNaN(void);
int Jsi_NumberIsNormal(Jsi_Number n);
int Jsi_LogError(const char *fmt, ...);