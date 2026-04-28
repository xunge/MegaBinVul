#include <stdlib.h>
#include <string.h>

typedef struct conn_st *conn_t;
typedef struct nad_st *nad_t;
typedef struct jid_st *jid_t;
typedef struct xhash_st xhash_t;
typedef struct sx_st sx_t;
typedef struct fd_st {
    int fd;
} fd_t;
typedef struct s2s_st s2s_st;
typedef struct pool_st pool_t;

enum conn_state {
    conn_INPROGRESS,
    conn_VALID
};

enum stream_error {
    stream_err_INVALID_ID
};

enum log_level {
    LOG_NOTICE
};

enum sx_flags {
    SX_SSL_WRAPPER
};

#define ZONE NULL
#define uri_DIALBACK NULL

jid_t *jid_new(const char *str, int len);
void jid_free(jid_t *jid);
int nad_find_attr(nad_t nad, int elem, int attr, const char *name, const char *ns);
char *NAD_AVAL(nad_t nad, int attr);
int NAD_AVAL_L(nad_t nad, int attr);
void nad_free(nad_t nad);
conn_t xhash_getx(xhash_t *h, const char *key, int key_len);
void *xhash_get(xhash_t *h, const char *key);
void xhash_put(xhash_t *h, char *key, void *val);
pool_t *xhash_pool(xhash_t *h);
char *pstrdup(pool_t *p, const char *s);
char *s2s_route_key(pool_t *p, const char *from, const char *to);
void log_debug(const char *zone, const char *fmt, ...);
void log_write(void *log, int level, const char *fmt, ...);
nad_t nad_new();
int nad_add_namespace(nad_t nad, const char *uri, const char *prefix);
void nad_append_elem(nad_t nad, int ns, const char *name, int parent);
void nad_append_attr(nad_t nad, int elem, const char *name, const char *val);
void sx_nad_write(sx_t *s, nad_t nad);
void sx_error(sx_t *s, int err, const char *reason);
void sx_close(sx_t *s);

struct conn_st {
    s2s_st *s2s;
    xhash_t *states;
    sx_t *s;
    fd_t *fd;
    char *ip;
    int port;
    int verify;
};

struct jid_st {
    char *domain;
};

struct s2s_st {
    xhash_t *in;
    void *log;
};

struct sx_st {
    int flags;
    int compressed;
};