#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct h2o_handler_t h2o_handler_t;
typedef struct h2o_req_t h2o_req_t;
typedef struct h2o_redirect_handler_t h2o_redirect_handler_t;
typedef struct h2o_iovec_t h2o_iovec_t;
typedef struct h2o_mem_pool_t h2o_mem_pool_t;
typedef struct h2o_pathconf_t h2o_pathconf_t;

struct h2o_iovec_t {
    char *base;
    size_t len;
};

struct h2o_pathconf_t {
    h2o_iovec_t path;
};

struct h2o_mem_pool_t {
    // Minimal pool definition
};

struct h2o_req_t {
    h2o_iovec_t path;
    h2o_iovec_t path_normalized;
    h2o_pathconf_t *pathconf;
    size_t query_at;
    h2o_mem_pool_t pool;
};

struct h2o_redirect_handler_t {
    h2o_iovec_t prefix;
    int status;
    int internal;
};

#define H2O_STRLIT(s) (char *)(s), sizeof(s) - 1
#define SIZE_MAX ((size_t)-1)

static h2o_iovec_t h2o_iovec_init(char *base, size_t len) {
    return (h2o_iovec_t){base, len};
}

static h2o_iovec_t h2o_concat(h2o_mem_pool_t *pool, h2o_iovec_t a, h2o_iovec_t b, h2o_iovec_t c) {
    size_t total_len = a.len + b.len + c.len;
    char *buf = malloc(total_len);
    if (buf) {
        memcpy(buf, a.base, a.len);
        memcpy(buf + a.len, b.base, b.len);
        memcpy(buf + a.len + b.len, c.base, c.len);
    }
    return (h2o_iovec_t){buf, total_len};
}

static h2o_iovec_t h2o_uri_escape(h2o_mem_pool_t *pool, char *base, size_t len, const char *reserved_chars) {
    // Minimal implementation
    char *buf = malloc(len);
    if (buf) {
        memcpy(buf, base, len);
    }
    return (h2o_iovec_t){buf, len};
}

static void h2o_send_redirect(h2o_req_t *req, int status, const char *reason, const char *location, size_t location_len) {
    // Empty implementation
}

static void redirect_internally(h2o_redirect_handler_t *self, h2o_req_t *req, h2o_iovec_t dest) {
    // Empty implementation
}