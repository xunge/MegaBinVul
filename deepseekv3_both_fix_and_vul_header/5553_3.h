#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <inttypes.h>

#define HVM_BELOW_4G_MMIO_START (0xE0000000)
#define LIBXL_MAC_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define LIBXL_MAC_BYTES(mac) (mac)[0], (mac)[1], (mac)[2], (mac)[3], (mac)[4], (mac)[5]
#define LIBXL_CHANNEL_CONNECTION_PTY 1
#define LIBXL_CHANNEL_CONNECTION_SOCKET 2
#define LIBXL_NIC_TYPE_VIF_IOEMU 1
#define LIBXL_DOMAIN_TYPE_PV 1
#define LIBXL_DOMAIN_TYPE_HVM 2
#define LIBXL_VGA_INTERFACE_TYPE_STD 1
#define LIBXL_VGA_INTERFACE_TYPE_CIRRUS 2
#define LIBXL_VGA_INTERFACE_TYPE_NONE 3
#define LIBXL_VENDOR_DEVICE_XENSERVER 1
#define LIBXL_DISK_FORMAT_EMPTY 0
#define LIBXL_DISK_FORMAT_RAW 1
#define LIBXL_DISK_BACKEND_TAP 1

typedef struct libxl__gc libxl__gc;
typedef struct libxl_ctx libxl_ctx;
typedef struct flexarray_t flexarray_t;

typedef struct {
    const char *name;
} libxl_domain_create_info;

typedef struct {
    const char *listen;
    int display;
    const char *passwd;
    int findunused;
} libxl_vnc_info;

typedef struct {
    int dummy;
} libxl_sdl_info;

typedef struct {
    int enable;
    int vdagent;
    int usbredirection;
} libxl_spice_info;

typedef struct {
    int kind;
} libxl_vga_interface_info;

typedef struct {
    const char *boot;
    const char *soundhw;
    const char *serial;
    char **serial_list;
    const char *usbdevice;
    char **usbdevice_list;
    int usbversion;
    libxl_spice_info spice;
    int mmio_hole_memkb;
    libxl_vga_interface_info vga;
    int nographic;
    int acpi;
    int gfx_passthru;
    int xen_platform_pci;
    int usb;
    int vendor_device;
} libxl_hvm_build_info;

typedef struct {
    int type;
    const char *kernel;
    const char *ramdisk;
    const char *cmdline;
    uint64_t max_memkb;
    uint64_t video_memkb;
    int max_vcpus;
    struct {
        int size;
    } avail_vcpus;
    char **extra;
    char **extra_pv;
    char **extra_hvm;
    union {
        libxl_hvm_build_info hvm;
    } u;
} libxl_domain_build_info;

typedef struct {
    const char *pdev_path;
    const char *vdev;
    int format;
    int is_cdrom;
    int backend;
} libxl_device_disk;

typedef struct {
    int nictype;
    unsigned char mac[6];
    const char *model;
    int devid;
} libxl_device_nic;

typedef struct {
    int connection;
    int devid;
    union {
        struct {
            const char *path;
        } socket;
    } u;
} libxl_device_channel;

typedef struct {
    libxl_domain_create_info c_info;
    libxl_domain_build_info b_info;
    libxl_device_disk *disks;
    libxl_device_nic *nics;
    libxl_device_channel *channels;
    int num_disks;
    int num_nics;
    int num_channels;
} libxl_domain_config;

typedef struct {
    const char *saved_state;
} libxl__domain_build_state;

static inline libxl_ctx *libxl__gc_owner(libxl__gc *gc) { return NULL; }
static inline const char *libxl__run_dir_path(void) { return NULL; }
static inline const libxl_vnc_info *libxl__dm_vnc(const libxl_domain_config *config) { return NULL; }
static inline const libxl_sdl_info *dm_sdl(const libxl_domain_config *config) { return NULL; }
static inline const char *dm_keymap(const libxl_domain_config *config) { return NULL; }
static inline char *dm_spice_options(libxl__gc *gc, const libxl_spice_info *spice) { return NULL; }
static inline flexarray_t *flexarray_make(libxl__gc *gc, int size, int alloc) { return NULL; }
static inline void flexarray_append(flexarray_t *fa, void *elem) {}
static inline void flexarray_vappend(flexarray_t *fa, ...) {}
static inline void flexarray_append_pair(flexarray_t *fa, const char *key, const char *val) {}
static inline void *flexarray_contents(flexarray_t *fa) { return NULL; }
static inline char *libxl__sprintf(libxl__gc *gc, const char *fmt, ...) { return NULL; }
static inline int libxl_bitmap_count_set(const void *bitmap) { return 0; }
static inline uint64_t libxl__sizekb_to_mb(uint64_t kb) { return kb / 1024; }
static inline const char *libxl__device_nic_devname(libxl__gc *gc, int domid, int devid, int nictype) { return NULL; }
static inline const char *libxl_tapif_script(libxl__gc *gc) { return NULL; }
static inline const char *qemu_disk_format_string(int format) { return NULL; }
static inline const char *libxl__blktap_devpath(libxl__gc *gc, const char *pdev_path, int format) { return NULL; }
static inline int libxl__device_disk_dev_number(const char *vdev, int *disk, int *part) { return 0; }
static inline int libxl_defbool_val(int defbool) { return defbool; }

#define GCSPRINTF(fmt, ...) libxl__sprintf(gc, fmt, ##__VA_ARGS__)
#define LOG(level, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define LIBXL__LOG(ctx, level, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)