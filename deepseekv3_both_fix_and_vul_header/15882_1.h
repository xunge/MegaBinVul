#include <stdlib.h>
#include <stdarg.h>

#define LYE_INSTMT 0
#define LY_VLOG_LYS 0
#define LY_VLOG_NONE 0

struct yang_parameter {
    void **value;
    void **data_node;
    void **actual_node;
    struct {
        void *ctx;
    } *module;
};

typedef struct {
    int first_line;
} YYLTYPE;

void LOGVAL(void *ctx, int code, int type, void *node, const char *text);
const char *yyget_text(void *scanner);