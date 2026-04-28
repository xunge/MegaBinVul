#include <stdio.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

struct js_Ast {
    int type;
    #define AST_LIST 0
};

extern int minify;
void sblock(int, js_Ast*);
void snode(int, js_Ast*);
void nl(void);