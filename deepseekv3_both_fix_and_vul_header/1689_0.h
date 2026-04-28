#include <stddef.h>

typedef struct pj_scanner {
    char *curptr;
    char *end;
} pj_scanner;

typedef struct parse_context {
    int last_error;
} parse_context;

#define PJMEDIA_SDP_EINVER 1

void on_scanner_error(pj_scanner *scanner);
void pj_scan_skip_line(pj_scanner *scanner);