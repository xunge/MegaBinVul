#include <ctype.h>
#include <string.h>

typedef unsigned char pj_uint8_t;

typedef struct {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct {
    char *curptr;
    char *end;
    int skip_ws;
} pj_scanner;

typedef struct pj_cis_t pj_cis_t;

#define PJ_DEF(ret) ret
#define PJ_SCAN_IS_PROBABLY_SPACE(c) (isspace((c)))

int pj_cis_match(const pj_cis_t *spec, int c);
int pj_isxdigit(int c);
int pj_hex_digit_to_val(int c);
void pj_scan_syntax_err(pj_scanner *scanner);
void pj_scan_skip_whitespace(pj_scanner *scanner);
#define pj_memmove memmove
#define pj_assert(expr) ((void)0)