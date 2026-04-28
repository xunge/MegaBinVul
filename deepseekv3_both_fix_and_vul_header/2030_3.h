#include <sys/types.h>

struct gendisk;
struct scsi_device;
struct scsi_disk;

struct block_device {
    struct gendisk *bd_disk;
};

struct scsi_host_template {
    int (*compat_ioctl)(struct scsi_device *, int, void *);
};

struct Scsi_Host {
    struct scsi_host_template *hostt;
};

struct scsi_device {
    struct Scsi_Host *host;
};

struct scsi_disk {
    struct scsi_device *device;
};

typedef unsigned int fmode_t;
#define ENODEV 19
#define ENOIOCTLCMD 515
#define __user

struct scsi_disk *scsi_disk(struct gendisk *disk);
int scsi_block_when_processing_errors(struct scsi_device *sdev);