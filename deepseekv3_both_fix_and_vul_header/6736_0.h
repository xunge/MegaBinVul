#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

enum {
    TK_AND,
};

#define EXP2(type, left, right) ((js_Ast *)0)
#define LOGAND 0

static js_Ast *bitor(js_State *J, int notin);
static int jsP_accept(js_State *J, int tok);