#include <stdint.h>
#include <stddef.h>

typedef struct _GTlsConnectionBase GTlsConnectionBase;
typedef struct _GTlsCertificate GTlsCertificate;
typedef struct _GSocketConnectable GSocketConnectable;
typedef struct _GTlsDatabase GTlsDatabase;
typedef struct _GTlsInteraction GTlsInteraction;
typedef struct _GTlsClientConnection GTlsClientConnection;
typedef struct _GDtlsClientConnection GDtlsClientConnection;
typedef struct _GTlsConnection GTlsConnection;

typedef struct _GError {
    int domain;
    int code;
    char *message;
} GError;

typedef int gboolean;
typedef uint32_t GTlsCertificateFlags;

#define G_IS_TLS_CLIENT_CONNECTION(obj) (0)
#define G_TLS_CLIENT_CONNECTION(obj) ((GTlsClientConnection*)obj)
#define G_DTLS_CLIENT_CONNECTION(obj) ((GDtlsClientConnection*)obj)
#define G_TLS_CONNECTION(obj) ((GTlsConnection*)obj)

enum {
    G_TLS_CERTIFICATE_BAD_IDENTITY = 1 << 0,
    G_TLS_CERTIFICATE_UNKNOWN_CA = 1 << 1
};

enum {
    G_TLS_DATABASE_PURPOSE_AUTHENTICATE_SERVER,
    G_TLS_DATABASE_PURPOSE_AUTHENTICATE_CLIENT,
    G_TLS_DATABASE_VERIFY_NONE
};

gboolean g_tls_connection_base_is_dtls(GTlsConnectionBase *tls);
GSocketConnectable* g_tls_client_connection_get_server_identity(GTlsClientConnection *conn);
GSocketConnectable* g_dtls_client_connection_get_server_identity(GDtlsClientConnection *conn);
GTlsDatabase* g_tls_connection_get_database(GTlsConnection *conn);
GTlsCertificateFlags g_tls_certificate_verify(GTlsCertificate *cert, GSocketConnectable *identity, GError **error);
GTlsCertificateFlags g_tls_database_verify_chain(GTlsDatabase *database, GTlsCertificate *cert, int purpose, GSocketConnectable *identity, GTlsInteraction *interaction, int flags, GTlsCertificate *trusted_ca, GError **error);
GTlsInteraction* g_tls_connection_get_interaction(GTlsConnection *conn);
void g_tls_log_debug(GTlsConnectionBase *tls, const char *format, ...);
void g_assert(gboolean expr);
void g_clear_error(GError **error);