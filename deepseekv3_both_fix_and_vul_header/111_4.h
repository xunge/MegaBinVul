#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef uint32_t xs_transaction_t;
#define XBT_NULL 0

typedef struct libxl_ctx {
    struct xc_interface *xch;
} libxl_ctx;

typedef struct xc_interface {
} xc_interface;

typedef struct libxl__device {
    int backend_kind;
    int devid;
} libxl__device;

typedef struct libxl__egc {
} libxl__egc;

typedef struct libxl__gc {
    libxl_ctx *owner;
} libxl__gc;

typedef struct libxl__ao {
    libxl__gc *gc;
} libxl__ao;

typedef struct libxl__ao_device {
    libxl__ao *ao;
    int update_json;
    libxl__device *dev;
    int action;
    int rc;
    void (*callback)(libxl__egc*, struct libxl__ao_device*);
} libxl__ao_device;

typedef struct libxl__flock {
} libxl__flock;

typedef struct libxl_domain_config {
} libxl_domain_config;

typedef struct libxl_device_disk {
    char *vdev;
    int backend;
    char *pdev_path;
    char *script;
    int format;
    int readwrite;
    int is_cdrom;
    int direct_io_safe;
    int discard_enable;
    int trusted;
    int removable;
    uint32_t backend_domid;
    int colo_enable;
    char *colo_host;
    int colo_port;
    char *colo_export;
    char *active_disk;
    char *hidden_disk;
} libxl_device_disk;

typedef struct flexarray_t {
} flexarray_t;

typedef enum {
    LIBXL_DOMAIN_TYPE_INVALID,
    LIBXL_DOMAIN_TYPE_PV,
    LIBXL_DOMAIN_TYPE_HVM
} libxl_domain_type;

typedef enum {
    LIBXL_DISK_BACKEND_PHY,
    LIBXL_DISK_BACKEND_TAP,
    LIBXL_DISK_BACKEND_QDISK
} libxl_disk_backend;

typedef enum {
    LIBXL__DEVICE_KIND_VBD,
    LIBXL__DEVICE_KIND_QDISK
} libxl__device_kind;

typedef enum {
    LIBXL__DEVICE_ACTION_ADD
} libxl__device_action;

typedef enum {
    XenbusStateInitialising
} XenbusState;

static const struct {
} libxl__disk_devtype;

#define ERROR_FAIL (-1)
#define ERROR_LOCK_FAIL (-2)
#define ERROR_DEVICE_EXISTS (-3)
#define ERROR_INVAL (-4)

#define STATE_AO_GC(ao) libxl__gc *gc = libxl__gc_from_ao(ao)
#define GCNEW(ptr) (ptr) = libxl__zalloc(gc, sizeof(*(ptr)))
#define LOG(level, fmt, ...)
#define LOGD(level, domid, fmt, ...)
#define GCSPRINTF(fmt, ...) libxl__sprintf(gc, fmt, ##__VA_ARGS__)

static inline libxl__gc *libxl__gc_from_ao(libxl__ao *ao) { return ao->gc; }
static inline void *libxl__zalloc(libxl__gc *gc, size_t size) { return calloc(1, size); }
static inline char *libxl__sprintf(libxl__gc *gc, const char *fmt, ...) { return NULL; }
static inline char *libxl__strdup(libxl__gc *gc, const char *s) { return strdup(s); }
static inline char *libxl__abs_path(libxl__gc *gc, const char *path, const char *dir) { return NULL; }
static inline const char *libxl__xen_script_dir_path(void) { return NULL; }
static inline const char *libxl__device_disk_string_of_backend(libxl_disk_backend backend) { return NULL; }
static inline const char *libxl__device_disk_string_of_format(int format) { return NULL; }
static inline int libxl_defbool_val(int defbool) { return defbool; }
static inline libxl_domain_type libxl__domain_type(libxl__gc *gc, uint32_t domid) { return LIBXL_DOMAIN_TYPE_INVALID; }
static inline flexarray_t *flexarray_make(libxl__gc *gc, int size, int alloc) { return NULL; }
static inline void flexarray_append(flexarray_t *fa, const char *str) {}
static inline void flexarray_append_pair(flexarray_t *fa, const char *key, const char *val) {}
static inline char **libxl__xs_kvs_of_flexarray(libxl__gc *gc, flexarray_t *fa) { return NULL; }
static inline int libxl__device_disk_setdefault(libxl__gc *gc, uint32_t domid, libxl_device_disk *disk, int update_json) { return 0; }
static inline int libxl__device_from_disk(libxl__gc *gc, uint32_t domid, libxl_device_disk *disk, libxl__device *device) { return 0; }
static inline int libxl__device_exists(libxl__gc *gc, xs_transaction_t t, libxl__device *device) { return 0; }
static inline int libxl__xs_transaction_start(libxl__gc *gc, xs_transaction_t *t) { return 0; }
static inline int libxl__xs_transaction_commit(libxl__gc *gc, xs_transaction_t *t) { return 0; }
static inline void libxl__xs_transaction_abort(libxl__gc *gc, xs_transaction_t *t) {}
static inline void libxl__device_generic_add(libxl__gc *gc, xs_transaction_t t, libxl__device *device, char **back, char **front, char **ro_front) {}
static inline void libxl__wait_device_connection(libxl__egc *egc, libxl__ao_device *aodev) {}
static inline libxl__flock *libxl__lock_domain_userdata(libxl__gc *gc, uint32_t domid) { return NULL; }
static inline void libxl__unlock_file(libxl__flock *lock) {}
static inline int libxl__get_domain_configuration(libxl__gc *gc, uint32_t domid, libxl_domain_config *d_config) { return 0; }
static inline int libxl__set_domain_configuration(libxl__gc *gc, uint32_t domid, libxl_domain_config *d_config) { return 0; }
static inline int libxl__dm_check_start(libxl__gc *gc, libxl_domain_config *d_config, uint32_t domid) { return 0; }
static inline void device_add_domain_config(libxl__gc *gc, libxl_domain_config *d_config, const void *devtype, libxl_device_disk *disk) {}
static inline void libxl_domain_config_init(libxl_domain_config *d_config) {}
static inline void libxl_domain_config_dispose(libxl_domain_config *d_config) {}
static inline void libxl_device_disk_init(libxl_device_disk *disk) {}
static inline void libxl_device_disk_copy(libxl_ctx *ctx, libxl_device_disk *dst, libxl_device_disk *src) {}
static inline void libxl_device_disk_dispose(libxl_device_disk *disk) {}
static inline const char *xc_domain_get_native_protocol(xc_interface *xch, uint32_t domid) { return NULL; }