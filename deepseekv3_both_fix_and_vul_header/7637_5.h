#include <sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

typedef struct _MetaBackend MetaBackend;
typedef struct _MetaSettings MetaSettings;
typedef struct _MetaBackendClass {
    void (*post_init)(MetaBackend *backend);
} MetaBackendClass;
typedef struct _MetaDbusRealtimeKit1 MetaDbusRealtimeKit1;
typedef struct _MetaBackendNative MetaBackendNative;
typedef struct _GError {
    char *message;
} GError;

extern MetaBackendClass meta_backend_native_parent_class;

#define META_BACKEND_CLASS(klass) (&(klass))
#define META_BACKEND_NATIVE(backend) ((MetaBackendNative *)(backend))
#define META_EXPERIMENTAL_FEATURE_RT_SCHEDULER 0
#define G_BUS_TYPE_SYSTEM 0
#define G_DBUS_PROXY_FLAGS_DO_NOT_LOAD_PROPERTIES (1 << 0)
#define G_DBUS_PROXY_FLAGS_DO_NOT_CONNECT_SIGNALS (1 << 1)
#define G_DBUS_PROXY_FLAGS_DO_NOT_AUTO_START (1 << 2)
#define SCHED_RESET_ON_FORK (1 << 31)

pid_t gettid(void);

MetaSettings *meta_backend_get_settings(MetaBackend *backend);
int meta_settings_is_experimental_feature_enabled(MetaSettings *settings, int feature);
void maybe_disable_screen_cast_dma_bufs(MetaBackendNative *backend);
void update_viewports(MetaBackend *backend);
MetaDbusRealtimeKit1 *meta_dbus_realtime_kit1_proxy_new_for_bus_sync(int, int, const char *, const char *, void *, GError **);
int meta_dbus_realtime_kit1_call_make_thread_realtime_sync(MetaDbusRealtimeKit1 *, pid_t, uint32_t, void *, GError **);
void g_dbus_error_strip_remote_error(GError *);
void g_message(const char *, ...);
void g_warning(const char *, ...);

/* Replace g_autoptr with standard pointers */
#define g_autoptr(type) type*