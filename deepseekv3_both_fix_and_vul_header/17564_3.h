#include <sys/types.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

typedef unsigned long nid_t;
typedef unsigned int __u32;

struct dentry;
struct inode {
    unsigned long i_ino;
};
struct f2fs_xattr_entry {
    __u32 e_name_index;
    __u32 e_name_len;
    char e_name[];
};
struct xattr_handler {
    int (*list)(struct dentry *);
};
struct f2fs_sb_info;

struct f2fs_inode_info {
    nid_t i_xattr_nid;
    struct {
        int dummy;
    } i_xattr_sem;
    struct f2fs_sb_info *i_sb;
};

#define F2FS_I(inode) ((struct f2fs_inode_info *)inode)
#define F2FS_I_SB(inode) (F2FS_I(inode)->i_sb)
#define XATTR_SIZE(xnid, inode) (0)
#define XATTR_NEXT_ENTRY(entry) ((struct f2fs_xattr_entry *)((char *)(entry) + sizeof(__u32)))
#define SBI_NEED_FSCK (0)
#define EFSCORRUPTED (EUCLEAN)
#define list_for_each_xattr(entry, base) for (entry = (struct f2fs_xattr_entry *)base; \
                                            (char *)entry < (char *)base + 1024; \
                                            entry = XATTR_NEXT_ENTRY(entry))

static inline struct inode *d_inode(const struct dentry *dentry) { return NULL; }
static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}
static inline void kvfree(const void *addr) {}
static inline void f2fs_err(struct f2fs_sb_info *sbi, const char *fmt, ...) {}
static inline void set_sbi_flag(struct f2fs_sb_info *sbi, int flag) {}

int read_all_xattrs(struct inode *inode, void *arg, void **base_addr);
const struct xattr_handler *f2fs_xattr_handler(int index);
const char *xattr_prefix(const struct xattr_handler *handler);