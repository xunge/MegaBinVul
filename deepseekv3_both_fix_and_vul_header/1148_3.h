#include <stdlib.h>

typedef struct js_State js_State;
typedef struct js_Function js_Function;
typedef struct js_JumpList js_JumpList;
typedef struct js_Ast js_Ast;

struct js_JumpList {
    int type;
    int inst;
    js_JumpList *next;
};

struct js_Ast {
    js_JumpList *jumps;
};

#define STM_BREAK 1
#define STM_CONTINUE 2

#define JF js_State *J, js_Function *F

void labelto(js_State *J, js_Function *F, int inst, int addr);
void js_free(js_State *J, void *p);