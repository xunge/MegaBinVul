#include <stddef.h>

typedef struct _GSocketClientAsyncConnectData {
    void *client;
    void *connectable;
    void *enumerator;
    void *socket;
    void *proxy_addr;
    void *connection;
    void *task;
} GSocketClientAsyncConnectData;

typedef int gboolean;

#define G_SOCKET_CLIENT_RESOLVING 0

void g_clear_object(void **object);
void g_object_ref(void *object);
void g_socket_client_emit_event(void *client, int event_type, void *connectable, void *user_data);
void g_socket_address_enumerator_next_async(void *enumerator, void *cancellable, void (*callback)(void), void *user_data);
void *g_task_get_cancellable(void *task);
void g_socket_client_enumerator_callback(void);