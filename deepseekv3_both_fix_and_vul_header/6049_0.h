#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_OpCodes Jsi_OpCodes;
typedef struct Jsi_ScopeStrs Jsi_ScopeStrs;
typedef struct jsi_Pstate jsi_Pstate;
typedef struct jsi_Pline jsi_Pline;
typedef struct jsi_Lexer jsi_Lexer;
typedef enum Jsi_otype Jsi_otype;

enum Jsi_otype {
    JSI_TT_UNDEFINED,
    JSI_TT_VOID
};

#define FC_NORMAL 0
#define LT_STRING 0
#define OP_RET 0
#define OP_NOP 0

struct Jsi_ScopeStrs {
    int count;
    struct {
        char *name;
    } *args;
    int retType;
};

struct Jsi_OpCodes {
    int code_len;
    struct {
        int op;
    } *codes;
};

struct jsi_Pstate {
    Jsi_Interp *interp;
    jsi_Lexer *lexer;
    int eval_flag;
    int argType;
    int err_count;
};

struct jsi_Pline {
    int first_line;
};

struct jsi_Lexer {
    int ltype;
    union {
        char *str;
    } d;
    int cur;
};

struct Jsi_Interp {
    char *curFile;
    int strict;
    struct {
        int run;
        int parse;
        int all;
        int funcsig;
    } typeCheck;
    void *staticFuncsTbl;
    jsi_Pline *parseLine;
};

struct Jsi_Func {
    int isArrow;
    int type;
    Jsi_OpCodes *opcodes;
    Jsi_ScopeStrs *argnames;
    Jsi_ScopeStrs *localnames;
    char *script;
    jsi_Pline bodyline;
    Jsi_otype retType;
    char *scriptFile;
    char *bodyStr;
    int endPos;
    int startPos;
    char *name;
};

char* Jsi_KeyAdd(Jsi_Interp *interp, const char *name);
Jsi_Func* jsi_FuncNew(Jsi_Interp *interp);
Jsi_ScopeStrs* jsi_ScopeGetVarlist(jsi_Pstate *pstate);
int Jsi_Strcmp(const char *s1, const char *s2);
void Jsi_LogWarn(const char *fmt, ...);
void Jsi_LogError(const char *fmt, ...);
int jsi_FuncSigsMatch(jsi_Pstate *pstate, Jsi_Func *f1, Jsi_Func *f2);
void jsi_TypeMismatch(Jsi_Interp *interp);