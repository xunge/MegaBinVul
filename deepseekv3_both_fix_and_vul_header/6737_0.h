#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

#define INCREC()
#define DECREC()
#define EXP2(type, left, right) ((left), (right))
#define COMMA 0

static js_Ast *assignment(js_State *J, int notin);
static int jsP_accept(js_State *J, int tok);