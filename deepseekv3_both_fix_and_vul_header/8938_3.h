#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _NMIP4Config NMIP4Config;
typedef struct _NMConnection NMConnection;
typedef struct _NMSetting NMSetting;
typedef struct _NMDefaultRouteManager NMDefaultRouteManager;

struct _NMDevicePrivate {
    NMIP4Config *ip4_config;
    NMIP4Config *dev_ip4_config;
};

typedef struct _NMDevicePrivate NMDevicePrivate;
typedef struct _NMDevice NMDevice;

typedef enum {
    NM_DEVICE_STATE_REASON_NONE,
    NM_DEVICE_STATE_REASON_CONFIG_FAILED
} NMDeviceStateReason;

#define NM_IS_DEVICE(obj) (1)
#define NM_DEVICE_GET_PRIVATE(obj) ((NMDevicePrivate*)0)
#define NM_TYPE_DEVICE (0)
#define NM_TYPE_IP4_CONFIG (0)
#define NM_TYPE_SETTING_IP4_CONFIG (0)

#define gboolean bool
#define guint32 uint32_t
#define TRUE true
#define FALSE false

#define g_return_val_if_fail(expr, val) if (!(expr)) return val
#define g_object_ref(obj) (obj)
#define g_clear_object(ptr) (*(ptr) = NULL)
#define g_object_notify(obj, prop)
#define g_signal_emit(obj, sig, detail, ...)
#define g_object_unref(obj)
#define g_object_freeze_notify(obj)
#define g_object_thaw_notify(obj)

enum {
    IP4_CONFIG_CHANGED,
    SIGNAL_LAST
};
static uint32_t signals[SIGNAL_LAST];

#define LOGD_IP4 0
#define _LOGD(domain, ...)

#define NM_PLATFORM_ROUTE_METRIC_IP4_DEVICE_ROUTE 0

static const char* nm_device_get_ip_iface(NMDevice* self) { return NULL; }
static int nm_device_get_ip_ifindex(NMDevice* self) { return 0; }
static int nm_ip4_config_get_ifindex(NMIP4Config* config) { return 0; }
static bool nm_device_uses_assumed_connection(NMDevice* self) { return false; }
static bool nm_ip4_config_commit(NMIP4Config* config, int ifindex, uint32_t metric) { return false; }
static void nm_ip4_config_replace(NMIP4Config* old, NMIP4Config* new, bool* changes) {}
static const char* nm_ip4_config_get_dbus_path(NMIP4Config* config) { return NULL; }
static void nm_ip4_config_export(NMIP4Config* config) {}
static void nm_default_route_manager_ip4_update_default_route(NMDefaultRouteManager* mgr, NMDevice* dev) {}
static NMDefaultRouteManager* nm_default_route_manager_get() { return NULL; }
static void _update_ip4_address(NMDevice* self) {}
static bool nm_device_uses_generated_assumed_connection(NMDevice* self) { return false; }
static NMConnection* nm_device_get_connection(NMDevice* self) { return NULL; }
static void nm_connection_remove_setting(NMConnection* conn, int type) {}
static NMSetting* nm_ip4_config_create_setting(NMIP4Config* config) { return NULL; }
static void nm_connection_add_setting(NMConnection* conn, NMSetting* setting) {}
static void nm_device_queue_recheck_assume(NMDevice* self) {}