#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

#define PAGE_SIZE 4096
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

typedef off_t loff_t;

struct page;
struct file;

struct inode {
    unsigned long i_ino;
};

struct fuse_conn {
    unsigned int max_pages;
    unsigned int max_read;
};

struct fuse_args_pages {
    struct page **pages;
    struct {
        size_t length;
    } *descs;
    unsigned int num_pages;
};

struct fuse_io_args {
    struct fuse_args_pages ap;
};

struct readahead_control {
    struct {
        struct inode *host;
    } *mapping;
    struct file *file;
};

static inline struct fuse_conn *get_fuse_conn(struct inode *inode) { return NULL; }
static inline bool is_bad_inode(struct inode *inode) { return false; }
static inline unsigned int readahead_count(struct readahead_control *rac) { return 0; }
static inline unsigned int __readahead_batch(struct readahead_control *rac, struct page **pages, unsigned int nr_pages) { return 0; }
static inline loff_t readahead_index(struct readahead_control *rac) { return 0; }
static inline void fuse_wait_on_page_writeback(struct inode *inode, loff_t index) {}
static inline struct fuse_io_args *fuse_io_alloc(void *arg, unsigned int nr_pages) { return NULL; }
static inline void fuse_send_readpages(struct fuse_io_args *ia, struct file *file) {}