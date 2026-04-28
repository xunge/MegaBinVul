#include <stdint.h>
#include <stddef.h>

typedef intptr_t        ngx_int_t;
typedef uintptr_t       ngx_uint_t;
typedef unsigned char   u_char;

typedef struct {
    size_t      len;
    u_char     *data;
    void       *lengths;
} ngx_str_t;

typedef struct {
    ngx_uint_t        hash;
    ngx_str_t         key;
    ngx_str_t         value;
} ngx_table_elt_t;

typedef struct {
    ngx_int_t   overwrite;
    ngx_str_t   value;
    ngx_str_t   args;
} ngx_http_err_page_t;

typedef struct ngx_list_s ngx_list_t;
typedef struct ngx_http_request_s ngx_http_request_t;
typedef struct ngx_http_core_loc_conf_s ngx_http_core_loc_conf_t;

struct ngx_list_s {
    void *last;
};

struct ngx_http_request_s {
    ngx_uint_t          method;
    void               *method_name;
    ngx_uint_t          err_status;
    ngx_uint_t          expect_tested;
    ngx_uint_t          keepalive;
    struct {
        ngx_uint_t     msie;
    } headers_in;
    struct {
        ngx_list_t     headers;
        ngx_table_elt_t *location;
    } headers_out;
};

struct ngx_http_core_loc_conf_s {
    ngx_uint_t          msie_refresh;
};

#define NGX_OK          0
#define NGX_ERROR      -1
#define NGX_HTTP_OK    200
#define NGX_HTTP_HEAD  1
#define NGX_HTTP_GET   2
#define NGX_HTTP_MOVED_PERMANENTLY  301
#define NGX_HTTP_MOVED_TEMPORARILY  302
#define NGX_HTTP_SEE_OTHER          303
#define NGX_HTTP_TEMPORARY_REDIRECT 307
#define NGX_HTTP_PERMANENT_REDIRECT 308
#define NGX_HTTP_OFF_3XX            300

#define ngx_str_set(str, text) \
    (str)->len = sizeof(text) - 1; (str)->data = (u_char *) text

extern ngx_table_elt_t *ngx_list_push(ngx_list_t *list);
extern ngx_int_t ngx_http_complex_value(ngx_http_request_t *r, ngx_str_t *val, ngx_str_t *uri);
extern ngx_int_t ngx_http_split_args(ngx_http_request_t *r, ngx_str_t *uri, ngx_str_t *args);
extern ngx_int_t ngx_http_internal_redirect(ngx_http_request_t *r, ngx_str_t *uri, ngx_str_t *args);
extern ngx_int_t ngx_http_named_location(ngx_http_request_t *r, ngx_str_t *name);
extern ngx_int_t ngx_http_discard_request_body(ngx_http_request_t *r);
extern void ngx_http_clear_location(ngx_http_request_t *r);
extern ngx_http_core_loc_conf_t *ngx_http_get_module_loc_conf(ngx_http_request_t *r, void *module);
extern ngx_int_t ngx_http_send_refresh(ngx_http_request_t *r);
extern ngx_int_t ngx_http_send_special_response(ngx_http_request_t *r, ngx_http_core_loc_conf_t *clcf, ngx_int_t status);
extern void *ngx_http_core_module;
extern void *ngx_http_core_get_method;