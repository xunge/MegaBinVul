#include <stdbool.h>
#include <stddef.h>

typedef struct _NMIP6Config NMIP6Config;
typedef struct _NMDevicePrivate {
    NMIP6Config *ip6_config;
    int ip6_mtu;
} NMDevicePrivate;

typedef struct _NMDevice NMDevice;
typedef struct _NMConnection NMConnection;
typedef struct _NMSetting NMSetting;

typedef enum {
    NM_DEVICE_STATE_REASON_NONE,
    NM_DEVICE_STATE_REASON_CONFIG_FAILED
} NMDeviceStateReason;

#define gboolean bool
#define TRUE true
#define FALSE false
#define G_OBJECT(obj) ((void*)(obj))
#define g_object_ref(obj) (obj)
#define g_object_unref(obj) 
#define g_object_notify(obj, prop) 
#define g_signal_emit(obj, sig, param, ...) 
#define g_object_freeze_notify(obj) 
#define g_object_thaw_notify(obj) 
#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)

#define NM_IS_DEVICE(obj) (1)
#define NM_DEVICE_GET_PRIVATE(obj) ((NMDevicePrivate*)0)
#define NM_TYPE_DEVICE (0)
#define NM_TYPE_IP6_CONFIG (0)
#define NM_TYPE_SETTING_IP6_CONFIG (0)

const char* nm_device_get_ip_iface(NMDevice* self) { return NULL; }
int nm_device_get_ip_ifindex(NMDevice* self) { return 0; }
int nm_ip6_config_get_ifindex(NMIP6Config* config) { return 0; }
bool nm_ip6_config_commit(NMIP6Config* config, int ifindex) { return true; }
void nm_ip6_config_replace(NMIP6Config* old, NMIP6Config* new, bool* changes) {}
const char* nm_ip6_config_get_dbus_path(NMIP6Config* config) { return NULL; }
void nm_ip6_config_export(NMIP6Config* config) {}
void nm_default_route_manager_ip6_update_default_route(void* manager, NMDevice* self) {}
void* nm_default_route_manager_get() { return NULL; }
bool nm_device_uses_generated_assumed_connection(NMDevice* self) { return false; }
NMConnection* nm_device_get_connection(NMDevice* self) { return NULL; }
void nm_connection_remove_setting(NMConnection* conn, int type) {}
NMSetting* nm_ip6_config_create_setting(NMIP6Config* config) { return NULL; }
void nm_connection_add_setting(NMConnection* conn, NMSetting* setting) {}
void nm_device_queue_recheck_assume(NMDevice* self) {}
void nm_device_ipv6_set_mtu(NMDevice* self, int mtu) {}

enum {
    IP6_CONFIG_CHANGED,
    LAST_SIGNAL
};
static unsigned int signals[LAST_SIGNAL];

#define LOGD_IP4 0
#define LOGD_IP6 0
#define _LOGD(domain, ...)