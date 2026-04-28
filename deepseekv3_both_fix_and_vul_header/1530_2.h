#include <stdatomic.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct super_block {
    void *s_fs_info;
};

struct inode {
    unsigned long i_private;
    unsigned long i_nlink;
    struct super_block *i_sb;
    struct {
        void *private_data;
    } i_data;
};

struct jfs_inode_info {
    struct list_head anon_inode_list;
    int ag_lock;
    int active_ag;
    int fileset;
    struct inode *i_imap;
};

struct jfs_sb_info {
    struct inode *ipimap;
    struct bmap *bmap;
};

struct bmap {
    atomic_int db_active[1];
};

#define JFS_IP(inode) ((struct jfs_inode_info *)(inode)->i_private)
#define JFS_SBI(sb) ((struct jfs_sb_info *)((struct super_block *)(sb))->s_fs_info)
#define FILESYSTEM_I 0
#define COMMIT_Freewmap 0
#define BUG_ON(cond) do { if (cond) {} } while (0)

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

static inline void spin_lock_irq(int *lock) {
    (void)lock;
}

static inline void spin_unlock_irq(int *lock) {
    (void)lock;
}

static inline void atomic_dec(atomic_int *v) {
    (*v)--;
}

void jfs_info(const char *fmt, ...);
int is_bad_inode(struct inode *inode);
void dquot_initialize(struct inode *inode);
void truncate_inode_pages_final(void *mapping);
int test_cflag(int flag, struct inode *inode);
void jfs_free_zero_link(struct inode *inode);
void diFree(struct inode *inode);
void dquot_free_inode(struct inode *inode);
void clear_inode(struct inode *inode);
void dquot_drop(struct inode *inode);