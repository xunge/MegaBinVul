struct f2fs_sb_info;
struct address_space;

struct page {
    struct address_space *mapping;
};

struct f2fs_sb_info *F2FS_M_SB(struct address_space *mapping);