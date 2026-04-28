#include <stddef.h>

#define PJ_DEF(ret) ret

typedef struct pj_scanner {
    char *curptr;
    char *end;
    int skip_ws;
} pj_scanner;

#define PJ_SCAN_CHECK_EOF(s) ((s) >= scanner->end)
#define PJ_SCAN_IS_PROBABLY_SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')

void pj_scan_syntax_err(pj_scanner *scanner);
void pj_scan_skip_whitespace(pj_scanner *scanner);