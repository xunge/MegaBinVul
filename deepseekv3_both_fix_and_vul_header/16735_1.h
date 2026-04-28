#include <stdint.h>
#include <string.h>
#include <strings.h>

typedef intptr_t ngx_int_t;
typedef uintptr_t ngx_uint_t;
typedef unsigned char u_char;

typedef struct {
    size_t len;
    u_char *data;
} ngx_str_t;

typedef struct {
    ngx_str_t name;
    ngx_int_t offset;
    ngx_int_t (*handler)(void *r, void *hv, ngx_str_t *value);
} ngx_http_lua_set_header_t;

typedef struct {
    ngx_uint_t hash;
    ngx_str_t key;
    ngx_int_t offset;
    unsigned no_override;
    ngx_int_t (*handler)(void *r, void *hv, ngx_str_t *value);
} ngx_http_lua_header_val_t;

typedef struct {
    int status;
} ngx_http_headers_out_t;

typedef struct {
    struct {
        void *last;
    } headers;
} ngx_http_headers_in_t;

typedef struct {
    ngx_http_headers_out_t headers_out;
    ngx_http_headers_in_t headers_in;
} ngx_http_request_t;

extern ngx_http_lua_set_header_t ngx_http_lua_set_handlers[];

#define NGX_ERROR -1
#define NGX_OK 0

#define dd(fmt, ...)

static ngx_uint_t ngx_hash_key_lc(u_char *data, size_t len) {
    return 0;
}

static int ngx_strncasecmp(u_char *s1, u_char *s2, size_t n) {
    return strncasecmp((char *)s1, (char *)s2, n);
}