#include <linux/errno.h>
#include <linux/cdrom.h>
#include <limits.h>

#define CD_DO_IOCTL 1
#define CD_CHANGER 2
#define CDC_SELECT_DISC 1
#define CDSL_CURRENT 0
#define CDSL_NONE (-1)

struct cdrom_device_ops {
    int (*select_disc)(struct cdrom_device_info *cdi, unsigned long arg);
};

struct cdrom_device_info {
    int capacity;
    struct cdrom_device_ops *ops;
};

static void cd_dbg(int level, const char *fmt, ...);
static int cdrom_select_disc(struct cdrom_device_info *cdi, unsigned long arg);
static int CDROM_CAN(int capability);