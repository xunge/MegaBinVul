#include <stdio.h>
#include <errno.h>

#define EIO 5
#define ENOMEM 12
#define EROFS 30
#define JBD2_ABORT 1

struct super_block {
    void *s_fs_info;
};

struct ext4_sb_info {
    struct {
        int j_flags;
    } *s_journal;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))