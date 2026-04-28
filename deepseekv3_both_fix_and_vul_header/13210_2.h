#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <stdint.h>

#define JSI_MAX_NUMBER_STRING 64
#define MAX_SUBREGEX 10
#define JSI_REG_GLOB 0x01
#define JSI_REG_NEWLINE 0x02

typedef uint8_t uchar;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_DString {
    char *str;
    int len;
    int maxlen;
} Jsi_DString;
typedef struct Jsi_Regex {
    regex_t reg;
    int eflags;
    char *pattern;
} Jsi_Regex;

typedef enum Jsi_RC {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

typedef enum Jsi_ValueType {
    JSI_VT_OBJECT,
    JSI_VT_NULL,
    JSI_VT_STRING
} Jsi_ValueType;

typedef enum Jsi_ObjType {
    JSI_OT_REGEXP,
    JSI_OT_FUNCTION
} Jsi_ObjType;

typedef struct Jsi_ArgNames {
    int argCnt;
} Jsi_ArgNames;

typedef struct Jsi_Func {
    Jsi_ArgNames *argnames;
} Jsi_Func;

typedef struct Jsi_Obj {
    Jsi_ObjType ot;
    union {
        struct {
            Jsi_Regex *robj;
        };
        struct {
            struct {
                struct {
                    Jsi_Func *func;
                } *fobj;
            };
        };
    } d;
} Jsi_Obj;

typedef struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        struct {
            Jsi_Obj *obj;
        } d;
    };
} Jsi_Value;

typedef struct Jsi_Interp {
    Jsi_Value *NullValue;
} Jsi_Interp;

static void ChkString(Jsi_Value *_this, Jsi_Func *funcPtr, const char *source_str, int *source_len, int *bLen) {}
static int skip = 0;
static char* jsi_SubstrDup(const char *p, int dummy, int rm_so, int rm_eo, int *olen) { return NULL; }

Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
int Jsi_ValueIsFunction(Jsi_Interp *interp, Jsi_Value *v);
const char* Jsi_ValueToString(Jsi_Interp *interp, Jsi_Value *v, int *len);
void Jsi_DSInit(Jsi_DString *dStr);
int Jsi_ValueIsString(Jsi_Interp *interp, Jsi_Value *v);
const char* Jsi_ValueString(Jsi_Interp *interp, Jsi_Value *v, int *len);
const char* Jsi_Strstr(const char *haystack, const char *needle);
void Jsi_ValueMakeStringDup(Jsi_Interp *interp, Jsi_Value **ret, const char *str);
void Jsi_DSAppendLen(Jsi_DString *dStr, const char *str, int len);
Jsi_Value* Jsi_ValueNewStringDup(Jsi_Interp *interp, const char *str);
void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *v);
Jsi_RC Jsi_FunctionInvokeString(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *arg, Jsi_DString *dStr);
int Jsi_InterpGone(Jsi_Interp *interp);
void Jsi_DSFree(Jsi_DString *dStr);
void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *v);
void Jsi_DSAppend(Jsi_DString *dStr, const char *str, const char *str2);
size_t Jsi_Strlen(const char *s);
void Jsi_ValueFromDS(Jsi_Interp *interp, Jsi_DString *dStr, Jsi_Value **ret);
void Jsi_ValueMakeNull(Jsi_Interp *interp, Jsi_Value **ret);
void Jsi_LogBug(const char *msg);
void Jsi_LogError(const char *fmt, ...);
const char* Jsi_Strchr(const char *s, int c);
Jsi_Value* Jsi_ValueMakeBlob(Jsi_Interp *interp, Jsi_Value *v, uchar *data, int len);
Jsi_Value* Jsi_ValueMakeNumber(Jsi_Interp *interp, Jsi_Value *v, double num);
Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, Jsi_Value *v, Jsi_Obj *obj);
Jsi_Obj* Jsi_ObjNewArray(Jsi_Interp *interp, Jsi_Value **items, int count, int flags);
Jsi_Value* Jsi_ValueNew1(Jsi_Interp *interp);
Jsi_RC Jsi_FunctionInvoke(Jsi_Interp *interp, Jsi_Value *func, Jsi_Value *args, Jsi_Value **ret, Jsi_Value *thisVal);