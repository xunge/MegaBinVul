#include <stdint.h>

typedef uint32_t ext4_lblk_t;

#define EXT4_ADDR_PER_BLOCK(sb) (1 << (sb)->s_blocksize_bits - 2)
#define EXT4_ADDR_PER_BLOCK_BITS(sb) ((sb)->s_blocksize_bits - 2)
#define EXT4_NDIR_BLOCKS 12
#define EXT4_IND_BLOCK (EXT4_NDIR_BLOCKS)
#define EXT4_DIND_BLOCK (EXT4_IND_BLOCK + 1)
#define EXT4_TIND_BLOCK (EXT4_DIND_BLOCK + 1)

struct inode {
    struct super_block *i_sb;
    unsigned long i_ino;
};

struct super_block {
    unsigned int s_blocksize_bits;
};

void ext4_warning(struct super_block *sb, const char *function, const char *fmt, ...);