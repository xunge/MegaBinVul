#include <stdbool.h>
#include <stdatomic.h>

#define FI_NO_EXTENT 1

struct inode {
    unsigned long i_ino;
};

struct f2fs_extent {
    unsigned int len;
};

struct f2fs_sb_info {
    int extent_lock;
    struct {
        struct {
            struct list_head *next, *prev;
        } list;
    } extent_list;
};

struct extent_tree {
    int lock;
    atomic_int node_cnt;
};

struct extent_node {
    struct {
        struct list_head *next, *prev;
    } list;
};

struct extent_info {
    unsigned int len;
};

extern bool __f2fs_init_extent_tree(struct inode *inode, struct f2fs_extent *i_ext);
extern struct f2fs_sb_info *F2FS_I_SB(struct inode *inode);
extern bool f2fs_may_extent_tree(struct inode *inode);
extern struct extent_tree *__grab_extent_tree(struct inode *inode);
extern void get_extent_info(struct extent_info *ei, struct f2fs_extent *i_ext);
extern struct extent_node *__init_extent_tree(struct f2fs_sb_info *sbi, struct extent_tree *et, struct extent_info *ei);
extern void set_inode_flag(struct inode *inode, int flag);
extern struct {
    struct extent_tree *extent_tree;
} *F2FS_I(struct inode *inode);

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void write_lock(int *lock) {}
static inline void write_unlock(int *lock) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}