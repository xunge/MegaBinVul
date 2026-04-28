#include <stdlib.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

enum {
    ADD,
    SUB
};

static js_Ast *EXP2(int op, js_Ast *left, js_Ast *right) {
    return NULL;
}

int jsP_accept(js_State *J, int tok);
js_Ast *multiplicative(js_State *J);