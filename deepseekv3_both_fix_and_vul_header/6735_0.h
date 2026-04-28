#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

#define INCREC()
#define DECREC()
#define EXP2(type, left, right) ((js_Ast*)NULL)

enum {
    TK_MUL_ASS,
    TK_DIV_ASS,
    TK_MOD_ASS,
    TK_ADD_ASS,
    TK_SUB_ASS,
    TK_SHL_ASS,
    TK_SHR_ASS,
    TK_USHR_ASS,
    TK_AND_ASS,
    TK_XOR_ASS,
    TK_OR_ASS,
    ASS,
    ASS_MUL,
    ASS_DIV,
    ASS_MOD,
    ASS_ADD,
    ASS_SUB,
    ASS_SHL,
    ASS_SHR,
    ASS_USHR,
    ASS_BITAND,
    ASS_BITXOR,
    ASS_BITOR
};

static js_Ast *conditional(js_State *J, int notin);
static int jsP_accept(js_State *J, int tok);