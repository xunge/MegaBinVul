#include <string.h>

struct js_Ast {
    char *string;
};

struct js_Function {
    int strict;
};

enum {
    OP_TRY,
    OP_THROW,
    OP_CATCH,
    OP_ENDCATCH,
    OP_ENDTRY,
    OP_JUMP
};

typedef struct js_State js_State;
typedef struct js_Function js_Function;
typedef struct js_Ast js_Ast;

#define JF js_State *J, js_Function *F

int emitjump(js_State *J, js_Function *F, int op);
void label(js_State *J, js_Function *F, int L);
void emit(js_State *J, js_Function *F, int op);
void emitstring(js_State *J, js_Function *F, int op, const char *str);
void emitline(js_State *J, js_Function *F, js_Ast *ast);
void cstm(js_State *J, js_Function *F, js_Ast *ast);
void checkfutureword(js_State *J, js_Function *F, js_Ast *ast);
void jsC_error(js_State *J, js_Ast *ast, const char *msg);