#include <stddef.h>

typedef struct pj_scanner {
    char *curptr;
    char *start_line;
    int line;
    int skip_ws;
} pj_scanner;

#define PJ_DEF(x) x
#define PJ_SCAN_IS_NEWLINE(c) ((c) == '\r' || (c) == '\n')
#define PJ_SCAN_IS_PROBABLY_SPACE(c) ((c) == ' ' || (c) == '\t')

void pj_scan_syntax_err(pj_scanner *scanner);
void pj_scan_skip_whitespace(pj_scanner *scanner);