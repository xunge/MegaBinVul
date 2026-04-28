#include <stdio.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

struct js_Ast {
    int type;
    #define AST_LIST 0
};

extern int minify;
void pstmlist(int n, js_Ast *prog);
void pstm(int n, js_Ast *prog);
void nl(void);