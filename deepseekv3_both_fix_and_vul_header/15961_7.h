#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _NMConnection NMConnection;
typedef struct _NMVpnEditorPlugin NMVpnEditorPlugin;
typedef struct _NMSettingConnection NMSettingConnection;
typedef struct _NMSettingVpn NMSettingVpn;
typedef struct _GError {
    int domain;
    int code;
    char *message;
} GError;

#define SSH_EDITOR_PLUGIN_ERROR 0
#define SSH_EDITOR_PLUGIN_ERROR_FAILED 0

#define NM_DBUS_SERVICE_SSH "org.freedesktop.NetworkManager.ssh"
#define NM_SETTING_VPN_SERVICE_TYPE "service-type"
#define NM_SETTING(x) ((void*)(x))
#define NM_SETTING_CONNECTION(x) ((NMSettingConnection*)(x))
#define NM_SETTING_VPN(x) ((NMSettingVpn*)(x))

#define NM_SSH_KEY_REMOTE "remote"
#define NM_SSH_KEY_AUTH_TYPE "auth-type"
#define NM_SSH_AUTH_TYPE_SSH_AGENT "ssh-agent"
#define NM_SSH_KEY_REMOTE_USERNAME "remote-username"
#define NM_SSH_DEFAULT_REMOTE_USERNAME "root"
#define NM_SSH_KEY_KEY_FILE "key-file"
#define NM_SSH_KEY_REMOTE_IP "remote-ip"
#define NM_SSH_KEY_LOCAL_IP "local-ip"
#define NM_SSH_KEY_NETMASK "netmask"
#define NM_SSH_KEY_IP_6 "ip6"
#define NM_SSH_KEY_REMOTE_IP_6 "remote-ip6"
#define NM_SSH_KEY_LOCAL_IP_6 "local-ip6"
#define NM_SSH_KEY_NETMASK_6 "netmask6"
#define NM_SSH_KEY_PORT "port"
#define NM_SSH_DEFAULT_PORT 22
#define NM_SSH_KEY_TUNNEL_MTU "tunnel-mtu"
#define NM_SSH_DEFAULT_MTU 1500
#define NM_SSH_KEY_REMOTE_DEV "remote-dev"
#define NM_SSH_DEFAULT_REMOTE_DEV 0
#define NM_SSH_KEY_TAP_DEV "tap-dev"
#define NM_SSH_KEY_EXTRA_OPTS "extra-opts"
#define NM_SSH_DEFAULT_EXTRA_OPTS ""

#define REMOTE_KEY "remote"
#define AUTH_TYPE_KEY "auth-type"
#define REMOTE_USERNAME_KEY "remote-username"
#define KEY_FILE_KEY "key-file"
#define REMOTE_IP_KEY "remote-ip"
#define LOCAL_IP_KEY "local-ip"
#define NETMASK_KEY "netmask"
#define IP_6_KEY "ip6"
#define REMOTE_IP_6_KEY "remote-ip6"
#define LOCAL_IP_6_KEY "local-ip6"
#define NETMASK_6_KEY "netmask6"
#define PORT_KEY "port"
#define MTU_KEY "mtu"
#define REMOTE_DEV_KEY "remote-dev"
#define DEV_TYPE_KEY "dev-type"
#define EXTRA_OPTS_KEY "extra-opts"

static inline void g_set_error(GError **error, int domain, int code, const char *format, ...) {}
static inline int g_file_get_contents(const char *path, char **contents, size_t *length, GError **error) { return 0; }
static inline int g_utf8_validate(const char *str, ssize_t max_len, const char **end) { return 0; }
static inline char *g_locale_to_utf8(const char *str, ssize_t len, size_t *bytes_read, size_t *bytes_written, GError **error) { return NULL; }
static inline void g_error_free(GError *error) {}
static inline void g_free(void *p) {}
static inline void g_assert(void *expr) {}
static inline char **g_strsplit_set(const char *string, const char *delimiters, int max_tokens) { return NULL; }
static inline int g_strv_length(char **str_array) { return 0; }
static inline void g_strfreev(char **str_array) {}
static inline char *g_strdup(const char *str) { return NULL; }

static inline NMConnection *nm_simple_connection_new(void) { return NULL; }
static inline NMSettingConnection *nm_setting_connection_new(void) { return NULL; }
static inline NMSettingVpn *nm_setting_vpn_new(void) { return NULL; }
static inline void nm_connection_add_setting(NMConnection *connection, void *setting) {}
static inline void nm_setting_vpn_add_data_item(NMSettingVpn *setting, const char *key, const char *item) {}
static inline void g_object_set(void *object, const char *first_property_name, ...) {}
static inline void g_object_unref(void *object) {}

#define PARSE_IMPORT_KEY(key, nm_key, items, s_vpn) \
    if (!strncmp(items[0], key, strlen(items[0]))) { \
        nm_setting_vpn_add_data_item(s_vpn, nm_key, items[1]); \
        free(items); \
        continue; \
    }

#define PARSE_IMPORT_KEY_WITH_DEFAULT_VALUE_STR(key, nm_key, items, s_vpn, default_value) \
    if (!strncmp(items[0], key, strlen(items[0]))) { \
        if (strncmp(items[1], default_value, strlen(items[1]))) \
            nm_setting_vpn_add_data_item(s_vpn, nm_key, items[1]); \
        free(items); \
        continue; \
    }

#define PARSE_IMPORT_KEY_WITH_DEFAULT_VALUE_INT(key, nm_key, items, s_vpn, default_value) \
    if (!strncmp(items[0], key, strlen(items[0]))) { \
        int value = atoi(items[1]); \
        if (value != default_value) { \
            char *str_value = malloc(32); \
            sprintf(str_value, "%d", value); \
            nm_setting_vpn_add_data_item(s_vpn, nm_key, str_value); \
            free(str_value); \
        } \
        free(items); \
        continue; \
    }

#define PARSE_IMPORT_KEY_BOOL(key, nm_key, items, s_vpn, true_value) \
    if (!strncmp(items[0], key, strlen(items[0]))) { \
        int value = !strncmp(items[1], true_value, strlen(items[1])); \
        nm_setting_vpn_add_data_item(s_vpn, nm_key, value ? "yes" : "no"); \
        free(items); \
        continue; \
    }

/* Replace gchar with char */
#define gchar char