#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char* message;
    int domain;
    int code;
} GError;

typedef int gint;
typedef unsigned int guint;
typedef void* gpointer;
typedef const void* gconstpointer;
typedef void (*GDestroyNotify)(gpointer data);
typedef unsigned int (*GHashFunc)(gconstpointer key);
typedef int (*GEqualFunc)(gconstpointer a, gconstpointer b);
typedef void (*GCallback)(void);

#define FALSE 0
#define TRUE 1

typedef struct _GVfsDaemon {
    void* thread_pool;
    pthread_mutex_t lock;
    guint mount_counter;
    void* jobs;
    void* registered_paths;
    void* client_connections;
    void* conn;
    void* auth_observer;
    void* daemon_skeleton;
    void* mountable_skeleton;
} GVfsDaemon;

#define G_BUS_TYPE_SESSION 0
#define G_VFS_DBUS_DAEMON_PATH "/org/gtk/vfs/daemon"
#define G_VFS_DBUS_MOUNTABLE_PATH "/org/gtk/vfs/mountable"
#define G_CALLBACK(f) ((GCallback)(f))
#define G_DBUS_INTERFACE_SKELETON(obj) ((void*)(obj))

void job_handler_callback(gpointer data);
void registered_path_free(gpointer data);
bool authorize_authenticated_peer_cb(void* observer, void* stream, void* credentials, void* user_data);
bool handle_get_connection(void* object, void* invocation, const char* arg_object_path, GVfsDaemon* daemon);
bool handle_cancel(void* object, void* invocation, guint arg_id, GVfsDaemon* daemon);
bool handle_list_monitor_implementations(void* object, void* invocation, GVfsDaemon* daemon);
bool daemon_handle_mount(void* object, void* invocation, const char* arg_mount_spec, GVfsDaemon* daemon);

unsigned int g_str_hash(gconstpointer key);
int g_str_equal(gconstpointer a, gconstpointer b);
unsigned int g_direct_hash(gconstpointer key);
int g_direct_equal(gconstpointer a, gconstpointer b);
void g_free(gpointer data);
void g_object_unref(gpointer object);
void* g_thread_pool_new(void* func, void* user_data, int max_threads, int exclusive, GError** error);
void g_assert(int condition);
void g_mutex_init(pthread_mutex_t* mutex);
void* g_hash_table_new_full(GHashFunc hash_func, GEqualFunc key_equal_func, GDestroyNotify key_destroy_func, GDestroyNotify value_destroy_func);
void* g_bus_get_sync(int bus_type, void* cancellable, GError** error);
void* g_dbus_auth_observer_new();
void g_signal_connect(void* instance, const char* detailed_signal, GCallback c_handler, void* data);
void* gvfs_dbus_daemon_skeleton_new();
void* gvfs_dbus_mountable_skeleton_new();
bool g_dbus_interface_skeleton_export(void* skeleton, void* connection, const char* object_path, GError** error);
char* g_quark_to_string(int quark);
void g_error_free(GError* error);
void g_warning(const char* format, ...);