#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

#define INCREC()
#define DECREC()
#define EXP2(type, left, right) ((js_Ast*)0)
#define MEMBER 0
#define INDEX 0

static js_Ast *newexp(js_State *J);
static int jsP_accept(js_State *J, int tok);
static js_Ast *identifiername(js_State *J);
static js_Ast *expression(js_State *J, int comma);
static void jsP_expect(js_State *J, int tok);