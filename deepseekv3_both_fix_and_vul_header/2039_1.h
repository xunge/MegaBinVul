#include <stdlib.h>

struct super_block {
    void *s_fs_info;
};

struct hugetlbfs_sb_info;
struct hugepage_subpool;

#define HUGETLBFS_SB(sb) ((struct hugetlbfs_sb_info *)(sb->s_fs_info))
#define kfree free

struct hugetlbfs_sb_info {
    struct hugepage_subpool *spool;
};

void hugepage_put_subpool(struct hugepage_subpool *spool);