#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef int64_t loff_t;
typedef uint32_t ext4_lblk_t;
typedef unsigned int umode_t;

#define EXT_MAX_BLOCKS 0xffffffff
#define EXT4_HT_MISC 0
#define EXT4_INODE_EOFBLOCKS 0
#define EXT4_INODE_EXTENTS 0
#define EXT4_GET_BLOCKS_CREATE_UNWRIT_EXT 0
#define EXT4_GET_BLOCKS_CONVERT_UNWRITTEN 0
#define EXT4_EX_NOCACHE 0
#define EXT4_GET_BLOCKS_KEEP_SIZE 0
#define PAGECACHE_TAG_DIRTY 0
#define FALLOC_FL_KEEP_SIZE 0
#define O_SYNC 0
#define EINVAL 22
#define EOPNOTSUPP 95

struct mutex {
    int dummy;
};

struct super_block {
    int dummy;
};

struct address_space {
    unsigned long nrpages;
};

struct inode {
    struct super_block *i_sb;
    struct address_space *i_mapping;
    unsigned int i_blkbits;
    umode_t i_mode;
    loff_t i_size;
    struct mutex i_mutex;
    unsigned long i_mtime;
    unsigned long i_ctime;
    unsigned long i_flags;
};

struct file {
    struct inode *f_inode;
    unsigned int f_flags;
};

struct handle_s;
typedef struct handle_s handle_t;

static inline int ext4_ext_index_trans_blocks(struct inode *inode, int n) { return 0; }

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}

#define ext4_should_journal_data(inode) 0
#define ext4_test_inode_flag(inode, flag) 0
#define ext4_set_inode_flag(inode, flag) do {} while (0)
#define ext4_current_time(inode) 0
#define ext4_inode_block_unlocked_dio(inode) do {} while (0)
#define ext4_inode_resume_unlocked_dio(inode) do {} while (0)
#define ext4_es_remove_extent(inode, start, len) 0
#define ext4_alloc_file_blocks(file, lblk, len, new_size, flags, mode) 0
#define ext4_zero_partial_blocks(handle, inode, offset, len) 0
#define ext4_handle_sync(handle) do {} while (0)
#define ext4_journal_start(inode, type, credits) NULL
#define ext4_journal_stop(handle) do {} while (0)
#define ext4_std_error(sb, err) do {} while (0)
#define ext4_mark_inode_dirty(handle, inode) do {} while (0)
#define ext4_update_inode_size(inode, size) do {} while (0)
#define ext4_force_commit(sb) 0
#define trace_ext4_zero_range(inode, offset, len, mode) do {} while (0)
#define IS_ERR(ptr) 0
#define PTR_ERR(ptr) 0
#define S_ISREG(mode) 1

static inline struct inode *file_inode(struct file *file) { return file->f_inode; }
static inline loff_t i_size_read(struct inode *inode) { return inode->i_size; }
static inline int inode_newsize_ok(struct inode *inode, loff_t offset) { return 0; }
static inline int mapping_tagged(struct address_space *mapping, int tag) { return 0; }
static inline int filemap_write_and_wait_range(struct address_space *mapping, loff_t start, loff_t end) { return 0; }
static inline void truncate_pagecache_range(struct inode *inode, loff_t start, loff_t end) {}
static inline void inode_dio_wait(struct inode *inode) {}
static inline loff_t round_up(loff_t x, loff_t y) { return x; }
static inline loff_t round_down(loff_t x, loff_t y) { return x; }