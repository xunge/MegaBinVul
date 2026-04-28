#include <stdbool.h>

typedef struct pj_scanner {
    char *curptr;
    char *end;
} pj_scanner;

#define PJ_DEF(ret) ret
#define PJ_SCAN_IS_PROBABLY_SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')
typedef bool pj_bool_t;

void pj_scan_syntax_err(pj_scanner *scanner);
void pj_scan_skip_whitespace(pj_scanner *scanner);