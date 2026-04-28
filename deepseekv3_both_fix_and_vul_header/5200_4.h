#include <stdbool.h>

typedef void* GObject;
typedef void* GAsyncResult;
typedef void* gpointer;
typedef void* GSocketClient;
typedef void* GIOStream;
typedef void* GSocketConnectable;
typedef void* GError;

#define G_TLS_CONNECTION(obj) ((void*)(obj))
#define G_IO_STREAM(obj) ((void*)(obj))
#define FALSE false

typedef enum {
    G_SOCKET_CLIENT_TLS_HANDSHAKED
} GSocketClientEvent;

typedef struct _GSocketClientAsyncConnectData GSocketClientAsyncConnectData;
struct _GSocketClientAsyncConnectData {
    GSocketClient *client;
    GIOStream *connection;
    GSocketConnectable *connectable;
    GError *last_error;
};

int g_tls_connection_handshake_finish(void* object, GAsyncResult *result, GError **error);
void g_object_unref(GObject *object);
void g_socket_client_emit_event(GSocketClient *client, GSocketClientEvent event, GSocketConnectable *connectable, GIOStream *connection);
void g_socket_client_async_connect_complete(GSocketClientAsyncConnectData *data);
void enumerator_next_async(GSocketClientAsyncConnectData *data, ...);