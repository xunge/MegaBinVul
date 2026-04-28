#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SYSFS_BUS_ID_SIZE 32
#define HUB_SPEED_HIGH 1
#define HUB_SPEED_SUPER 2
#define VDEV_ST_NULL 0
#define VDEV_ST_NOTASSIGNED 1

struct usbip_imported_device {
    int hub;
    int port;
    int status;
    int devid;
    int busnum;
    int devnum;
};

struct vhci_driver {
    struct usbip_imported_device *idev;
};

extern struct vhci_driver *vhci_driver;
extern struct usbip_imported_device *imported_device_init(struct usbip_imported_device *idev, const char *lbusid);
extern void dbg(const char *fmt, ...);
#define BUG() abort()