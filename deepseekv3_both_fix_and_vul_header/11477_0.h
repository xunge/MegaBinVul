#include <linux/ioctl.h>
#include <linux/cdrom.h>
#include <linux/errno.h>

#define CD_DO_IOCTL 1
#define CDC_DRIVE_STATUS 1
#define CDC_SELECT_DISC 1
#define CDSL_CURRENT 0
#define CDSL_NONE 0
#define ENOSYS 38
#define EINVAL 22

struct cdrom_device_info {
    struct cdrom_device_ops *ops;
    int capacity;
};

struct cdrom_device_ops {
    unsigned int capability;
    int (*drive_status)(struct cdrom_device_info *cdi, int slot);
};

static void cd_dbg(int level, const char *fmt, ...) {}
static int cdrom_slot_status(struct cdrom_device_info *cdi, unsigned long arg) { return 0; }