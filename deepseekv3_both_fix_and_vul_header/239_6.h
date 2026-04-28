#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _GVfsDBusDaemon GVfsDBusDaemon;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef struct _GVfsDaemon {
    void *auth_observer;
} GVfsDaemon;
typedef struct _GDBusServer GDBusServer;
typedef struct _GError {
    int domain;
    int code;
    char *message;
} GError;
typedef struct _GDBusConnection GDBusConnection;

typedef struct NewConnectionData {
    GVfsDaemon *daemon;
    char *socket_dir;
    GDBusConnection *conn;
    GDBusServer *server;
} NewConnectionData;

typedef int gboolean;
#define TRUE 1
#define FALSE 0
typedef void* gpointer;
typedef char gchar;

#define G_VFS_DAEMON(obj) ((GVfsDaemon*)obj)
#define G_DBUS_SERVER_FLAGS_NONE 0
#define G_CALLBACK(f) ((void (*)())f)

static void generate_address(gchar **address, char **socket_dir) {
    *address = strdup("unix:tmpdir=/tmp/gvfs");
    *socket_dir = strdup("/tmp/gvfs");
}

static gboolean daemon_new_connection_func(GDBusServer *server, GDBusConnection *conn, gpointer user_data) {
    return TRUE;
}

static void new_connection_data_free(NewConnectionData *data) {
    free(data->socket_dir);
    free(data);
}

static void* g_new(size_t size) {
    return calloc(1, size);
}

void g_free(void *ptr) {
    free(ptr);
}

gchar* g_dbus_generate_guid(void) {
    return strdup("12345678-1234-1234-1234-123456789abc");
}

void g_dbus_method_invocation_return_gerror(GDBusMethodInvocation *invocation, GError *error) {}

void g_printerr(const char *format, ...) {}

void g_error_free(GError *error) {
    free(error->message);
    free(error);
}

void g_dbus_server_start(GDBusServer *server) {}

GDBusServer* g_dbus_server_new_sync(const char *address, int flags, const char *guid, void *observer, void *cancellable, GError **error) {
    return NULL;
}

void g_signal_connect(GDBusServer *server, const char *signal, void (*callback)(), gpointer user_data) {}

void gvfs_dbus_daemon_complete_get_connection(GVfsDBusDaemon *object, GDBusMethodInvocation *invocation, gchar *address, const char *str) {}

#define g_new(type, count) ((type*)g_new(sizeof(type) * (count)))