#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Gsasl_session Gsasl_session;
typedef void* Gsasl;

typedef struct _sx_sasl_sess_st {
    void* s;
    void* ctx;
} *_sx_sasl_sess_t;

typedef struct _sx_ssl_conn_st {
    char *external_id[10];
} *_sx_ssl_conn_t;

typedef struct _sx_sasl_st {
    Gsasl *gsasl_ctx;
    char *appname;
    char *ext_id[10];
    int (*cb)(int, void *, void **, void *, void *);
    void *cbarg;
} *_sx_sasl_t;

typedef struct sx_buf_st {
    void (*notify)(void *);
    void *notify_arg;
} *sx_buf_t;

typedef struct sx_queue_node {
    void *data;
    struct sx_queue_node *front;
} *sx_queue_node_t;

typedef struct sx_queue {
    sx_queue_node_t front;
} *sx_queue_t;

typedef struct sx_st {
    int tag;
    sx_queue_t wbufq;
    void **plugin_data;
    struct {
        int nplugins;
        void **plugins;
    } *env;
} *sx_t;

typedef struct sx_plugin_st {
    int magic;
    int index;
    void *private;
} *sx_plugin_t;

#define GSASL_OK 0
#define GSASL_NEEDS_MORE 1
#define GSASL_AUTHENTICATION_ERROR 2
#define GSASL_NO_ANONYMOUS_TOKEN 3
#define GSASL_NO_AUTHID 4
#define GSASL_NO_AUTHZID 5
#define GSASL_NO_PASSWORD 6
#define GSASL_NO_PASSCODE 7
#define GSASL_NO_PIN 8
#define GSASL_NO_SERVICE 9
#define GSASL_NO_HOSTNAME 10
#define GSASL_UNKNOWN_MECHANISM 11
#define GSASL_MECHANISM_PARSE_ERROR 12
#define GSASL_BASE64_ERROR 13

#define GSASL_SERVICE 0
#define GSASL_REALM 1
#define GSASL_HOSTNAME 2

#define SX_SSL_MAGIC 0
#define ZONE 0
#define SX_CONN_EXTERNAL_ID_MAX_COUNT 10

enum {
    sx_sasl_cb_CHECK_MECH,
    sx_sasl_cb_GET_REALM,
    sx_sasl_cb_GEN_AUTHZID
};

enum {
    sx_sasl_ret_OK
};

static const char* _sasl_err_NOT_AUTHORIZED = "not-authorized";
static const char* _sasl_err_INVALID_MECHANISM = "invalid-mechanism";
static const char* _sasl_err_TEMPORARY_FAILURE = "temporary-failure";
static const char* _sasl_err_INCORRECT_ENCODING = "incorrect-encoding";
static const char* _sasl_err_MECH_TOO_WEAK = "mechanism-too-weak";
static const char* _sasl_err_MALFORMED_REQUEST = "malformed-request";

static int gsasl_server_support_p(Gsasl *ctx, const char *mech) { return 0; }
static int gsasl_server_start(Gsasl *ctx, const char *mech, Gsasl_session **sd) { return 0; }
static void* gsasl_session_hook_get(Gsasl_session *sd) { return NULL; }
static void gsasl_session_hook_set(Gsasl_session *sd, void *hook) {}
static void gsasl_property_set(Gsasl_session *sd, int prop, const char *data) {}
static int gsasl_base64_from(const char *in, int inlen, char **out, size_t *outlen) { return 0; }
static int gsasl_step(Gsasl_session *sd, const char *in, size_t inlen, char **out, size_t *outlen) { return 0; }
static int gsasl_base64_to(const char *in, size_t inlen, char **out, size_t *outlen) { return 0; }
static const char* gsasl_strerror(int err) { return ""; }

static void _sx_debug(int zone, const char *fmt, ...) {}
static void _sx_nad_write(void *s, void *nad, int flags) {}
static void* _sx_sasl_failure(void *s, const char *err, const char *text) { return NULL; }
static void* _sx_sasl_success(void *s, const char *data, size_t len) { return NULL; }
static void* _sx_sasl_challenge(void *s, const char *data, size_t len) { return NULL; }
static void _sx_sasl_notify_success(void *arg) {}