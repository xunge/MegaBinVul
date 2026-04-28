#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <sys/types.h>

#define JSI_MAX_ALLOC_BUF (1<<24)
#define JSI_MAX_NUMBER_STRING 64
#define MAX_SUBREGEX 10
#define JSI_OK 0
#define JSI_ERROR -1
#define JSI_VT_OBJECT 1
#define JSI_OT_REGEXP 2
#define JSI_REG_GLOB 1
#define JSI_REG_NEWLINE 2

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_DString Jsi_DString;
typedef struct Jsi_Regex Jsi_Regex;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_FuncObj Jsi_FuncObj;
typedef struct Jsi_ArgNames Jsi_ArgNames;

typedef int Jsi_RC;
typedef unsigned char uchar;

struct Jsi_DString {
    char *str;
    int len;
    int maxlen;
};

struct Jsi_Regex {
    regex_t reg;
    int eflags;
    char *pattern;
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
        struct Jsi_Regex *robj;
        struct Jsi_FuncObj *fobj;
    } d;
};

struct Jsi_FuncObj {
    Jsi_Func *func;
};

struct Jsi_Func {
    Jsi_ArgNames *argnames;
};

struct Jsi_ArgNames {
    int argCnt;
};

struct Jsi_Interp {
    Jsi_Value *NullValue;
};

static int skip = 0;