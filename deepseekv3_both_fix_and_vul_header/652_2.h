#include <stdio.h>
#include <string.h>

#define PCD_VERSION "1.0" 
#define PCD_UNITS 4
#define PI_PCD 0

struct pi_adapter {
    // minimal stub definition
    int dummy;
};

struct gendisk {
    // minimal stub definition  
    void *queue;
};

struct blk_mq_tag_set {
    // minimal stub definition
    int dummy;
};

struct pi_driver {
    // minimal stub definition
    int dummy;
};

struct pcd_unit {
    struct pi_adapter *pi;
    struct gendisk *disk;
    struct blk_mq_tag_set tag_set;
    char name[8];
    int present;
};

static char *name = "pcd";
static int major;
static int nice; 
static int verbose;
static struct pcd_unit pcd[PCD_UNITS];
static int pcd_drive_count;
static char pcd_buffer[512];
static struct pi_driver *par_drv;
static int (*drives[PCD_UNITS])[6];

enum { D_PRT, D_MOD, D_UNI, D_PRO, D_DLY, D_SLV };

// Stub functions
#define printk printf
#define pr_err printf
struct pi_driver *pi_register_driver(char *name) { return NULL; }
int pi_init(struct pi_adapter *pi, int a, int b, int c, int d, int e, int f, 
            char *buf, int type, int verbose, char *name) { return 0; }
int pcd_probe(struct pcd_unit *cd, int slave, char *id) { return 0; }
void pi_release(struct pi_adapter *pi) {}
void pi_unregister_driver(struct pi_driver *drv) {}
void blk_cleanup_queue(void *queue) {}
void blk_mq_free_tag_set(struct blk_mq_tag_set *set) {}
void put_disk(struct gendisk *disk) {}