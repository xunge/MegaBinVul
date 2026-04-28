#include <stddef.h>

struct iso_directory_record;

struct super_block {
    void *s_fs_info;
};

struct inode {
    struct super_block *i_sb;
};

struct iso9660_sb_info {
    int s_rock_offset;
    int s_rock;
};

#define ISOFS_SB(sb) ((struct iso9660_sb_info *)(sb)->s_fs_info)
#define RR_RELOC_DE 0
#define RR_REGARD_XA 14

int parse_rock_ridge_inode_internal(struct iso_directory_record *de, struct inode *inode, int offset);