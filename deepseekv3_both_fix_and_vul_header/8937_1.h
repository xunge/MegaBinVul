#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _NMDevice NMDevice;

typedef struct _NMDevicePrivate {
    int rdisc_use_tempaddr;
    void *act_request;
    void *ac_ip6_config;
    int dhcp6_mode;
    int ip6_mtu;
} NMDevicePrivate;

typedef struct {
    int len;
    void *data;
} GArray;

typedef struct _NMRDisc {
    GArray *gateways;
    GArray *addresses;
    GArray *routes;
    GArray *dns_servers;
    GArray *dns_domains;
    int dhcp_level;
    int hop_limit;
    int mtu;
} NMRDisc;

typedef struct _NMRDiscGateway {
    struct in6_addr address;
} NMRDiscGateway;

typedef struct _NMRDiscAddress {
    struct in6_addr address;
    uint32_t timestamp;
    uint32_t lifetime;
    uint32_t preferred;
} NMRDiscAddress;

typedef struct _NMRDiscRoute {
    struct in6_addr network;
    struct in6_addr gateway;
    int plen;
} NMRDiscRoute;

typedef struct _NMRDiscDNSServer {
    struct in6_addr address;
} NMRDiscDNSServer;

typedef struct _NMRDiscDNSDomain {
    char *domain;
} NMRDiscDNSDomain;

typedef struct _NMPlatformIP6Address {
    struct in6_addr address;
    int plen;
    uint32_t timestamp;
    uint32_t lifetime;
    uint32_t preferred;
    int source;
    unsigned int flags;
} NMPlatformIP6Address;

typedef struct _NMPlatformIP6Route {
    struct in6_addr network;
    struct in6_addr gateway;
    int plen;
    int source;
    int metric;
} NMPlatformIP6Route;

typedef enum {
    NM_SETTING_IP6_CONFIG_PRIVACY_PREFER_TEMP_ADDR,
    NM_SETTING_IP6_CONFIG_PRIVACY_PREFER_PUBLIC_ADDR
} NMIP6Privacy;

typedef enum {
    NM_RDISC_DHCP_LEVEL_NONE,
    NM_RDISC_DHCP_LEVEL_MANAGED
} NMRDiscDHCPLevel;

typedef enum {
    NM_IP_CONFIG_SOURCE_RDISC
} NMIPConfigSource;

typedef enum {
    NM_DEVICE_STATE_FAILED
} NMDeviceState;

typedef int NMDeviceStateReason;
typedef unsigned int NMRDiscConfigMap;
typedef unsigned int guint;

#define NM_DEVICE_GET_PRIVATE(obj) ((NMDevicePrivate *)obj)
#define IFA_F_NOPREFIXROUTE (1 << 0)
#define IFA_F_MANAGETEMPADDR (1 << 1)

#define NM_RDISC_CONFIG_GATEWAYS (1 << 0)
#define NM_RDISC_CONFIG_ADDRESSES (1 << 1)
#define NM_RDISC_CONFIG_ROUTES (1 << 2)
#define NM_RDISC_CONFIG_DNS_SERVERS (1 << 3)
#define NM_RDISC_CONFIG_DNS_DOMAINS (1 << 4)
#define NM_RDISC_CONFIG_DHCP_LEVEL (1 << 5)
#define NM_RDISC_CONFIG_HOP_LIMIT (1 << 6)
#define NM_RDISC_CONFIG_MTU (1 << 7)

#define LOGD_DEVICE 0
#define LOGD_DHCP6 0

#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)

static inline void _LOGI(int flags, const char *fmt, ...) {}
static inline int g_snprintf(char *str, size_t size, const char *format, ...) { return 0; }

#define g_array_index(array, type, index) (((type*)((array)->data))[index])

void nm_ip6_config_set_gateway(void *config, struct in6_addr *addr);
void nm_ip6_config_reset_addresses(void *config);
void nm_ip6_config_add_address(void *config, NMPlatformIP6Address *addr);
void nm_ip6_config_reset_routes(void *config);
void nm_ip6_config_add_route(void *config, NMPlatformIP6Route *route);
void nm_ip6_config_reset_nameservers(void *config);
void nm_ip6_config_add_nameserver(void *config, struct in6_addr *addr);
void nm_ip6_config_reset_domains(void *config);
void nm_ip6_config_add_domain(void *config, const char *domain);
void nm_device_ipv6_sysctl_set(NMDevice *device, const char *property, const char *value);
void nm_device_activate_schedule_ip6_config_result(NMDevice *device);
int nm_device_get_ip_ifindex(NMDevice *device);
int nm_device_get_ip6_route_metric(NMDevice *device);
void *nm_ip6_config_new(int ifindex);
int nm_platform_check_support_libnl_extended_ifa_flags(void);
int nm_platform_check_support_kernel_extended_ifa_flags(void);
void nm_device_state_changed(NMDevice *device, NMDeviceState state, NMDeviceStateReason reason);
int dhcp6_start(NMDevice *device, int force, NMDeviceStateReason *reason);
void dhcp6_cleanup(NMDevice *device, int release, int wait);