#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define G_SOURCE_CONTINUE TRUE
#define G_SOURCE_REMOVE FALSE
#define FIND_AUTH_END_ABORT (-2)

typedef struct _Buffer Buffer;
typedef struct _ProxySide ProxySide;
typedef struct _FlatpakProxyClient FlatpakProxyClient;
typedef struct _FlatpakProxy FlatpakProxy;

typedef void* GSocket;
typedef void* GError;
typedef void* GBytes;
typedef void* GSource;
typedef void* GObject;
typedef int GIOCondition;
typedef void* gpointer;
typedef int gboolean;
typedef unsigned long gsize;
typedef long gssize;
typedef uint8_t guint8;

struct _Buffer {
    guint8 *data;
    gsize size;
    gsize pos;
    gboolean send_credentials;
};

struct _ProxySide {
    FlatpakProxyClient *client;
    Buffer header_buffer;
    Buffer *current_read_buffer;
    GBytes *extra_input_data;
    GSource *in_source;
    gboolean closed;
    gboolean got_first_byte;
};

struct _FlatpakProxy {
    gboolean log_messages;
};

struct _FlatpakProxyClient {
    gboolean authenticated;
    ProxySide client_side;
    FlatpakProxy *proxy;
};

static Buffer *buffer_new(gsize size, Buffer *parent);
static gboolean buffer_read(ProxySide *side, Buffer *buffer, GSocket *socket);
static void buffer_unref(Buffer *buffer);
static void got_buffer_from_side(ProxySide *side, Buffer *buffer);
static void side_closed(ProxySide *side);
static gssize find_auth_end(FlatpakProxyClient *client, Buffer *buffer);
static void g_object_ref(GObject *object);
static void g_object_unref(GObject *object);
static GBytes *g_bytes_new(const void *data, gsize size);
static void g_print(const char *format, ...);
static void g_warning(const char *format, ...);
static gssize g_dbus_message_bytes_needed(const void *blob, gsize size, GError **error);