#include <stddef.h>

typedef struct pj_scanner {
    char *curptr;
    int skip_ws;
} pj_scanner;

typedef struct pj_str_t {
    char *ptr;
    size_t slen;
} pj_str_t;

typedef struct pj_cis_t {
    unsigned char bits[32];
} pj_cis_t;

#define PJ_DEF(x) x
#define PJ_SCAN_IS_PROBABLY_SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')

void pj_assert(int expr);
int pj_cis_match(const pj_cis_t *spec, int c);
void pj_scan_syntax_err(pj_scanner *scanner);
void pj_strset3(pj_str_t *str, char *begin, char *end);
void pj_scan_skip_whitespace(pj_scanner *scanner);