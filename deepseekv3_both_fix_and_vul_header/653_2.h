#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PCD_UNITS 4
#define D_SLV 0
#define D_PRT 1
#define BLK_MQ_F_SHOULD_MERGE 0
#define GENHD_FL_BLOCK_EVENTS_ON_EXCL_WRITE 0
#define BLK_BOUNCE_HIGH 0

struct list_head {
    struct list_head *next, *prev;
};

struct blk_mq_tag_set {};
struct blk_mq_ops {};
struct request_queue {
    void *queuedata;
};

struct gendisk {
    int major;
    int first_minor;
    char disk_name[32];
    struct request_queue *queue;
    void *fops;
    int flags;
};

struct pi_adapter {
    struct pia *pia;
};

struct pia {};
struct cdrom_device_ops {};
struct block_device_operations {};

struct pcd_unit {
    struct gendisk *disk;
    struct pi_adapter *pi;
    struct pia pia;
    int present;
    int last_sense;
    int changed;
    int drive;
    char *name;
    struct {
        char name[32];
        struct cdrom_device_ops *ops;
        void *handle;
        int speed;
        int capacity;
        int mask;
    } info;
    struct blk_mq_tag_set tag_set;
    struct list_head rq_list;
};

extern struct pcd_unit pcd[PCD_UNITS];
extern int pcd_drive_count;
extern int major;
extern char *name;
extern int (*drives[PCD_UNITS])[2];
extern struct cdrom_device_ops pcd_dops;
extern struct block_device_operations pcd_bdops;
extern struct blk_mq_ops pcd_mq_ops;

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline struct gendisk *alloc_disk(int minors) {
    return calloc(1, sizeof(struct gendisk));
}

static inline struct request_queue *blk_mq_init_sq_queue(struct blk_mq_tag_set *set, 
                                      const struct blk_mq_ops *ops,
                                      unsigned int queue_depth,
                                      unsigned int flags) {
    return calloc(1, sizeof(struct request_queue));
}

static inline int IS_ERR(const void *ptr) {
    return ptr == NULL;
}

static inline void blk_queue_bounce_limit(struct request_queue *queue, int limit) {
}