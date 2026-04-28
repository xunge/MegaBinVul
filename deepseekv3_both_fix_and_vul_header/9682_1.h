#include <stdint.h>

typedef uint32_t ext4_lblk_t;

struct inode;
struct ext4_extent {
    uint32_t ee_block;
    uint16_t ee_len;
    uint64_t ee_start;
};

struct ext4_ext_cache {
    ext4_lblk_t ec_block;
    uint16_t ec_len;
    uint64_t ec_start;
    int ec_type;
};

#define EXT4_EXT_CACHE_NO 0
#define EXT4_EXT_CACHE_GAP 1
#define EXT4_EXT_CACHE_EXTENT 2

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))

struct ext4_inode_info {
    int i_block_reservation_lock;
    struct ext4_ext_cache i_cached_extent;
};

static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }
static inline uint32_t cpu_to_le32(uint32_t x) { return x; }
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
static inline void ext4_ext_store_pblock(struct ext4_extent *ex, uint64_t pb) {
    ex->ee_start = pb;
}
#define BUG_ON(cond) (void)(cond)
#define ext_debug(fmt, ...) (void)0