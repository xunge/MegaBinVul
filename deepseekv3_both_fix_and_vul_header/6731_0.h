#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

static js_Ast *logor(js_State *J, int notin);
static js_Ast *assignment(js_State *J, int notin);
static int jsP_accept(js_State *J, int tok);
static void jsP_expect(js_State *J, int tok);
#define EXP3(t,a,b,c) /* implementation-defined */