#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_OpCodes Jsi_OpCodes;
typedef struct Jsi_ScopeStrs Jsi_ScopeStrs;
typedef struct Jsi_Func Jsi_Func;
typedef struct jsi_Pstate jsi_Pstate;
typedef struct jsi_Pline jsi_Pline;
typedef struct jsi_Lexer jsi_Lexer;
typedef struct Jsi_File Jsi_File;
typedef struct Jsi_TypeCheck Jsi_TypeCheck;

enum {
    LT_STRING = 1
};

typedef enum {
    FC_NORMAL
} Jsi_FuncType;

typedef enum {
    OP_NOP,
    OP_RET
} Jsi_OpCode;

typedef enum {
    JSI_TT_UNDEFINED = 1,
    JSI_TT_VOID = 2
} Jsi_otype;

struct Jsi_ScopeStrs {
    int count;
    struct {
        char *name;
    } *args;
    Jsi_otype retType;
};

struct Jsi_OpCodes {
    int code_len;
    struct {
        Jsi_OpCode op;
    } *codes;
};

struct jsi_Pline {
    int first_line;
};

struct Jsi_File {
    char *fileName;
};

struct Jsi_TypeCheck {
    int funcdecl;
};

struct Jsi_Func {
    int isArrow;
    int isSet;
    int isGet;
    Jsi_FuncType type;
    Jsi_OpCodes *opcodes;
    Jsi_ScopeStrs *argnames;
    Jsi_ScopeStrs *localnames;
    struct jsi_Pline bodyline;
    Jsi_otype retType;
    char *bodyStr;
    int endPos;
    int startPos;
    char *name;
    Jsi_File *filePtr;
};

struct jsi_Lexer {
    int ltype;
    union {
        char *str;
    } d;
    int cur;
};

struct Jsi_Interp {
    int noES6;
    int noCheck;
    jsi_Pline *parseLine;
    void *staticFuncsTbl;
    Jsi_TypeCheck typeCheck;
};

struct jsi_Pstate {
    Jsi_Interp *interp;
    jsi_Lexer *lexer;
    int err_count;
    int argType;
};

extern Jsi_Func *jsi_FuncNew(Jsi_Interp *interp);
extern Jsi_ScopeStrs *jsi_ScopeGetVarlist(jsi_Pstate *pstate);
extern int Jsi_Strcmp(const char *s1, const char *s2);
extern void Jsi_LogError(const char *fmt, ...);
extern void Jsi_LogWarn(const char *fmt, ...);
extern char *Jsi_KeyAdd(Jsi_Interp *interp, const char *str);
extern void *Jsi_HashGet(void *tbl, void *key, int flags);
extern void Jsi_HashSet(void *tbl, void *key, void *val);
extern int jsi_FuncSigsMatch(jsi_Pstate *pstate, Jsi_Func *f1, Jsi_Func *f2);
extern void jsi_TypeMismatch(Jsi_Interp *interp);