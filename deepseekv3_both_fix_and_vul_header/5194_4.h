typedef void* GObject;
typedef void* GAsyncResult;
typedef void* gpointer;
typedef void* GSocketClient;
typedef void* GSocketConnection;
typedef void* GSocketConnectable;
typedef void* GError;
typedef void* GProxy;

#define FALSE 0
#define G_PROXY(obj) ((GProxy*)(obj))

typedef struct {
    GSocketClient *client;
    GSocketConnection *connection;
    GSocketConnectable *connectable;
    GError *last_error;
} GSocketClientAsyncConnectData;

typedef enum {
    G_SOCKET_CLIENT_PROXY_NEGOTIATED
} GSocketClientEvent;

void g_object_unref(void* obj);
void* g_proxy_connect_finish(GProxy* proxy, GAsyncResult* result, GError** error);
void g_socket_client_emit_event(GSocketClient* client, GSocketClientEvent event, GSocketConnectable* connectable, GSocketConnection* connection);
void enumerator_next_async(GSocketClientAsyncConnectData* data, ...);
void g_socket_client_tls_handshake(GSocketClientAsyncConnectData* data);