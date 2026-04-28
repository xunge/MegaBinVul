#include <stddef.h>

typedef int ngx_int_t;
typedef struct ngx_http_request_s ngx_http_request_t;
typedef struct ngx_http_auth_spnego_ctx_s ngx_http_auth_spnego_ctx_t;
typedef struct ngx_http_auth_spnego_loc_conf_s ngx_http_auth_spnego_loc_conf_t;
typedef struct ngx_str_s ngx_str_t;

#define NGX_DECLINED  -5
#define NGX_OK        0
#define NGX_ERROR    -1
#define NGX_HTTP_OK                 200
#define NGX_HTTP_FORBIDDEN          403
#define NGX_HTTP_UNAUTHORIZED       401
#define NGX_HTTP_INTERNAL_SERVER_ERROR 500

struct ngx_str_s {
    size_t      len;
    void       *data;
};

struct ngx_http_headers_in_s {
    ngx_str_t   user;
};

struct ngx_http_request_s {
    struct ngx_http_headers_in_s headers_in;
    void *pool;
};

struct ngx_http_auth_spnego_ctx_s {
    ngx_str_t   token;
    ngx_str_t   token_out_b64;
    int         head;
    ngx_int_t   ret;
};

struct ngx_http_auth_spnego_loc_conf_s {
    int         protect;
    int         allow_basic;
};

#define ngx_http_get_module_loc_conf(r, module) NULL
#define ngx_http_get_module_ctx(r, module) NULL
#define ngx_palloc(pool, size) NULL
#define ngx_http_set_ctx(r, ctx, module) 
#define spnego_debug0(msg)
#define spnego_debug1(msg, arg1)
#define spnego_debug3(msg, arg1, arg2, arg3)
#define ngx_http_auth_basic_user(r) NGX_DECLINED
#define ngx_http_auth_spnego_basic(r, ctx, alcf) NGX_DECLINED
#define ngx_http_auth_spnego_headers_basic_only(r, ctx, alcf) NGX_OK
#define ngx_spnego_authorized_principal(r, user, alcf) 1
#define ngx_http_auth_spnego_token(r, ctx) NGX_DECLINED
#define ngx_http_auth_spnego_auth_user_gss(r, ctx, alcf) NGX_DECLINED
#define ngx_http_auth_spnego_headers(r, ctx, token, alcf) NGX_OK