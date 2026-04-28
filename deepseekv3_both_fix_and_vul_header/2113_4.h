#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jid *jid_t;
typedef struct conn *conn_t;
typedef struct nad *nad_t;
typedef struct xhash xhash_t;
typedef struct sx sx_t;
typedef struct fd fd_t;
typedef struct s2s s2s_t;
typedef struct pool pool_t;

enum {
    ZONE,
    LOG_NOTICE,
    conn_INPROGRESS,
    conn_VALID,
    SX_SSL_WRAPPER,
    stream_err_INVALID_ID,
    stanza_err_SERVICE_UNAVAILABLE
};

struct jid {
    char *domain;
};

struct fd {
    int fd;
};

struct s2s {
    void *log;
};

struct conn {
    xhash_t *states;
    s2s_t *s2s;
    fd_t *fd;
    char *ip;
    int port;
    sx_t *s;
};

struct sx {
    int flags;
    int compressed;
};

jid_t jid_new(const char *str, int len);
void jid_free(jid_t jid);
void nad_free(nad_t nad);
int nad_find_attr(nad_t nad, int elem, int attr, const char *name, const char *value);
char *NAD_AVAL(nad_t nad, int attr);
int NAD_AVAL_L(nad_t nad, int attr);
char *s2s_route_key(pool_t *pool, const char *to, const char *from);
void log_debug(int zone, const char *fmt, ...);
void log_write(void *log, int level, const char *fmt, ...);
void *xhash_get(xhash_t *h, const char *key);
void xhash_put(xhash_t *h, char *key, void *val);
pool_t *xhash_pool(xhash_t *h);
char *pstrdup(pool_t *p, const char *s);
void out_flush_route_queue(s2s_t *s2s, const char *rkey, int rkeylen);
void sx_error(sx_t *s, int err, const char *reason);
void sx_close(sx_t *s);
void out_bounce_route_queue(s2s_t *s2s, const char *rkey, int rkeylen, int err);