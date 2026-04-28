#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct libxl__gc libxl__gc;
typedef struct flexarray_t flexarray_t;

typedef struct {
    int val;
} libxl_defbool;

typedef struct {
    const char *script;
    const char *ifname;
    const char *coloft_forwarddev;
    uint8_t mac[6];
    const char *ip;
    const char *gatewaydev;
    uint64_t rate_bytes_per_interval;
    uint32_t rate_interval_usecs;
    unsigned int mtu;
    const char *bridge;
    int devid;
    int nictype;
    const char *colo_sock_mirror_id;
    const char *colo_sock_mirror_ip;
    const char *colo_sock_mirror_port;
    const char *colo_sock_compare_pri_in_id;
    const char *colo_sock_compare_pri_in_ip;
    const char *colo_sock_compare_pri_in_port;
    const char *colo_sock_compare_sec_in_id;
    const char *colo_sock_compare_sec_in_ip;
    const char *colo_sock_compare_sec_in_port;
    const char *colo_sock_compare_notify_id;
    const char *colo_sock_compare_notify_ip;
    const char *colo_sock_compare_notify_port;
    const char *colo_sock_redirector0_id;
    const char *colo_sock_redirector0_ip;
    const char *colo_sock_redirector0_port;
    const char *colo_sock_redirector1_id;
    const char *colo_sock_redirector1_ip;
    const char *colo_sock_redirector1_port;
    const char *colo_sock_redirector2_id;
    const char *colo_sock_redirector2_ip;
    const char *colo_sock_redirector2_port;
    const char *colo_filter_mirror_queue;
    const char *colo_filter_mirror_outdev;
    const char *colo_filter_redirector0_queue;
    const char *colo_filter_redirector0_indev;
    const char *colo_filter_redirector0_outdev;
    const char *colo_filter_redirector1_queue;
    const char *colo_filter_redirector1_indev;
    const char *colo_filter_redirector1_outdev;
    const char *colo_compare_pri_in;
    const char *colo_compare_sec_in;
    const char *colo_compare_out;
    const char *colo_compare_notify_dev;
    const char *colo_sock_sec_redirector0_id;
    const char *colo_sock_sec_redirector0_ip;
    const char *colo_sock_sec_redirector0_port;
    const char *colo_sock_sec_redirector1_id;
    const char *colo_sock_sec_redirector1_ip;
    const char *colo_sock_sec_redirector1_port;
    const char *colo_filter_sec_redirector0_queue;
    const char *colo_filter_sec_redirector0_indev;
    const char *colo_filter_sec_redirector0_outdev;
    const char *colo_filter_sec_redirector1_queue;
    const char *colo_filter_sec_redirector1_indev;
    const char *colo_filter_sec_redirector1_outdev;
    const char *colo_filter_sec_rewriter0_queue;
    const char *colo_checkpoint_host;
    const char *colo_checkpoint_port;
    libxl_defbool trusted;
} libxl_device_nic;

#define LIBXL_MAC_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define LIBXL_MAC_BYTES(mac) (mac)[0], (mac)[1], (mac)[2], (mac)[3], (mac)[4], (mac)[5]
#define LIBXL_DEVICE_NIC_MTU_DEFAULT 0
#define GCSPRINTF(...) NULL

static inline char *libxl__strdup(libxl__gc *gc, const char *s) { return NULL; }
static inline char *libxl__abs_path(libxl__gc *gc, const char *s, const char *d) { return NULL; }
static inline const char *libxl_nic_type_to_string(int nictype) { return NULL; }
static inline int libxl_defbool_val(libxl_defbool b) { return 0; }
static inline void flexarray_grow(flexarray_t *a, int n) {}
static inline void flexarray_append(flexarray_t *a, const char *s) {}
static inline void flexarray_append_pair(flexarray_t *a, const char *k, const char *v) {}
static inline const char *libxl__xen_script_dir_path(void) { return NULL; }