#include <stdint.h>

typedef unsigned long sector_t;
typedef uint64_t u64;
typedef unsigned long pgoff_t;

struct inode {
    unsigned long i_blkbits;
    void *i_sb;
};

struct buffer_head {
    unsigned long b_size;
    unsigned long b_state;
};

struct super_block;

struct f2fs_map_blocks {
    sector_t m_lblk;
    sector_t m_pblk;
    unsigned int m_len;
    unsigned int m_flags;
    pgoff_t *m_next_pgofs;
};

#define F2FS_MAP_FLAGS 0

int f2fs_map_blocks(struct inode *inode, struct f2fs_map_blocks *map, int create, int flag);
void map_bh(struct buffer_head *bh, struct super_block *sb, sector_t block);