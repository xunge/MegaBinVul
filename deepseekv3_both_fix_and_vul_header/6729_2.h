#include <stdlib.h>
#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

struct js_Ast {
    int type;
    js_Ast *left;
    js_Ast *right;
};

enum {
    MEMBER,
    INDEX, 
    CALL
};

static js_Ast *newast(int type, js_Ast *left, js_Ast *right) {
    js_Ast *ast = malloc(sizeof(js_Ast));
    ast->type = type;
    ast->left = left;
    ast->right = right;
    return ast;
}

#define EXP2(t, l, r) newast(t, l, r)

static js_Ast *newexp(js_State *J);
static js_Ast *identifiername(js_State *J); 
static js_Ast *expression(js_State *J, int comma);
static js_Ast *arguments(js_State *J);
static int jsP_accept(js_State *J, int tok);
static void jsP_expect(js_State *J, int tok);