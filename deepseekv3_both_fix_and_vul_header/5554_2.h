#include <stdlib.h>
#include <string.h>

typedef struct libxl__gc libxl__gc;
typedef struct libxl_ctx libxl_ctx;
typedef struct flexarray_t flexarray_t;

typedef struct {
    int size;
    unsigned long *map;
} libxl_bitmap;

typedef struct {
    int nictype;
    int devid;
    unsigned char mac[6];
    const char *model;
    const char *bridge;
} libxl_device_nic;

typedef struct {
    const char *name;
} libxl_domain_create_info;

typedef struct {
    int val;
} libxl_defbool;

typedef struct {
    int type;
    const char *kernel;
    const char **extra;
    const char **extra_pv;
    const char **extra_hvm;
    int video_memkb;
    int max_vcpus;
    libxl_bitmap avail_vcpus;
    union {
        struct {
            const char *serial;
            const char **serial_list;
            const char *boot;
            const char *usbdevice;
            const char **usbdevice_list;
            const char *soundhw;
            libxl_defbool nographic;
            libxl_defbool usb;
            libxl_defbool acpi;
            libxl_defbool gfx_passthru;
            struct {
                int kind;
            } vga;
        } hvm;
    } u;
} libxl_domain_build_info;

typedef struct {
    libxl_domain_create_info c_info;
    libxl_domain_build_info b_info;
    libxl_device_nic *nics;
    int num_nics;
} libxl_domain_config;

typedef struct {
    const char *listen;
    int display;
    const char *passwd;
    libxl_defbool findunused;
} libxl_vnc_info;

typedef struct {
    libxl_defbool opengl;
} libxl_sdl_info;

typedef struct {
    const char *saved_state;
} libxl__domain_build_state;

#define LIBXL_MAC_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define LIBXL_MAC_BYTES(mac) (mac)[0], (mac)[1], (mac)[2], (mac)[3], (mac)[4], (mac)[5]
#define GCSPRINTF(...) libxl__sprintf(gc, __VA_ARGS__)
#define CTX ((libxl_ctx *)gc)

enum libxl_domain_type {
    LIBXL_DOMAIN_TYPE_PV,
    LIBXL_DOMAIN_TYPE_HVM
};

enum libxl_nic_type {
    LIBXL_NIC_TYPE_VIF_IOEMU
};

enum libxl_vga_interface_type {
    LIBXL_VGA_INTERFACE_TYPE_STD,
    LIBXL_VGA_INTERFACE_TYPE_CIRRUS,
    LIBXL_VGA_INTERFACE_TYPE_NONE
};

static inline int libxl_defbool_val(libxl_defbool b) { return b.val; }
static inline int libxl__sizekb_to_mb(int kb) { return kb / 1024; }
static inline char *libxl__sprintf(libxl__gc *gc, const char *fmt, ...) { return NULL; }
static inline char *libxl__device_nic_devname(libxl__gc *gc, int domid, int devid, int nictype) { return NULL; }
static inline const char *libxl_tapif_script(libxl__gc *gc) { return NULL; }
static inline char *libxl_bitmap_to_hex_string(libxl_ctx *ctx, libxl_bitmap *bitmap) { return NULL; }
static inline int libxl_bitmap_count_set(libxl_bitmap *bitmap) { return 0; }
static inline const libxl_vnc_info *libxl__dm_vnc(const libxl_domain_config *guest_config) { return NULL; }
static inline const libxl_sdl_info *dm_sdl(const libxl_domain_config *guest_config) { return NULL; }
static inline const char *dm_keymap(const libxl_domain_config *guest_config) { return NULL; }

static inline flexarray_t *flexarray_make(libxl__gc *gc, int size, int alloc_step) { return NULL; }
static inline void flexarray_vappend(flexarray_t *fa, ...) {}
static inline void flexarray_append(flexarray_t *fa, const char *str) {}
static inline void flexarray_append_pair(flexarray_t *fa, const char *key, const char *val) {}
static inline char **flexarray_contents(flexarray_t *fa) { return NULL; }

#define LOG(level, msg)