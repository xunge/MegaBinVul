#include <errno.h>
#include <stddef.h>

#define __init
#define ENODEV 19
#define EBUSY 16
#define EINVAL 22
#define PF_UNITS 4

static int disable;
static int major;
static char *name;
static struct pf_unit *units;
static int pf_busy;

struct blk_mq_tag_set {
    unsigned int flags;
    unsigned int queue_depth;
    unsigned int reserved_tags;
    unsigned int cmd_size;
    void *driver_data;
};

struct gendisk {
    void *queue;
    void *private_data;
};

struct pf_unit {
    struct gendisk *disk;
    int present;
    struct blk_mq_tag_set tag_set;
};

static int pf_detect(void) { return 0; }
static void pf_init_units(void) {}
static int register_blkdev(int major, char *name) { return 0; }
static void blk_cleanup_queue(void *queue) {}
static void blk_mq_free_tag_set(struct blk_mq_tag_set *tag_set) {}
static void put_disk(struct gendisk *disk) {}
static void add_disk(struct gendisk *disk) {}