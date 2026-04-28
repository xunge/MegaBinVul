#include <sys/types.h>
#include <sys/ioctl.h>

typedef unsigned int fmode_t;
#define __user

struct gendisk {
    struct request_queue *queue;
};

struct block_device {
    struct gendisk *bd_disk;
};

struct request_queue;

int scsi_cmd_ioctl(struct request_queue *q, struct gendisk *disk, fmode_t mode,
                  unsigned int cmd, void *arg);