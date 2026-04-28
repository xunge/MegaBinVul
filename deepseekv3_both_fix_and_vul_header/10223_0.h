#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef void* yyscan_t;
typedef void* YY_EXTRA_TYPE;

struct yyguts_t {
    // 这里需要根据实际使用情况定义结构体成员
    // 由于原代码中没有使用具体成员，暂时留空
};

void re_yyset_extra(YY_EXTRA_TYPE user_defined, struct yyguts_t* yyg);
void* re_yyalloc(size_t size, struct yyguts_t* yyg);
int yy_init_globals(yyscan_t yyscanner);