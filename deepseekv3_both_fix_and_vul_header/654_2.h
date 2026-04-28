#include <errno.h>
#include <stddef.h>

#define PCD_UNITS 4
#define disable 0
#define __init
#define EINVAL 22
#define ENODEV 19
#define EBUSY 16

struct gendisk {
    void *queue;
    void *private_data;
};

struct cdrom_device_info {
    int dummy;
};

struct blk_mq_tag_set {
    int dummy;
};

struct pcd_unit {
    struct gendisk *disk;
    struct cdrom_device_info info;
    struct blk_mq_tag_set tag_set;
    int present;
};

static struct pcd_unit pcd[PCD_UNITS];
static int major;
static char *name;

static int register_blkdev(int major, char *name) { return 0; }
static void blk_cleanup_queue(void *queue) {}
static void blk_mq_free_tag_set(struct blk_mq_tag_set *set) {}
static void put_disk(struct gendisk *disk) {}
static void register_cdrom(struct cdrom_device_info *info) {}
static void add_disk(struct gendisk *disk) {}
static void pcd_init_units(void) {}
static int pcd_detect(void) { return 0; }
static void pcd_probe_capabilities(void) {}