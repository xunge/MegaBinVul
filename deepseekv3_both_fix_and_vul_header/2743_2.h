#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

typedef uint64_t u64;
typedef uint8_t u8;
typedef int64_t loff_t;

#define BTRFS_FIRST_FREE_OBJECTID 256ULL
#define BTRFS_INODE_ITEM_KEY 1
#define EEXIST 17
#define EOVERFLOW 75
#define unlikely(x) (x)

struct inode {
    u64 i_ino;
    unsigned int i_mode;
    loff_t i_size;
    unsigned long i_version;
    struct timespec i_mtime;
    struct timespec i_ctime;
};

struct btrfs_key {
    u64 objectid;
    u8 type;
    u64 offset;
};

struct btrfs_root {
    struct btrfs_key root_key;
    struct {
        struct btrfs_root *tree_root;
    } *fs_info;
};

struct btrfs_inode {
    struct btrfs_root *root;
};

struct btrfs_trans_handle;

static inline struct btrfs_inode *BTRFS_I(struct inode *inode) {
    return (struct btrfs_inode *)inode;
}

static inline u64 btrfs_ino(struct inode *inode) {
    return inode->i_ino;
}

static inline void btrfs_set_key_type(struct btrfs_key *key, int type) {
    key->type = type;
}

static inline int btrfs_inode_type(struct inode *inode) {
    return inode->i_mode & S_IFMT;
}

static inline void btrfs_i_size_write(struct inode *inode, loff_t size) {
    inode->i_size = size;
}

static inline void inode_inc_iversion(struct inode *inode) {
    inode->i_version++;
}

#define CURRENT_TIME (struct timespec){ .tv_sec = time(NULL), .tv_nsec = 0 }

extern int btrfs_add_root_ref(struct btrfs_trans_handle *, struct btrfs_root *,
                             u64, u64, u64, u64, const char *, int);
extern int btrfs_insert_inode_ref(struct btrfs_trans_handle *, struct btrfs_root *,
                                 const char *, int, u64, u64, u64);
extern int btrfs_insert_dir_item(struct btrfs_trans_handle *, struct btrfs_root *,
                                const char *, int, struct inode *,
                                struct btrfs_key *, int, u64);
extern int btrfs_update_inode(struct btrfs_trans_handle *, struct btrfs_root *,
                             struct inode *);
extern int btrfs_del_root_ref(struct btrfs_trans_handle *, struct btrfs_root *,
                             u64, u64, u64, u64 *, const char *, int);
extern int btrfs_del_inode_ref(struct btrfs_trans_handle *, struct btrfs_root *,
                              const char *, int, u64, u64, u64 *);
extern void btrfs_abort_transaction(struct btrfs_trans_handle *, struct btrfs_root *, int);