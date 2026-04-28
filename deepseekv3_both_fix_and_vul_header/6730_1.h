#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

enum {
    TK_EQ,
    TK_NE,
    TK_STRICTEQ,
    TK_STRICTNE
};

enum {
    EQ,
    NE,
    STRICTEQ,
    STRICTNE
};

#define EXP2(op, left, right) ((js_Ast*)0)

static js_Ast *relational(js_State *J, int notin) { return (js_Ast*)0; }
static int jsP_accept(js_State *J, int tok) { return 0; }