#include <string.h>

#define PJ_DEF(ret) ret

typedef struct pj_scanner {
    char *curptr;
    char *end;
    char *start_line;
    int line;
} pj_scanner;

void *pj_memchr(const void *s, int c, size_t n);