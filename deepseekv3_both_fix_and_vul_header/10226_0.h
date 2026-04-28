#include <stdlib.h>
#include <string.h>

typedef unsigned int yy_size_t;
typedef void* yyscan_t;

struct yy_buffer_state;
struct yyguts_t {
    struct yy_buffer_state** yy_buffer_stack;
    yy_size_t yy_buffer_stack_max;
    yy_size_t yy_buffer_stack_top;
};

void* re_yyalloc(yy_size_t size, yyscan_t yyscanner);
void* re_yyrealloc(void* ptr, yy_size_t size, yyscan_t yyscanner);
void YY_FATAL_ERROR(const char* msg);