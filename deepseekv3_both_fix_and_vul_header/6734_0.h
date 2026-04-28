#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

#define EXP2(type, left, right) ((js_Ast *)((type) | (size_t)(left) | (size_t)(right)))
#define BITXOR 0x01

static js_Ast *bitand(js_State *J, int notin);
static int jsP_accept(js_State *J, int tok);