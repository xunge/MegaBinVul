#include <sys/types.h>
#include <sys/ioctl.h>

typedef unsigned int fmode_t;

struct block_device {
    struct gendisk *bd_disk;
};

struct gendisk {
    char *disk_name;
};

struct scsi_disk {
    struct scsi_device *device;
};

struct scsi_device;

#define __user
#define SCSI_IOCTL_GET_IDLUN 1
#define SCSI_IOCTL_GET_BUS_NUMBER 2
#define FMODE_NDELAY 0x4
#define ENOTTY 25
#define KERN_INFO 0

#define SCSI_LOG_IOCTL(level, fmt) 
#define sd_printk(level, sdkp, fmt, ...) 

static inline struct scsi_disk *scsi_disk(struct gendisk *disk) { return 0; }
static inline int scsi_nonblockable_ioctl(struct scsi_device *sdp, unsigned int cmd, void *p, int ndelay) { return 0; }
static inline int scsi_block_when_processing_errors(struct scsi_device *sdp) { return 0; }
static inline int scsi_ioctl(struct scsi_device *sdp, unsigned int cmd, void *p) { return 0; }
static inline int scsi_cmd_blk_ioctl(struct block_device *bdev, fmode_t mode, unsigned int cmd, void *p) { return 0; }