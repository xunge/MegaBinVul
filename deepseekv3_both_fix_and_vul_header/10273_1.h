#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define BLKID_PROBE_OK 0
#define ENOMEM 12
#define LOWPROBE 0

struct dos_partition {
    unsigned char boot_ind;
    unsigned char head;
    unsigned char sector;
    unsigned char cyl;
    unsigned char sys_ind;
    unsigned char end_head;
    unsigned char end_sector;
    unsigned char end_cyl;
    uint32_t start_sect;
    uint32_t nr_sects;
};

typedef void* blkid_probe;
typedef void* blkid_parttable;
typedef void* blkid_partlist;
typedef void* blkid_partition;

#define DBG(level, expr) do { } while (0)

static inline int mbr_is_valid_magic(const unsigned char *data) { return 0; }
static inline struct dos_partition* mbr_get_partition(const unsigned char *data, int i) { return NULL; }
static inline uint32_t dos_partition_get_start(struct dos_partition *p) { return 0; }
static inline uint32_t dos_partition_get_size(struct dos_partition *p) { return 0; }
static inline int is_extended(struct dos_partition *p) { return 0; }
static inline blkid_partlist blkid_probe_get_partlist(blkid_probe pr) { return NULL; }
static inline unsigned char* blkid_probe_get_sector(blkid_probe pr, uint32_t sector) { return NULL; }
static inline blkid_partition blkid_partlist_add_partition(blkid_partlist ls, blkid_parttable tab, uint32_t start, uint32_t size) { return NULL; }
static inline void blkid_partition_set_type(blkid_partition par, unsigned char type) {}
static inline void blkid_partition_set_flags(blkid_partition par, unsigned char flags) {}
static inline void blkid_partition_gen_uuid(blkid_partition par) {}