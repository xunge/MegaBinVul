#include <stdint.h>

typedef struct pj_str_t {
    char *ptr;
    unsigned long slen;
} pj_str_t;

typedef struct pj_scanner {
    char *curptr;
    char *end;
} pj_scanner;

typedef struct pjmedia_sdp_origin {
    pj_str_t user;
    uint64_t id;
    uint64_t version;
    pj_str_t net_type;
    pj_str_t addr_type;
    pj_str_t addr;
} pjmedia_sdp_origin;

typedef struct pjmedia_sdp_session {
    pjmedia_sdp_origin origin;
} pjmedia_sdp_session;

typedef struct parse_context {
    int last_error;
} parse_context;

#define PJMEDIA_SDP_EINORIGIN 1
#define SKIP_WS 1

void on_scanner_error(pj_scanner *scanner);
void pj_scan_advance_n(pj_scanner *scanner, int n, int skip_ws);
void pj_scan_get_until_ch(pj_scanner *scanner, char ch, pj_str_t *out);
void pj_scan_get_char(pj_scanner *scanner);
uint64_t pj_strtoul(pj_str_t *str);
void pj_scan_get_until_chr(pj_scanner *scanner, const char *delim, pj_str_t *out);
void pj_scan_skip_line(pj_scanner *scanner);