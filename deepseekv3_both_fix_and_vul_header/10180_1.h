#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>

struct exfat_dev;

enum exfat_mode {
    EXFAT_MODE_RO,
    EXFAT_MODE_RW,
    EXFAT_MODE_ANY
};

#define EXFAT_ATTRIB_DIR 0x10

struct exfat_version {
    uint8_t major;
    uint8_t minor;
};

struct exfat_super_block {
    char oem_name[8];
    struct exfat_version version;
    uint8_t fat_count;
    uint8_t sector_bits;
    uint8_t spc_bits;
    uint64_t sector_count;
    uint32_t rootdir_cluster;
};

struct exfat_node {
    uint16_t flags;
    uint32_t start_cluster;
    uint32_t fptr_cluster;
    uint16_t name[256];
    uint64_t size;
    uint64_t mtime;
    uint64_t atime;
};

struct exfat {
    struct exfat_dev* dev;
    struct exfat_super_block* sb;
    struct exfat_node* root;
    void* zero_cluster;
    int ro;
    void* upcase;
    struct {
        void* chunk;
    } cmap;
};

#define CLUSTER_SIZE(sb) (1 << ((sb).sector_bits + (sb).spc_bits))
#define SECTOR_SIZE(sb) (1 << (sb).sector_bits)

static inline uint64_t le64_to_cpu(uint64_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }