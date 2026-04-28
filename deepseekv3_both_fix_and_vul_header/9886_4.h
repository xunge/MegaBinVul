#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define MAC_DRIVER_MAGIC 0x4552
#define MAC_PARTITION_MAGIC 0x504d
#define DISK_MAX_PARTS 256
#define PAGE_SIZE 4096
#define ADDPART_FLAG_RAID 1
#define MAC_STATUS_BOOTABLE 0x40000000

typedef struct {
    int dummy;
} Sector;

struct mac_driver_desc {
    uint16_t signature;
    uint16_t block_size;
    uint32_t block_count;
};

struct mac_partition {
    uint16_t signature;
    uint16_t res1;
    uint32_t map_count;
    uint32_t start_block;
    uint32_t block_count;
    char name[32];
    char type[32];
    uint32_t data_start;
    uint32_t data_count;
    uint32_t status;
    uint32_t boot_start;
    uint32_t boot_size;
    uint32_t boot_load;
    uint32_t boot_load2;
    uint32_t boot_entry;
    uint32_t boot_entry2;
    uint32_t boot_cksum;
    char processor[16];
};

struct parsed_partitions {
    char pp_buf[PAGE_SIZE];
    struct {
        uint64_t from;
        uint64_t size;
        int flags;
    } parts[DISK_MAX_PARTS];
    int next;
    int limit;
    void *bdev;
};

static inline uint16_t be16_to_cpu(uint16_t x) { return __builtin_bswap16(x); }
static inline uint32_t be32_to_cpu(uint32_t x) { return __builtin_bswap32(x); }
static inline void mac_fix_string(char *str, int len) {}
static inline void put_dev_sector(Sector sect) {}
static inline void note_bootable_part(void *dev, int part, int goodness) {}
static inline void put_partition(struct parsed_partitions *state, int slot, uint64_t from, uint64_t size) {}
static inline unsigned char *read_part_sector(struct parsed_partitions *state, int sector, Sector *sect) { return NULL; }