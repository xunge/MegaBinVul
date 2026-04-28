#include <stddef.h>

typedef struct pj_scanner {
    char *curptr;
    char *end;
    int skip_ws;
} pj_scanner;

typedef struct pj_str_t {
    char *ptr;
    size_t slen;
} pj_str_t;

#define PJ_DEF(ret) ret
#define PJ_SCAN_IS_PROBABLY_SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')

void pj_scan_syntax_err(pj_scanner *scanner);
void pj_strset(pj_str_t *str, char *ptr, size_t len);
void pj_scan_skip_whitespace(pj_scanner *scanner);