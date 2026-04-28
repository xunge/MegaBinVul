#include <stdbool.h>
#include <cstddef>

#define WRITE 1
#define LFS 1
#define S_SWAPFILE 1
#define SBI_CP_DISABLED 1

struct f2fs_sb_info;
struct inode {
    unsigned long i_flags;
};
struct kiocb;
struct iov_iter;

static inline struct f2fs_sb_info *F2FS_I_SB(struct inode *inode) { return NULL; }
static inline int iov_iter_rw(struct iov_iter *iter) { return 0; }
static inline bool f2fs_post_read_required(struct inode *inode) { return false; }
static inline bool f2fs_is_multi_device(struct f2fs_sb_info *sbi) { return false; }
static inline bool f2fs_sb_has_blkzoned(struct f2fs_sb_info *sbi) { return false; }
static inline bool test_opt(struct f2fs_sb_info *sbi, int opt) { return false; }
static inline bool block_unaligned_IO(struct inode *inode, struct kiocb *iocb, struct iov_iter *iter) { return false; }
static inline bool is_sbi_flag_set(struct f2fs_sb_info *sbi, int flag) { return false; }