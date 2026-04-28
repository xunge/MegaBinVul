#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef uintptr_t ngx_uint_t;
typedef intptr_t ngx_int_t;
typedef int ngx_err_t;

typedef struct ngx_http_lua_ctx_s {
    int exit_code;
    int exited;
    int header_sent;
} ngx_http_lua_ctx_t;

typedef struct {
    size_t len;
    u_char *data;
} ngx_str_t;

typedef struct ngx_table_elt_s {
    ngx_uint_t hash;
    ngx_str_t key;
    ngx_str_t value;
} ngx_table_elt_t;

typedef struct ngx_list_s {
    ngx_table_elt_t *last;
} ngx_list_t;

typedef struct {
    ngx_list_t headers;
    ngx_uint_t status;
    ngx_table_elt_t *location;
} ngx_http_headers_out_t;

typedef struct ngx_pool_s ngx_pool_t;
typedef struct ngx_log_s ngx_log_t;

typedef struct ngx_http_request_s {
    ngx_http_headers_out_t headers_out;
    ngx_pool_t *pool;
    ngx_log_t *log;
    unsigned header_sent:1;
    struct ngx_http_connection_s *connection;
} ngx_http_request_t;

typedef struct ngx_http_connection_s {
    ngx_http_request_t *request;
    ngx_log_t *log;
} ngx_http_connection_t;

typedef struct lua_State lua_State;

#define NGX_HTTP_MOVED_TEMPORARILY 302
#define NGX_HTTP_MOVED_PERMANENTLY 301
#define NGX_HTTP_SEE_OTHER 303
#define NGX_HTTP_PERMANENT_REDIRECT 308
#define NGX_HTTP_TEMPORARY_REDIRECT 307

#define NGX_HTTP_LUA_CONTEXT_REWRITE 0x0001
#define NGX_HTTP_LUA_CONTEXT_ACCESS 0x0002
#define NGX_HTTP_LUA_CONTEXT_CONTENT 0x0004

#define NGX_OK 0
#define NGX_LOG_DEBUG_HTTP 0

extern ngx_http_lua_ctx_t *ngx_http_get_module_ctx(ngx_http_request_t *r, void *module);
extern ngx_http_request_t *ngx_http_lua_get_req(lua_State *L);
extern void ngx_http_lua_check_context(lua_State *L, ngx_http_lua_ctx_t *ctx, int flags);
extern void ngx_http_lua_check_if_abortable(lua_State *L, ngx_http_lua_ctx_t *ctx);
extern ngx_int_t ngx_http_lua_check_header_safe(ngx_http_request_t *r, u_char *p, size_t len);
extern size_t ngx_http_lua_safe_header_value_len(u_char *p, size_t len);
extern ngx_uint_t ngx_http_lua_location_hash;
extern void *ngx_http_lua_module;
extern void *ngx_palloc(ngx_pool_t *pool, size_t size);
extern void ngx_memcpy(void *dst, const void *src, size_t n);
extern void ngx_str_set(ngx_str_t *dst, const char *src);
extern void ngx_log_debug2(ngx_uint_t level, ngx_log_t *log, ngx_err_t err, const char *fmt, ...);