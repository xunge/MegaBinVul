#include <stdlib.h>

typedef struct pj_str_t {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct pj_scanner {
    char *curptr;
    char *end;
} pj_scanner;

typedef struct parse_context {
    int last_error;
} parse_context;

typedef struct pjmedia_sdp_attr {
    pj_str_t name;
    pj_str_t value;
} pjmedia_sdp_attr;

typedef struct pj_pool_t {
    void *data;
} pj_pool_t;

static const char cs_token[] = " \t\r\n=";

#define PJ_POOL_ALLOC_T(pool, type) ((type*)malloc(sizeof(type)))
#define PJMEDIA_SDP_EINATTR (-1)
#define SKIP_WS 1

static void on_scanner_error(pj_scanner *scanner) {}
static void pj_scan_advance_n(pj_scanner *scanner, int n, int skip_ws) {}
static void pj_scan_get(pj_scanner *scanner, const void *cs_token, pj_str_t *str) {}
static void pj_scan_get_char(pj_scanner *scanner) {}
static int pj_scan_is_eof(pj_scanner *scanner) { return 0; }
static void pj_scan_get_until_chr(pj_scanner *scanner, const char *delim, pj_str_t *str) {}
static void pj_scan_skip_line(pj_scanner *scanner) {}