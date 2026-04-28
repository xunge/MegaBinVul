#include <string.h>
#include <stdint.h>

typedef enum {
    SUP,
    SUP_OR_EQUAL,
    INF,
    INF_OR_EQUAL
} comparison_t;

typedef struct {
    char* data;
    size_t len;
} ngx_str_t;

typedef struct {
    void* elts;
    size_t nelts;
} ngx_array_t;

typedef struct {
    ngx_str_t    sc_tag;
    int          sc_score;
    comparison_t cmp;
    unsigned int block:1;
    unsigned int drop:1;
    unsigned int allow:1;
    unsigned int log:1;
} ngx_http_check_rule_t;

typedef struct {
    ngx_str_t* sc_tag;
    int        sc_score;
} ngx_http_special_score_t;

typedef struct {
    ngx_array_t* check_rules;
    ngx_array_t* ignore_ips;
    ngx_array_t* ignore_cidrs;
} ngx_http_naxsi_loc_conf_t;

typedef struct {
    unsigned int ignore:1;
    unsigned int block:1;
    unsigned int drop:1;
    unsigned int allow:1;
    unsigned int log:1;
    ngx_array_t* special_scores;
} ngx_http_request_ctx_t;

typedef struct {
    ngx_str_t addr_text;
} ngx_connection_t;

typedef struct {
    ngx_str_t value;
} ngx_table_elt_t;

typedef struct {
    union {
        ngx_array_t array;
        ngx_table_elt_t* single;
    } x_forwarded_for;
} ngx_http_headers_in_t;

typedef struct {
    ngx_http_headers_in_t headers_in;
    ngx_connection_t* connection;
} ngx_http_request_t;

#define NX_DEBUG(flag, level, log, err, fmt, ...)
#define _debug_custom_score 0
#define _debug_whitelist_ignore 0
#define nginx_version 0
#define NGX_HTTP_X_FORWARDED_FOR 0
#define NGX_LOG_DEBUG_HTTP 0

static int ngx_strcmp(const char* s1, const char* s2) {
    return strcmp(s1, s2);
}

int naxsi_can_ignore_ip(ngx_str_t* ip, ngx_http_naxsi_loc_conf_t* cf);
int naxsi_can_ignore_cidr(ngx_str_t* ip, ngx_http_naxsi_loc_conf_t* cf);