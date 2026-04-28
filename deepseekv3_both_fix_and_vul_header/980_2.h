#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_String Jsi_String;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct jsi_OpCode jsi_OpCode;

typedef enum Jsi_RC {
    JSI_OK
} Jsi_RC;

typedef enum Jsi_ValueType {
    JSI_VT_UNDEF,
    JSI_VT_OBJECT,
    JSI_VT_STRING,
    JSI_VT_NUMBER,
    JSI_VT_VARIABLE
} Jsi_ValueType;

typedef enum Jsi_ObjType {
    JSI_OT_OBJECT,
    JSI_OT_NUMBER
} Jsi_ObjType;

#define JSI__UTF8 1
#define JSI_IS_UTF (1<<0)
#define JSI_UTF_CHECKED (1<<1)

struct Jsi_Value {
    Jsi_ValueType vt;
    union {
        double num;
        struct {
            struct Jsi_String *str;
        } s;
        struct Jsi_Obj *obj;
        struct Jsi_Value *lval;
    } d;
    struct {
        struct {
            unsigned int readonly : 1;
        } bits;
    } f;
};

struct Jsi_String {
    unsigned int flags;
};

struct Jsi_Obj {
    Jsi_ObjType ot;
    int freeze;
    int (*freezeReadCheck)(void);
};

struct Jsi_Interp {
    Jsi_Value *lastSubscriptFail;
    const char *lastSubscriptFailStr;
};

struct jsi_OpCode {
    void *data;
};

#define VALINIT {0}

typedef unsigned int uint;

static Jsi_String* jsi_ValueString(Jsi_Value*);
static int Jsi_ValueIsNumber(Jsi_Interp*, Jsi_Value*);
static char* Jsi_ValueString(Jsi_Interp*, Jsi_Value*, int*);
static int Jsi_NumUtfChars(char*, int);
static void Jsi_UtfGetIndex(char*, int, char*);
static void Jsi_ValueMakeUndef(Jsi_Interp*, Jsi_Value**);
static void Jsi_ValueMakeStringDup(Jsi_Interp*, Jsi_Value**, char*);
static void Jsi_ValueReset(Jsi_Interp*, Jsi_Value**);
static Jsi_RC Jsi_ValueToObject(Jsi_Interp*, Jsi_Value*);
static Jsi_Value* jsi_ValueSubscript(Jsi_Interp*, Jsi_Value*, Jsi_Value*, Jsi_Value**, uint);
static void Jsi_ValueDup2(Jsi_Interp*, Jsi_Value**, Jsi_Value*);
static const char* Jsi_ValueToString(Jsi_Interp*, Jsi_Value*, void*);
static int jsi_isDebugKey(const char*);
static Jsi_RC Jsi_LogError(const char*, ...);
static void Jsi_IncrRefCount(Jsi_Interp*, Jsi_Value*);
static void Jsi_ValueMove(Jsi_Interp*, Jsi_Value*, Jsi_Value*);
static void Jsi_ValueCopy(Jsi_Interp*, Jsi_Value*, Jsi_Value*);
static void Jsi_DecrRefCount(Jsi_Interp*, Jsi_Value*);