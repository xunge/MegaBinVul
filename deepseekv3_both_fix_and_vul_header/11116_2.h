#include <stdbool.h>
#include <stdint.h>

struct super_block {
    void *s_fs_info;
};

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
};

struct f2fs_sb_info {
    struct super_block *sb;
};

#define F2FS_I_SB(inode) ((struct f2fs_sb_info *)((inode)->i_sb->s_fs_info))
#define SBI_NEED_FSCK 0
#define KERN_WARNING 0

static inline bool f2fs_sb_has_flexible_inline_xattr(struct super_block *sb) { return false; }
static inline bool f2fs_has_extra_attr(struct inode *inode) { return false; }
static inline void set_sbi_flag(struct f2fs_sb_info *sbi, int flag) {}
static inline void f2fs_msg(struct super_block *sb, int level, const char *fmt, ...) {}