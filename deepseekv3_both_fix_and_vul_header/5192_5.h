#include <stdbool.h>

typedef struct _GSocketClientAsyncConnectData GSocketClientAsyncConnectData;
typedef struct _GSocketClientPrivate GSocketClientPrivate;
typedef struct _GIOStream GIOStream;
typedef struct _GSocketClient GSocketClient;
typedef struct _GSocketConnectable GSocketConnectable;
typedef struct _GError GError;
typedef struct _GTask GTask;
typedef struct _GObject GObject;
typedef struct _GAsyncResult GAsyncResult;

typedef unsigned int GTlsCertificateFlags;
typedef unsigned int GSocketClientEvent;
typedef void* gpointer;
typedef bool gboolean;

#define G_SOCKET_CLIENT_TLS_HANDSHAKING 0
#define G_PRIORITY_DEFAULT 0
#define G_TLS_CLIENT_CONNECTION(x) ((void*)x)
#define G_TLS_CONNECTION(x) ((void*)x)
#define G_IO_STREAM(x) ((void*)x)
#define FALSE 0

struct _GSocketClient {
    GSocketClientPrivate *priv;
};

struct _GSocketClientPrivate {
    gboolean tls;
    GTlsCertificateFlags tls_validation_flags;
};

struct _GSocketClientAsyncConnectData {
    GSocketClient *client;
    GIOStream *connection;
    GSocketConnectable *connectable;
    GError *last_error;
    GTask *task;
};

void g_socket_client_async_connect_complete(GSocketClientAsyncConnectData *data);
void g_socket_client_emit_event(GSocketClient *client, GSocketClientEvent event, GSocketConnectable *connectable, GIOStream *connection);
void enumerator_next_async(GSocketClientAsyncConnectData *data, ...);
void g_socket_client_tls_handshake_callback(GObject *source, GAsyncResult *result, gpointer user_data);
GIOStream* g_tls_client_connection_new(GIOStream *connection, GSocketConnectable *connectable, GError **error);
void g_tls_client_connection_set_validation_flags(void *connection, GTlsCertificateFlags flags);
void g_tls_connection_handshake_async(void *connection, int priority, void *cancellable, void (*callback)(GObject*, GAsyncResult*, gpointer), gpointer user_data);
void* g_task_get_cancellable(GTask *task);