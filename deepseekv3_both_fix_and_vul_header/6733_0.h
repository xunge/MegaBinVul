#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

#define TK_LE 0
#define TK_GE 0
#define TK_INSTANCEOF 0
#define TK_IN 0

#define EXP2(op, left, right) NULL
#define LT 0
#define GT 0
#define LE 0
#define GE 0
#define INSTANCEOF 0
#define IN 0

static js_Ast *shift(js_State *J);
static int jsP_accept(js_State *J, int tok);