#include <stddef.h>
#include <stdint.h>
#include <errno.h>

typedef struct hive_h hive_h;
typedef struct offset_list offset_list;
typedef uint32_t hive_node_h;

struct hive_h {
    void *addr;
    int unsafe;
};

struct offset_list {
    // Minimal implementation
    size_t count;
    hive_node_h *items;
};

struct ntreg_hbin_block {
    char id[2];
};

struct ntreg_lf_record {
    char id[2];
    uint16_t nr_keys;
    struct {
        uint32_t offset;
    } keys[];
};

struct ntreg_ri_record {
    char id[2];
    uint16_t nr_offsets;
    uint32_t offset[];
};

#define le16toh(x) (x)
#define le32toh(x) (x)
#define DEBUG(level, fmt, ...)
#define SET_ERRNO(err, fmt, ...)
#define IS_VALID_BLOCK(h, offset) (1)