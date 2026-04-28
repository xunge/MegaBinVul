#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

typedef uint32_t ext4_lblk_t;

#define EXT_MAX_BLOCKS ((ext4_lblk_t)~0)
#define EXT_MAX_BLOCK EXT_MAX_BLOCKS

struct inode;
struct ext4_ext_path {
    struct ext4_extent *p_ext;
};
struct ext4_extent {
    uint32_t ee_block;
    uint32_t ee_len;
};

static inline uint32_t le32_to_cpu(uint32_t x) {
    return le32toh(x);
}

#define ext_depth(inode) (0)
#define ext4_ext_get_actual_len(ex) ((ex)->ee_len)
#define ext4_ext_next_allocated_block(path) (0)
#define ext_debug(fmt, ...) 
#define BUG() 
#define BUG_ON(cond) 

static void ext4_ext_put_in_cache(struct inode *inode, ext4_lblk_t lblock, unsigned long len, int flag);