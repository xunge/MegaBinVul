#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef struct sx_st *sx_t;
typedef struct c2s_st *c2s_t;
typedef struct sess_st *sess_t;
typedef struct host_st *host_t;
typedef struct xhash_st *xhash_t;
typedef struct config_st *config_t;
typedef struct sx_sasl_creds_st *sx_sasl_creds_t;
typedef struct jid_st jid_st;
typedef struct jid_static_buf_st jid_static_buf;

enum {
    sx_sasl_cb_GET_REALM,
    sx_sasl_cb_GET_PASS,
    sx_sasl_cb_CHECK_PASS,
    sx_sasl_cb_CHECK_AUTHZID,
    sx_sasl_cb_GEN_AUTHZID,
    sx_sasl_cb_CHECK_MECH
};

enum {
    sx_sasl_ret_OK,
    sx_sasl_ret_FAIL
};

enum {
    LOG_ERR,
    LOG_WARNING
};

enum {
    ZONE
};

enum {
    jid_NODE
};

struct sx_st {
    int tag;
    char *req_to;
    int ssf;
};

struct jid_st {
    char *domain;
    char *node;
    char *resource;
};

struct jid_static_buf_st {
    char data[256];
};

struct c2s_st {
    xhash_t sessions;
    xhash_t hosts;
    void *log;
    config_t config;
};

struct host_st {
    char *realm;
    struct {
        int (*get_password)(void *, sess_t, char *, char *, char *);
        int (*check_password)(void *, sess_t, char *, char *, char *);
        int (*user_authz_allowed)(void *, sess_t, char *, char *, char *);
        int (*user_exists)(void *, sess_t, char *, char *);
        void *ar;
    } *ar;
};

struct sess_st {
    struct host_st *host;
};

struct sx_sasl_creds_st {
    char *authnid;
    char *realm;
    char *authzid;
    char *pass;
};

void jid_static(jid_st *jid, jid_static_buf *buf);
char *jid_reset(jid_st *jid, const char *str, int len);
void jid_random_part(jid_st *jid, int part);

void *xhash_get(xhash_t xh, const char *key);
void *config_get(config_t cfg, const char *key);

void log_write(void *log, int level, const char *fmt, ...);
void log_debug(int zone, const char *fmt, ...);