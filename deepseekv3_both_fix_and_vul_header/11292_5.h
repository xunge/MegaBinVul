#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct QIOChannel QIOChannel;
typedef struct QIOChannelTLS QIOChannelTLS;
typedef struct Error Error;
typedef struct QCryptoTLSCreds QCryptoTLSCreds;

struct NBDClient {
    QIOChannel *ioc;
    QCryptoTLSCreds *tlscreds;
    const char *tlsaclname;
};

struct NBDTLSHandshakeData {
    void *loop;
    bool complete;
    Error *error;
};

#define TRACE(fmt, ...)
#define NBD_REP_ACK 0
#define NBD_REP_ERR_INVALID 1
#define NBD_OPT_STARTTLS 1
#define QIO_CHANNEL(obj) ((QIOChannel *)obj)
#define OBJECT(obj) ((void *)obj)
#define FALSE 0

typedef void (*nbd_tls_handshake_func)(void *source, void *res, void *user_data);
static nbd_tls_handshake_func nbd_tls_handshake = NULL;

extern int nbd_negotiate_drop_sync(QIOChannel *ioc, uint32_t length);
extern int nbd_negotiate_send_rep(QIOChannel *ioc, uint32_t type, uint32_t opt);
extern void nbd_negotiate_send_rep_err(QIOChannel *ioc, uint32_t error, uint32_t opt, const char *msg);
extern void qio_channel_set_name(QIOChannel *ioc, const char *name);
extern QIOChannelTLS *qio_channel_tls_new_server(QIOChannel *ioc, QCryptoTLSCreds *creds, const char *aclname, Error **errp);
extern void qio_channel_tls_handshake(QIOChannelTLS *ioc, nbd_tls_handshake_func callback, void *opaque, void *destroy);
extern void object_unref(void *obj);
extern void error_free(Error *err);
extern void *g_main_loop_new(void *context, bool is_running);
extern void g_main_loop_run(void *loop);
extern void g_main_loop_unref(void *loop);
extern void *g_main_context_default(void);

typedef struct NBDClient NBDClient;