#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef bool gboolean;
typedef uint32_t guint32;

#define FALSE false
#define TRUE true
#define NULL ((void*)0)

typedef struct _NMIP4Config {
    char _placeholder;  // Dummy member to allow sizeof calculation
} NMIP4Config;

typedef struct _NMIP4ConfigPrivate {
    void *addresses;
} NMIP4ConfigPrivate;

typedef struct _NMPlatformIP4Route {
    guint32 network;
    guint32 gateway;
    guint32 metric;
    uint8_t plen;
} NMPlatformIP4Route;

typedef struct {
    void *data;
    size_t len;
    size_t alloc;
} GArray;

#define NM_IP4_CONFIG_GET_PRIVATE(obj) ((NMIP4ConfigPrivate*)((char*)(obj) + sizeof(NMIP4Config)))

static inline void g_return_val_if_fail(int expr, gboolean val) {
    if (!(expr)) exit(1);
}

static inline GArray* g_array_sized_new(gboolean zero_terminated, gboolean clear, size_t element_size, size_t reserved_size) {
    GArray *array = malloc(sizeof(GArray));
    array->data = malloc(element_size * reserved_size);
    array->len = 0;
    array->alloc = reserved_size;
    return array;
}

static inline void g_array_append_vals(GArray *array, const void *data, size_t len) {
    // Simplified implementation
    memcpy((char*)array->data + array->len * sizeof(NMPlatformIP4Route), data, len * sizeof(NMPlatformIP4Route));
    array->len += len;
}

static inline void g_array_unref(GArray *array) {
    free(array->data);
    free(array);
}

extern guint32 nm_ip4_config_get_mtu(const NMIP4Config *config);
extern int nm_ip4_config_get_num_routes(const NMIP4Config *config);
extern const NMPlatformIP4Route *nm_ip4_config_get_route(const NMIP4Config *config, int i);
extern gboolean nm_ip4_config_destination_is_direct(const NMIP4Config *config, guint32 network, uint8_t plen);
extern void *nm_route_manager_get(void);
extern gboolean nm_platform_ip4_address_sync(int ifindex, void *addresses, guint32 default_route_metric);
extern gboolean nm_route_manager_ip4_route_sync(void *manager, int ifindex, void *routes);
extern guint32 nm_platform_link_get_mtu(int ifindex);
extern void nm_platform_link_set_mtu(int ifindex, guint32 mtu);