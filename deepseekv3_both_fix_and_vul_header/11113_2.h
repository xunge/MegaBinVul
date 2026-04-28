#include <stdbool.h>
#include <stdint.h>

struct inode {
    unsigned long i_ino;
    void *i_sb;
};

struct page;
struct f2fs_sb_info {
    void *sb;
};
struct f2fs_inode {
    uint64_t i_blocks;
};
struct f2fs_node {
    struct {
        uint32_t ino;
        uint32_t nid;
    } footer;
};

#define F2FS_I_SB(inode) ((struct f2fs_sb_info *)((inode)->i_sb))
#define le64_to_cpu(x) (x)
#define F2FS_INODE(page) ((struct f2fs_inode *)((char *)(page) + sizeof(struct f2fs_node)))
#define ino_of_node(page) (F2FS_NODE(page)->footer.ino)
#define nid_of_node(page) (F2FS_NODE(page)->footer.nid)
#define F2FS_NODE(page) ((struct f2fs_node *)(page))
#define KERN_WARNING 0

enum {
    SBI_NEED_FSCK,
};

static inline bool f2fs_sb_has_flexible_inline_xattr(void *sb) { return false; }
static inline bool f2fs_has_extra_attr(struct inode *inode) { return false; }
static inline bool f2fs_sb_has_extra_attr(void *sb) { return false; }
static inline void set_sbi_flag(struct f2fs_sb_info *sbi, unsigned int flag) {}
static inline void f2fs_msg(void *sb, int level, const char *fmt, ...) {}