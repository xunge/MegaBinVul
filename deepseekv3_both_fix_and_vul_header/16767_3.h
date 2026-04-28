#include <stddef.h>
#include <stdint.h>
#include <sys/stat.h>

struct list_head {
    struct list_head *next, *prev;
};

struct address_space {
    struct list_head private_list;
};

struct super_block {
    unsigned long s_flags;
};

struct inode {
    struct address_space i_data;
    struct super_block *i_sb;
    unsigned short i_mode;
};

struct fuse_forget_link {
    struct fuse_forget_link *next;
};

struct fuse_conn {
    unsigned dummy;
};

struct fuse_inode {
    uint64_t nlookup;
    uint64_t nodeid;
    struct fuse_forget_link *forget;
    struct list_head write_files;
    struct list_head queued_writes;
};

#define SB_ACTIVE (1 << 0)
#define FUSE_IS_DAX(inode) (0)
#define WARN_ON(condition) ((void)(condition))

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

static inline struct fuse_inode *get_fuse_inode(struct inode *inode) {
    return (struct fuse_inode *)0;
}

static inline struct fuse_conn *get_fuse_conn(struct inode *inode) {
    return (struct fuse_conn *)0;
}

static void truncate_inode_pages_final(struct address_space *mapping) {}
static void clear_inode(struct inode *inode) {}
static int is_bad_inode(struct inode *inode) { return 0; }
static void fuse_dax_inode_cleanup(struct inode *inode) {}
static void fuse_queue_forget(struct fuse_conn *fc, struct fuse_forget_link *forget,
                             uint64_t nodeid, uint64_t nlookup) {}