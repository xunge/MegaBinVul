#include <stdio.h>
#include <string.h>

#define PF_VERSION "1.0"
#define PF_UNITS 4
#define PI_PF 1

struct pf_unit {
    void *pi;
    struct {
        void *queue;
    } *disk;
    int present;
    char *name;
    void *tag_set;
};

struct pi_driver;

static struct pf_unit *units;
static char *name;
static int major;
static int cluster;
static int nice;
static struct pi_driver *par_drv;
static int pf_drive_count;
static int verbose;
static int pf_scratch;
static int **drives[PF_UNITS];

enum {
    D_PRT,
    D_MOD,
    D_UNI,
    D_PRO,
    D_DLY
};

#define printk printf
#define pr_err(fmt, ...) fprintf(stderr, "ERROR: " fmt, ##__VA_ARGS__)

static int pf_probe(struct pf_unit *pf) { return 0; }
static void pi_release(void *pi) {}
static struct pi_driver *pi_register_driver(char *name) { return NULL; }
static void pi_unregister_driver(struct pi_driver *drv) {}
static int pi_init(void *pi, int autoprobe, int port, int mode,
                   int unit, int protocol, int delay, int scratch, int type,
                   int verbose, char *name) { return 0; }
static void blk_cleanup_queue(void *queue) {}
static void blk_mq_free_tag_set(void *tag_set) {}
static void put_disk(void *disk) {}