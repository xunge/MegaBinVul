#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

#define NM_SSH_KEY_REMOTE "remote"
#define NM_SSH_KEY_REMOTE_IP "remote-ip"
#define NM_SSH_KEY_LOCAL_IP "local-ip"
#define NM_SSH_KEY_NETMASK "netmask"
#define NM_SSH_KEY_AUTH_TYPE "auth-type"
#define NM_SSH_AUTH_TYPE_PASSWORD "password"
#define NM_SSH_AUTH_TYPE_KEY "key"
#define NM_SSH_AUTH_TYPE_SSH_AGENT "ssh-agent"
#define NM_SSH_KEY_KEY_FILE "key-file"
#define NM_SSH_KEY_PORT "port"
#define NM_SSH_DEFAULT_PORT 22
#define NM_SSH_KEY_TUNNEL_MTU "mtu"
#define NM_SSH_DEFAULT_MTU 1500
#define NM_SSH_KEY_EXTRA_OPTS "extra-opts"
#define NM_SSH_DEFAULT_EXTRA_OPTS ""
#define NM_SSH_KEY_REMOTE_DEV "remote-dev"
#define NM_SSH_DEFAULT_REMOTE_DEV 0
#define NM_SSH_KEY_REMOTE_USERNAME "remote-username"
#define NM_SSH_DEFAULT_REMOTE_USERNAME "root"
#define NM_SSH_KEY_TAP_DEV "tap-dev"
#define NM_SSH_KEY_IP_6 "ipv6"
#define NM_SSH_KEY_REMOTE_IP_6 "remote-ip6"
#define NM_SSH_KEY_LOCAL_IP_6 "local-ip6"
#define NM_SSH_KEY_NETMASK_6 "netmask6"
#define IFCONFIG "/sbin/ifconfig"
#define YES "yes"
#define AUTH_TYPE_KEY "AUTH_TYPE"
#define KEY_FILE_KEY "KEY_FILE"
#define REMOTE_KEY "REMOTE"
#define REMOTE_USERNAME_KEY "REMOTE_USERNAME"
#define REMOTE_IP_KEY "REMOTE_IP"
#define LOCAL_IP_KEY "LOCAL_IP"
#define NETMASK_KEY "NETMASK"
#define IP_6_KEY "IP_6"
#define REMOTE_IP_6_KEY "REMOTE_IP_6"
#define LOCAL_IP_6_KEY "LOCAL_IP_6"
#define NETMASK_6_KEY "NETMASK_6"
#define PORT_KEY "PORT"
#define MTU_KEY "MTU"
#define EXTRA_OPTS_KEY "EXTRA_OPTS"
#define REMOTE_DEV_KEY "REMOTE_DEV"
#define DEV_TYPE_KEY "DEV_TYPE"
#define TUNNEL_TYPE_KEY "TUNNEL_TYPE"

#define IS_YES(x) (x && !strcasecmp((x), "yes"))

typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct _GError GError;
typedef struct _NMVpnEditorPlugin NMVpnEditorPlugin;
typedef struct _NMConnection NMConnection;
typedef struct _NMSettingConnection NMSettingConnection;
typedef struct _NMSettingVpn NMSettingVpn;

#define NM_TYPE_SETTING_CONNECTION 0
#define NM_TYPE_SETTING_VPN 0

#define NM_SETTING_CONNECTION(x) ((NMSettingConnection*)(x))

static inline NMSettingConnection* nm_connection_get_setting(NMConnection *connection, int type) {
    return (NMSettingConnection*)connection;
}

static inline const char* nm_setting_vpn_get_data_item(NMSettingVpn *setting, const char *key) {
    return NULL;
}

static inline char* g_strdup(const char* str) {
    return str ? strdup(str) : NULL;
}

static inline void g_free(void* ptr) {
    free(ptr);
}

static inline char* g_strdup_printf(const char* format, ...) {
    char *buf = NULL;
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);
    
    if (len >= 0) {
        buf = malloc(len + 1);
        if (buf) {
            va_start(args, format);
            vsnprintf(buf, len + 1, format, args);
            va_end(args);
        }
    }
    return buf;
}

static inline char* g_strconcat(const char* first, ...) {
    size_t len = 0;
    va_list args;
    const char *arg;
    char *result, *p;
    
    va_start(args, first);
    for (arg = first; arg != NULL; arg = va_arg(args, const char*)) {
        len += strlen(arg);
    }
    va_end(args);
    
    result = malloc(len + 1);
    if (result) {
        p = result;
        va_start(args, first);
        for (arg = first; arg != NULL; arg = va_arg(args, const char*)) {
            strcpy(p, arg);
            p += strlen(arg);
        }
        va_end(args);
    }
    return result;
}

static inline void g_set_error(GError** err, int domain, int code, const char* format, ...) {
    (void)err; (void)domain; (void)code; (void)format;
}

static inline void g_assert(int condition) {
    if (!condition) abort();
}