#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef uint64_t u64;
typedef int64_t loff_t;

struct rw_semaphore {
    int dummy;
};

#define BTRFS_EMPTY_SUBVOL_DIR_OBJECTID ((u64)-2)
#define BTRFS_FIRST_FREE_OBJECTID ((u64)256)
#define BTRFS_EMPTY_DIR_SIZE 0
#define BTRFS_ORDERED_OPERATIONS_FLUSH_LIMIT 0

#define EPERM 1
#define EXDEV 2
#define ENOTEMPTY 3
#define EEXIST 4

#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))
#define BUG_ON(condition) do { if (condition) { } } while (0)
#define WARN_ON(condition) ((void)(condition))
#define unlikely(cond) (cond)

struct inode {
    unsigned long i_ino;
    unsigned int i_mode;
    loff_t i_size;
    struct timespec i_ctime;
    struct timespec i_mtime;
    unsigned int i_nlink;
    void *i_mapping;
};

struct dentry {
    struct inode *d_inode;
    struct dentry *d_parent;
    struct {
        const char *name;
        unsigned int len;
    } d_name;
};

struct btrfs_trans_handle {
    u64 transid;
};

struct btrfs_key {
    u64 objectid;
};

struct btrfs_root {
    struct btrfs_fs_info *fs_info;
    struct btrfs_key root_key;
};

struct btrfs_inode {
    struct btrfs_root *root;
    u64 ino;
    struct btrfs_key location;
};

struct btrfs_fs_info {
    struct rw_semaphore subvol_sem;
    u64 last_trans_log_full_commit;
};

#define BTRFS_I(inode) ((struct btrfs_inode *)(inode))
#define CURRENT_TIME ((struct timespec){0})

static inline u64 btrfs_ino(struct inode *inode) { return BTRFS_I(inode)->ino; }
static inline void inode_inc_iversion(struct inode *inode) { }
static inline void fixup_inode_flags(struct inode *dir, struct inode *inode) { }
static inline void btrfs_pin_log_trans(struct btrfs_root *root) { }
static inline void btrfs_end_log_trans(struct btrfs_root *root) { }
static inline void btrfs_log_new_name(struct btrfs_trans_handle *trans, 
                                    struct inode *inode, 
                                    struct inode *old_dir, 
                                    struct dentry *parent) { }
static inline void down_read(struct rw_semaphore *sem) { }
static inline void up_read(struct rw_semaphore *sem) { }
static inline void filemap_flush(void *mapping) { }

static int btrfs_check_dir_item_collision(struct btrfs_root *root, u64 dir_ino,
                                        const char *name, int name_len) { return 0; }
static int btrfs_start_transaction(struct btrfs_root *root, int num_blocks) { return 0; }
static void btrfs_end_transaction(struct btrfs_trans_handle *trans, 
                                struct btrfs_root *root) { }
static int btrfs_record_root_in_trans(struct btrfs_trans_handle *trans,
                                    struct btrfs_root *root) { return 0; }
static int btrfs_set_inode_index(struct inode *dir, u64 *index) { return 0; }
static int btrfs_insert_inode_ref(struct btrfs_trans_handle *trans,
                                struct btrfs_root *root,
                                const char *name, int name_len,
                                u64 inode_objectid, u64 ref_objectid,
                                u64 index) { return 0; }
static void btrfs_add_ordered_operation(struct btrfs_trans_handle *trans,
                                      struct btrfs_root *root,
                                      struct inode *inode) { }
static void btrfs_record_unlink_dir(struct btrfs_trans_handle *trans,
                                  struct inode *dir, struct inode *inode,
                                  int for_rename) { }
static int btrfs_unlink_subvol(struct btrfs_trans_handle *trans,
                             struct btrfs_root *root,
                             struct inode *dir, u64 objectid,
                             const char *name, int name_len) { return 0; }
static int __btrfs_unlink_inode(struct btrfs_trans_handle *trans,
                              struct btrfs_root *root,
                              struct inode *dir, struct inode *inode,
                              const char *name, int name_len) { return 0; }
static int btrfs_update_inode(struct btrfs_trans_handle *trans,
                            struct btrfs_root *root,
                            struct inode *inode) { return 0; }
static void btrfs_abort_transaction(struct btrfs_trans_handle *trans,
                                  struct btrfs_root *root, int errno) { }
static int btrfs_unlink_inode(struct btrfs_trans_handle *trans,
                            struct btrfs_root *root,
                            struct inode *dir, struct inode *inode,
                            const char *name, int name_len) { return 0; }
static int btrfs_orphan_add(struct btrfs_trans_handle *trans,
                          struct inode *inode) { return 0; }
static int btrfs_add_link(struct btrfs_trans_handle *trans,
                        struct inode *dir, struct inode *inode,
                        const char *name, int name_len,
                        int add_backref, u64 index) { return 0; }