#include <stdio.h>
#include <stdlib.h>

typedef void* yyscan_t;

struct yyguts_t {
    int yylineno;
    void* YY_CURRENT_BUFFER;
};

#define YY_CURRENT_BUFFER (yyg->YY_CURRENT_BUFFER)
#define yylineno (yyg->yylineno)