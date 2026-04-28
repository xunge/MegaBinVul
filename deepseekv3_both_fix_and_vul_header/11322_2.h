#include <stdint.h>

#define EXT4_ROOT_INO         1
#define EXT4_USR_QUOTA_INO    2
#define EXT4_GRP_QUOTA_INO    3
#define EXT4_BOOT_LOADER_INO  4
#define EXT4_JOURNAL_INO      5
#define EXT4_RESIZE_INO       6

struct ext4_super_block {
    uint32_t s_inodes_count;
    uint32_t s_first_ino;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
};

struct super_block {
    struct ext4_sb_info *s_fs_info;
};

static inline uint32_t le32_to_cpu(uint32_t x) {
    return x;
}

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))
#define EXT4_FIRST_INO(sb) (EXT4_SB(sb)->s_es->s_first_ino)