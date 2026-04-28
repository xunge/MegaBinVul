#include <stddef.h>
#include <stdio.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_Regex Jsi_Regex;
typedef struct Jsi_Obj Jsi_Obj;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT,
    JSI_VT_NUMBER,
    JSI_VT_NULL
} Jsi_ValueType;

typedef enum Jsi_ObjType {
    JSI_OT_REGEXP,
    JSI_OT_NUMBER
} Jsi_ObjType;

typedef enum Jsi_RC {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

typedef double Jsi_Number;

#define JSI_REG_GLOB (1<<0)

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        Jsi_Obj *obj;
        double num;
    } d;
};

struct Jsi_Obj {
    Jsi_ObjType ot;
    union {
        Jsi_Regex *robj;
        double num;
    } d;
};

struct Jsi_Regex {
    int eflags;
    int lastIndex;
};

#define ChkRegexp(a,b,c) (void)(c)
#define Jsi_ValueString(a,b,c) NULL
#define Jsi_ValueArrayIndex(a,b,c) NULL
#define Jsi_LogError(a) JSI_ERROR
#define Jsi_ValueObjLookup(a,b,c,d) NULL
#define Jsi_ValueGetNumber(a,b,c) JSI_ERROR
#define jsi_RegExpMatches(a,b,c,d,e,f,g) JSI_ERROR
#define Jsi_ValueIsNull(a,b) 0
#define Jsi_ValueInsert(a,b,c,d,e) (void)0
#define Jsi_ValueNewNumber(a,b) NULL