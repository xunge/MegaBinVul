#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

enum {
    TK_SHL,
    TK_SHR,
    TK_USHR
};

#define EXP2(op, left, right) ((js_Ast*)NULL)

static int jsP_accept(js_State *J, int tok);
static js_Ast *additive(js_State *J);