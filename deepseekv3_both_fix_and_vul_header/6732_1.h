#include <stdlib.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

enum {
    MUL,
    DIV, 
    MOD
};

static js_Ast* EXP2(int op, js_Ast* left, js_Ast* right) {
    return NULL;
}

static js_Ast *unary(js_State *J) {
    return NULL;
}

static int jsP_accept(js_State *J, int tok) {
    return 0;
}