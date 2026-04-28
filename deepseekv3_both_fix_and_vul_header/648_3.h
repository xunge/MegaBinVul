#include <stdbool.h>

#define PF_UNITS 4
#define major 0
#define __exit

struct gendisk {
    void *queue;
};

struct pf_unit {
    bool present;
    struct gendisk *disk;
    void *tag_set;
    void *pi;
};

extern struct pf_unit units[PF_UNITS];
extern char *name;

void unregister_blkdev(int, char*);
void del_gendisk(struct gendisk*);
void blk_cleanup_queue(void*);
void blk_mq_free_tag_set(void*);
void put_disk(struct gendisk*);
void pi_release(void*);