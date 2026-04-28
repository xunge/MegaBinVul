#include <stddef.h>

struct page {
    struct address_space *mapping;
};

struct address_space;
struct f2fs_sb_info;

struct f2fs_sb_info *F2FS_M_SB(struct address_space *mapping);