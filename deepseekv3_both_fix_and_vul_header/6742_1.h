#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

enum { BITAND };

static js_Ast *EXP2(int type, js_Ast *left, js_Ast *right);
static js_Ast *equality(js_State *J, int notin);
static int jsP_accept(js_State *J, int tok);