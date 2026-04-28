#include <stddef.h>
#include <stdlib.h>

typedef unsigned long pj_size_t;

typedef struct pj_str_t {
    char *ptr;
    pj_size_t slen;
} pj_str_t;

typedef struct pj_scanner {
    char *curptr;
    char *end;
} pj_scanner;

typedef struct pjmedia_sdp_time {
    unsigned long start;
    unsigned long stop;
} pjmedia_sdp_time;

typedef struct pjmedia_sdp_session {
    pjmedia_sdp_time time;
} pjmedia_sdp_session;

typedef struct parse_context {
    int last_error;
} parse_context;

#define PJMEDIA_SDP_EINTIME 0
#define SKIP_WS 0

unsigned long pj_strtoul(const pj_str_t *str);
void on_scanner_error(pj_scanner *scanner);
void pj_scan_advance_n(pj_scanner *scanner, int n, int flags);
void pj_scan_get_until_ch(pj_scanner *scanner, char ch, pj_str_t *str);
void pj_scan_get_char(pj_scanner *scanner);
void pj_scan_get_until_chr(pj_scanner *scanner, const char *delim, pj_str_t *str);
void pj_scan_skip_line(pj_scanner *scanner);