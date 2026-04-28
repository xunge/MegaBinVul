#include <stdio.h>
#include <stdlib.h>

typedef void* yyscan_t;

struct yyguts_t {
    void* YY_CURRENT_BUFFER;
    int yycolumn;
};

#define YY_CURRENT_BUFFER (yyg->YY_CURRENT_BUFFER)
#define yycolumn (yyg->yycolumn)