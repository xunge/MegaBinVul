#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t ext4_lblk_t;
typedef long ssize_t;

struct buffer_head {
    void *b_data;
};

struct inode {
    uint64_t i_size;
    unsigned long i_ino;
    struct super_block *i_sb;
};

struct super_block {
    unsigned long s_blocksize;
};

struct ext4_dir_entry {
    uint32_t inode;
    uint16_t rec_len;
    uint16_t name_len;
    char name[];
};

struct task_struct {
    char comm[16];
};

extern struct task_struct *current;

typedef enum {
    INDEX,
    DIRENT_HTREE
} dirblock_type_t;

#define EXT4_SIM_DIRBLOCK_EIO 0
#define EXT4_SIM_DIRBLOCK_CRC 0
#define EFSCORRUPTED EUCLEAN
#define EFSBADCRC EBADMSG
#define EIO 5
#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(long)(x))

static inline int ext4_simulate_fail(void *sb, int flag) { return 0; }
static inline struct buffer_head *ext4_bread(void *a, struct inode *b, ext4_lblk_t c, int d) { return NULL; }
static inline void __ext4_warning(void *sb, const char *func, unsigned int line, const char *fmt, ...) {}
static inline void ext4_error_inode(struct inode *inode, const char *func, unsigned int line, ext4_lblk_t block, const char *fmt, ...) {}
static inline void ext4_error_inode_err(struct inode *inode, const char *func, unsigned int line, ext4_lblk_t block, int err, const char *fmt, ...) {}
static inline int is_dx(struct inode *inode) { return 0; }
static inline unsigned int ext4_rec_len_from_disk(uint16_t len, unsigned long blocksize) { return 0; }
static inline void brelse(struct buffer_head *bh) {}
static inline int ext4_has_metadata_csum(void *sb) { return 0; }
static inline int buffer_verified(struct buffer_head *bh) { return 0; }
static inline int ext4_dx_csum_verify(struct inode *inode, struct ext4_dir_entry *dirent) { return 0; }
static inline void set_buffer_verified(struct buffer_head *bh) {}
static inline int ext4_dirblock_csum_verify(struct inode *inode, struct buffer_head *bh) { return 0; }