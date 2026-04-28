#include <stdint.h>
#include <string.h>

typedef intptr_t ngx_int_t;
typedef uintptr_t ngx_uint_t;
typedef unsigned char u_char;
typedef int64_t off_t;

#define NGX_OK 0
#define NGX_ERROR -1
#define NGX_OFF_T_LEN 20

typedef struct {
    size_t len;
    u_char *data;
} ngx_str_t;

typedef struct ngx_table_elt_s {
    ngx_uint_t hash;
    ngx_str_t key;
    ngx_str_t value;
    u_char *lowcase_key;
} ngx_table_elt_t;

typedef struct ngx_list_part_s {
    void *elts;
    ngx_uint_t nelts;
    struct ngx_list_part_s *next;
} ngx_list_part_t;

typedef struct {
    ngx_list_part_t part;
    size_t size;
    ngx_uint_t nalloc;
    void *pool;
} ngx_list_t;

typedef struct {
    ngx_list_t headers;
    ngx_table_elt_t *content_length;
    off_t content_length_n;
} ngx_http_headers_in_t;

typedef struct {
    void *buf;
} ngx_http_request_body_t;

typedef struct ngx_http_request_s {
    ngx_http_headers_in_t headers_in;
    ngx_http_request_body_t *request_body;
    void *pool;
} ngx_http_request_t;

extern ngx_uint_t ngx_http_lua_content_length_hash;
extern ngx_str_t ngx_http_lua_content_length_header_key;
extern ngx_int_t ngx_http_lua_set_input_header(ngx_http_request_t *r, ngx_str_t key, ngx_str_t value, ngx_uint_t override);
extern void *ngx_palloc(void *pool, size_t size);
extern void *ngx_pnalloc(void *pool, size_t size);
extern u_char *ngx_sprintf(u_char *buf, const char *fmt, ...);
extern u_char *ngx_strlow(u_char *dst, u_char *src, size_t n);
extern int ngx_strncasecmp(u_char *s1, u_char *s2, size_t n);
extern ngx_int_t ngx_list_init(ngx_list_t *list, void *pool, ngx_uint_t n, size_t size);
extern void *ngx_list_push(ngx_list_t *list);
extern off_t ngx_buf_size(void *buf);

#define dd(...)