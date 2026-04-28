#include <stdio.h>

typedef struct js_State js_State;
typedef struct js_Ast js_Ast;

struct js_Ast {
    int type;
    #define AST_LIST 1
};

extern int minify;
extern void pstmlist(int, js_Ast*);
extern void pstm(int, js_Ast*);
extern void nl(void);