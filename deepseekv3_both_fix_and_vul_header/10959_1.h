#include <stdint.h>

enum count_type {
    F2FS_RD_META,
    F2FS_RD_NODE, 
    F2FS_RD_DATA
};

struct page {
    void *mapping;
};

struct address_space {
    void *host;
};

struct inode {
    uint64_t i_ino;
};

struct f2fs_sb_info;

#define F2FS_I_SB(inode) ((struct f2fs_sb_info *)0)
#define F2FS_META_INO(sbi) (0UL)
#define F2FS_NODE_INO(sbi) (0UL)