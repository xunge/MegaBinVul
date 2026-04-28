#include <stddef.h>

#define PCD_UNITS 4
#define __exit

struct gendisk {
    void *queue;
};

struct pi_adapter;
struct pi_driver;

struct pcd_unit {
    int present;
    struct gendisk *disk;
    struct pi_adapter *pi;
    void *info;
    void *tag_set;
};

static int major;
static char *name;
static struct pcd_unit *pcd;
static struct pi_driver *par_drv;