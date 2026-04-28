#include <stddef.h>
#include <string.h>

struct dentry {
    struct dentry *d_parent;
    struct inode *d_inode;
    struct {
        const char *name;
        int len;
    } d_name;
};

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
    unsigned int i_flags;
};

struct super_block {
    unsigned int s_blocksize;
    unsigned int s_def_hash_version;
    unsigned int s_hash_unsigned;
    unsigned int s_hash_seed;
};

struct buffer_head {
    char *b_data;
};

struct fake_dirent {
    unsigned int rec_len;
};

struct dx_root {
    struct fake_dirent dotdot;
    struct {
        unsigned int info_length;
        unsigned int hash_version;
    } info;
    struct dx_entry *entries;
};

struct dx_frame {
    struct dx_entry *entries;
    struct dx_entry *at;
    struct buffer_head *bh;
};

struct dx_entry {
    unsigned int block;
    unsigned int count;
    unsigned int limit;
};

struct ext4_dir_entry_2 {
    unsigned int rec_len;
};

struct dx_hash_info {
    unsigned int hash_version;
    unsigned int seed;
};

typedef unsigned long ext4_lblk_t;
typedef void* handle_t;

#define KERN_DEBUG
#define dxtrace(x)
#define EXT4_DIR_REC_LEN(x) ((x)*8)
#define DX_HASH_TEA 0
#define EIO 5
#define EXT4_INDEX_FL 0x1000

static inline struct inode* EXT4_I(struct inode *inode) { return inode; }
static inline struct super_block* EXT4_SB(struct super_block *sb) { return sb; }
static inline void ext4_error(void *sb, const char *func, const char *msg, unsigned long ino) {}
static inline void ext4_std_error(void *sb, int err) {}
static inline int ext4_journal_get_write_access(handle_t *handle, struct buffer_head *bh) { return 0; }
static inline unsigned ext4_rec_len_from_disk(unsigned rec_len) { return rec_len; }
static inline unsigned ext4_rec_len_to_disk(unsigned rec_len) { return rec_len; }
static inline struct buffer_head *ext4_append(handle_t *handle, struct inode *dir, ext4_lblk_t *block, int *retval) { return NULL; }
static inline void ext4fs_dirhash(const char *name, int namelen, struct dx_hash_info *hinfo) {}
static inline struct ext4_dir_entry_2 *ext4_next_entry(struct ext4_dir_entry_2 *de) { return de; }
static inline struct ext4_dir_entry_2 *do_split(handle_t *handle, struct inode *dir, struct buffer_head **bh, struct dx_frame *frame, struct dx_hash_info *hinfo, int *retval) { return NULL; }
static inline void dx_release(struct dx_frame *frames) {}
static inline int add_dirent_to_buf(handle_t *handle, struct dentry *dentry, struct inode *inode, struct ext4_dir_entry_2 *de, struct buffer_head *bh) { return 0; }
static inline void brelse(struct buffer_head *bh) {}
static inline void dx_set_block(struct dx_entry *entries, int block) { entries->block = block; }
static inline void dx_set_count(struct dx_entry *entries, int count) { entries->count = count; }
static inline void dx_set_limit(struct dx_entry *entries, int limit) { entries->limit = limit; }
static inline int dx_root_limit(struct inode *dir, size_t info_size) { return 0; }