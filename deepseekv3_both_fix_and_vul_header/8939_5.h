#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    NM_ACT_STAGE_RETURN_FAILURE,
    NM_ACT_STAGE_RETURN_SUCCESS,
    NM_ACT_STAGE_RETURN_POSTPONE,
    NM_ACT_STAGE_RETURN_WAIT,
    NM_ACT_STAGE_RETURN_STOP
} NMActStageReturn;

typedef enum {
    NM_SETTING_IP6_CONFIG_PRIVACY_UNKNOWN,
    NM_SETTING_IP6_CONFIG_PRIVACY_DISABLED,
    NM_SETTING_IP6_CONFIG_PRIVACY_PREFER_PUBLIC_ADDR,
    NM_SETTING_IP6_CONFIG_PRIVACY_PREFER_TEMP_ADDR
} NMSettingIP6ConfigPrivacy;

typedef enum {
    NM_RDISC_DHCP_LEVEL_NONE,
    NM_RDISC_DHCP_LEVEL_MANAGED
} NMRDiscDHCPLevel;

typedef int NMDeviceStateReason;
typedef bool gboolean;
#define TRUE true
#define FALSE false

struct GSList {
    void *data;
    struct GSList *next;
};
typedef struct GSList GSList;

typedef struct _NMDevice NMDevice;
typedef struct _NMIP6Config NMIP6Config;
typedef struct _NMConnection NMConnection;
typedef struct _NMSettingIP6Config NMSettingIP6Config;
typedef struct _NMSettingIPConfig NMSettingIPConfig;
typedef struct _NMDeviceClass NMDeviceClass;
typedef struct _NMDevicePrivate NMDevicePrivate;

struct _NMDeviceClass {
    bool (*have_any_ready_slaves)(NMDevice *self, GSList *slaves);
};

struct _NMDevicePrivate {
    bool is_master;
    bool carrier;
    bool master;
    bool nm_ipv6ll;
    int ip6_mtu;
    NMRDiscDHCPLevel dhcp6_mode;
};

#define NM_DEVICE_GET_PRIVATE(obj) ((NMDevicePrivate *)0)
#define NM_DEVICE_GET_CLASS(obj) ((NMDeviceClass *)0)
#define NM_TYPE_SETTING_IP6_CONFIG (0)
#define NM_SETTING_IP6_CONFIG(obj) ((NMSettingIP6Config *)0)
#define NM_SETTING_IP6_CONFIG_METHOD_IGNORE "ignore"
#define NM_SETTING_IP6_CONFIG_METHOD_AUTO "auto"
#define NM_SETTING_IP6_CONFIG_METHOD_LINK_LOCAL "link-local"
#define NM_SETTING_IP6_CONFIG_METHOD_DHCP "dhcp"
#define NM_SETTING_IP6_CONFIG_METHOD_MANUAL "manual"
#define LOGD_IP6 (0)
#define LOGD_DEVICE (0)

#define _LOGI(flags, ...)
#define _LOGW(flags, ...)
#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)
#define g_assert(expr)
#define g_slist_free(list) free(list)

static bool connection_ip4_method_requires_carrier(NMConnection *connection, void *unused) { return false; }
static bool ip6_requires_slaves(NMConnection *connection) { return false; }
static GSList *nm_device_master_get_slaves(NMDevice *self) { return NULL; }
static const char *nm_device_get_ip_iface(NMDevice *self) { return NULL; }
static NMConnection *nm_device_get_connection(NMDevice *self) { return NULL; }
static bool nm_device_uses_assumed_connection(NMDevice *self) { return false; }
static void set_nm_ipv6ll(NMDevice *self, bool val) {}
static void nm_device_ipv6_sysctl_set(NMDevice *self, const char *key, const char *val) {}
static void restore_ip6_properties(NMDevice *self) {}
static void nm_device_ipv6_set_mtu(NMDevice *self, int mtu) {}
static void set_disable_ipv6(NMDevice *self, const char *val) {}
static NMSettingIP6ConfigPrivacy ip6_use_tempaddr(void) { return NM_SETTING_IP6_CONFIG_PRIVACY_UNKNOWN; }
static NMSettingIP6ConfigPrivacy use_tempaddr_clamp(NMSettingIP6ConfigPrivacy privacy) { return privacy; }
static bool addrconf6_start(NMDevice *self, NMSettingIP6ConfigPrivacy privacy) { return false; }
static NMActStageReturn linklocal6_start(NMDevice *self) { return NM_ACT_STAGE_RETURN_FAILURE; }
static bool dhcp6_start(NMDevice *self, bool val, NMDeviceStateReason *reason) { return false; }
static NMIP6Config *nm_ip6_config_new(int ifindex) { return NULL; }
static int nm_device_get_ip_ifindex(NMDevice *self) { return 0; }
static NMSettingIPConfig *nm_connection_get_setting_ip6_config(NMConnection *connection) { return NULL; }
static NMSettingIP6ConfigPrivacy nm_setting_ip6_config_get_ip6_privacy(NMSettingIP6Config *s_ip6) { return NM_SETTING_IP6_CONFIG_PRIVACY_UNKNOWN; }
static const char *nm_utils_get_ip_config_method(NMConnection *connection, int type) { return NULL; }