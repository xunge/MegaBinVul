#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Function {
    int script;
} js_Function;
typedef struct js_Ast js_Ast;

#define JF js_State *J, js_Function *F

enum {
    AST_FUNDEC,
    STM_BLOCK,
    STM_EMPTY,
    STM_VAR,
    STM_IF,
    STM_DO,
    STM_WHILE,
    STM_FOR,
    STM_FOR_VAR,
    STM_FOR_IN,
    STM_FOR_IN_VAR,
    STM_SWITCH,
    STM_LABEL,
    STM_BREAK,
    STM_CONTINUE,
    STM_RETURN,
    STM_THROW,
    STM_WITH,
    STM_TRY,
    STM_DEBUGGER
};

enum {
    OP_POP,
    OP_UNDEF,
    OP_JTRUE,
    OP_JUMP,
    OP_JFALSE,
    OP_ITERATOR,
    OP_NEXTITER,
    OP_ROT2,
    OP_RETURN,
    OP_THROW,
    OP_WITH,
    OP_ENDWITH,
    OP_DEBUGGER
};

struct js_Ast {
    int type;
    struct js_Ast *a, *b, *c, *d;
    struct js_Ast *parent;
    struct js_Ast *jumps;
    char *string;
};

static void emit(js_State *J, js_Function *F, int op);
static void emitline(js_State *J, js_Function *F, js_Ast *stm);
static void cstmlist(js_State *J, js_Function *F, js_Ast *list);
static void cvarinit(js_State *J, js_Function *F, js_Ast *list);
static void js_cexp(js_State *J, js_Function *F, js_Ast *exp);
static int emitjump(js_State *J, js_Function *F, int op);
static void emitjumpto(js_State *J, js_Function *F, int op, int target);
static void label(js_State *J, js_Function *F, int pc);
static void labeljumps(js_State *J, js_Function *F, js_Ast *list, int from, int to);
static int here(js_State *J, js_Function *F);
static void cassignforin(js_State *J, js_Function *F, js_Ast *stm);
static void cswitch(js_State *J, js_Function *F, js_Ast *exp, js_Ast *stm);
static int isloop(int type);
static js_Ast *breaktarget(js_State *J, js_Function *F, js_Ast *parent, const char *label);
static js_Ast *continuetarget(js_State *J, js_Function *F, js_Ast *parent, const char *label);
static js_Ast *returntarget(js_State *J, js_Function *F, js_Ast *parent);
static void cexit(js_State *J, js_Function *F, int type, js_Ast *stm, js_Ast *target);
static void addjump(js_State *J, js_Function *F, int type, js_Ast *target, int pc);
static void ctrycatch(js_State *J, js_Function *F, js_Ast *try, js_Ast *catch, js_Ast *var);
static void ctryfinally(js_State *J, js_Function *F, js_Ast *try, js_Ast *finally);
static void ctrycatchfinally(js_State *J, js_Function *F, js_Ast *try, js_Ast *catch, js_Ast *var, js_Ast *finally);
static void jsC_error(js_State *J, js_Ast *stm, const char *fmt, ...);

#define cexp js_cexp