#include <stdlib.h>
#include <stdint.h>

#define CD_DO_IOCTL 0
#define CDC_MEDIA_CHANGED 0
#define CDC_SELECT_DISC 0
#define CDSL_CURRENT 0
#define ENOSYS 38
#define ENOMEM 12
#define EINVAL 22
#define GFP_KERNEL 0

struct cdrom_device_info {
    unsigned int capacity;
};

struct cdrom_changer_info {
    struct {
        int change;
    } *slots;
};

static int media_changed(struct cdrom_device_info *cdi, int arg) { return 0; }
static void cd_dbg(int level, const char *msg) {}
static int cdrom_read_mech_status(struct cdrom_device_info *cdi, struct cdrom_changer_info *info) { return 0; }
#define CDROM_CAN(x) 0

#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)