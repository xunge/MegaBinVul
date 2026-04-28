#include <stddef.h>

typedef struct pj_str_t {
    char *ptr;
    size_t slen;
} pj_str_t;

typedef struct pj_scanner {
    char *curptr;
    char *end;
} pj_scanner;

typedef struct parse_context {
    int last_error;
} parse_context;

#define PJMEDIA_SDP_EINSDP 1
#define SKIP_WS 0

void on_scanner_error(pj_scanner *scanner);
void pj_scan_advance_n(pj_scanner *scanner, int n, int flags);
void pj_scan_get_until_chr(pj_scanner *scanner, const char *delim, pj_str_t *str);
void pj_scan_get_newline(pj_scanner *scanner);