#include <stddef.h>

typedef unsigned char u_char;

typedef struct ngx_connection_s {
    void *log;
} ngx_connection_t;

typedef struct ngx_http_request_s {
    struct {
        u_char *data;
        size_t len;
    } uri;
    void *pool;
    ngx_connection_t *connection;
    unsigned internal:1;
    unsigned valid_unparsed_uri:1;
    unsigned uri_changed:1;
    unsigned valid_location:1;
} ngx_http_request_t;

typedef struct ngx_module_s {
    int ctx_index;
} ngx_module_t;

typedef struct {
    unsigned entered_rewrite_phase:1;
    unsigned entered_access_phase:1;
    unsigned entered_content_phase:1;
} ngx_http_lua_ctx_t;

#define NGX_OK 0
#define NGX_HTTP_LUA_CONTEXT_REWRITE 0x01
#define NGX_LOG_DEBUG_HTTP 0
#define dd(...)

extern ngx_module_t *ngx_http_lua_module;

typedef struct lua_State lua_State;
#define LUA_TBOOLEAN 1

int lua_gettop(lua_State *L);
int luaL_error(lua_State *L, const char *fmt, ...);
void luaL_checktype(lua_State *L, int idx, int type);
int lua_toboolean(lua_State *L, int idx);
const char *luaL_checklstring(lua_State *L, int idx, size_t *len);
int lua_yield(lua_State *L, int nresults);

ngx_http_request_t *ngx_http_lua_get_req(lua_State *L);
void ngx_http_lua_check_fake_request(lua_State *L, ngx_http_request_t *r);
int ngx_http_lua_check_uri_safe(ngx_http_request_t *r, u_char *p, size_t len);
void ngx_http_lua_check_context(lua_State *L, ngx_http_lua_ctx_t *ctx, int flags);
void ngx_http_lua_check_if_abortable(lua_State *L, ngx_http_lua_ctx_t *ctx);
void ngx_http_set_exten(ngx_http_request_t *r);
void *ngx_palloc(void *pool, size_t size);
void ngx_memcpy(void *dst, const void *src, size_t n);
ngx_http_lua_ctx_t *ngx_http_get_module_ctx(ngx_http_request_t *r, ngx_module_t *module);
void ngx_log_debug2(int level, void *log, int err, const char *fmt, size_t len, const u_char *p);