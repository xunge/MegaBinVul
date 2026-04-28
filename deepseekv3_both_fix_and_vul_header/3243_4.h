#include <linux/capability.h>

struct scsi_device {
    struct {
        void* hostdata;
    }* host;
};
struct aac_dev;
extern int aac_compat_do_ioctl(struct aac_dev *dev, int cmd, unsigned long arg);

#define __user
#define CAP_SYS_RAWIO 0
#define EPERM 1