#include <stddef.h>
#include <pthread.h>

typedef struct _GObject {
    void* g_type_instance;
    unsigned int ref_count;
    void* qdata;
} GObject;

typedef struct _GObjectClass {
    void (*finalize)(GObject* object);
} GObjectClass;

typedef struct _GVfsDaemon {
    GObject parent_instance;
    void* jobs;
    unsigned int name_watcher;
    void* daemon_skeleton;
    void* mountable_skeleton;
    void* conn;
    void* auth_observer;
    void* registered_paths;
    void* client_connections;
    pthread_mutex_t lock;
} GVfsDaemon;

typedef void* GDBusInterfaceSkeleton;

#define G_VFS_DAEMON(object) ((GVfsDaemon*)(object))
#define G_OBJECT_CLASS(klass) ((GObjectClass*)(klass))
#define G_DBUS_INTERFACE_SKELETON(object) ((GDBusInterfaceSkeleton)(object))

extern GObjectClass* g_vfs_daemon_parent_class;
extern void g_warning(const char* format, ...);
extern void g_bus_unwatch_name(unsigned int watcher_id);
extern void g_dbus_interface_skeleton_unexport(void* skeleton);
extern void g_object_unref(void* object);
extern void g_hash_table_destroy(void* hash_table);
extern void g_mutex_clear(pthread_mutex_t* mutex);