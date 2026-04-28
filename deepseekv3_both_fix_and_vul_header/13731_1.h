#include <stdint.h>
#include <linux/types.h>

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
};

struct super_block {
    struct ext4_super_block *s_es;
};

struct ext4_super_block {
    uint32_t s_journal_inum;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
};

struct ext4_map_blocks {
    uint64_t m_pblk;
    unsigned long m_lblk;
    int m_len;
};

#define le32_to_cpu(x) (x)
#define EXT4_SB(sb) ((struct ext4_sb_info *)sb)
#define EFSCORRUPTED 117

int ext4_has_feature_journal(struct super_block *sb);
int ext4_data_block_valid(struct ext4_sb_info *es, uint64_t pblk, int len);
void ext4_error_inode(struct inode *inode, const char *func, unsigned int line, uint64_t block, const char *fmt, ...);