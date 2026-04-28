#include <stdint.h>
#include <string.h>
#include <strings.h>

typedef intptr_t ngx_int_t;
typedef uintptr_t ngx_uint_t;
typedef unsigned char u_char;

#define NGX_OK 0
#define NGX_ERROR -1

typedef struct {
    size_t len;
    u_char *data;
} ngx_str_t;

typedef struct ngx_http_request_s ngx_http_request_t;

typedef struct ngx_http_lua_ctx_s {
    int mime_set;
} ngx_http_lua_ctx_t;

typedef struct {
    ngx_str_t name;
    ngx_int_t offset;
    ngx_int_t (*handler)(ngx_http_request_t *r, void *val, ngx_str_t *value);
} ngx_http_lua_set_header_t;

typedef struct {
    ngx_uint_t hash;
    ngx_str_t key;
    ngx_int_t offset;
    unsigned no_override;
    ngx_int_t (*handler)(ngx_http_request_t *r, void *val, ngx_str_t *value);
} ngx_http_lua_header_val_t;

extern ngx_http_lua_set_header_t ngx_http_lua_set_handlers[];

ngx_uint_t ngx_hash_key_lc(u_char *data, size_t len);
ngx_int_t ngx_http_lua_check_header_safe(ngx_http_request_t *r, u_char *data, size_t len);
ngx_int_t ngx_http_set_content_type_header(ngx_http_request_t *r, void *val, ngx_str_t *value);
size_t ngx_http_lua_safe_header_value_len(u_char *data, size_t len);
int ngx_strncasecmp(u_char *s1, u_char *s2, size_t n);
void dd(const char *fmt, ...);