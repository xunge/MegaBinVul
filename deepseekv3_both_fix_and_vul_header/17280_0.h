#include <string.h>

typedef struct MD_MARK {
    int beg;
    int end;
    char ch;
} MD_MARK;

typedef struct MD_CTX {
    MD_MARK* marks;
} MD_CTX;

#define MD_ASSERT(expr) ((void)0)
#define SZ int