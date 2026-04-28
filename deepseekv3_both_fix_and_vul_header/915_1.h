#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PCI_BDF "%04x:%02x:%02x.%01x"
#define ERROR_FAIL -1
#define DOMID_IO 0x7FF0

typedef struct libxl__gc libxl__gc;
typedef struct libxl_ctx libxl_ctx;
typedef struct libxl_device_pci libxl_device_pci;
typedef struct xc_interface xc_interface;

struct libxl_device_pci {
    uint16_t domain;
    uint8_t bus;
    uint8_t dev;
    uint8_t func;
};

struct libxl_ctx {
    xc_interface *xch;
};

#define LOG(level, fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#define LOGE(level, fmt, ...) fprintf(stderr, fmt ": %s\n", ##__VA_ARGS__, strerror(errno))
#define GCSPRINTF(...) NULL

static libxl_ctx *libxl__gc_owner(libxl__gc *gc) { return NULL; }
static int xc_deassign_device(xc_interface *xch, uint32_t domid, const char *bdf) { return 0; }
static char *pcidev_encode_bdf(libxl_device_pci *pcidev) { return NULL; }
static int pciback_dev_is_assigned(libxl__gc *gc, libxl_device_pci *pcidev) { return 0; }
static void pciback_dev_unassign(libxl__gc *gc, libxl_device_pci *pcidev) {}
static char *pci_assignable_driver_path_read(libxl__gc *gc, libxl_device_pci *pcidev) { return NULL; }
static int sysfs_write_bdf(libxl__gc *gc, const char *path, libxl_device_pci *pcidev) { return 0; }
static void pci_assignable_driver_path_remove(libxl__gc *gc, libxl_device_pci *pcidev) {}