#include <stddef.h>
#include <stdbool.h>

struct address_space {
    struct inode *host;
};

struct inode;
struct fuse_conn {
    unsigned max_pages;
};
struct page;

struct fuse_fill_wb_data {
    struct inode *inode;
    void *wpa;
    void *ff;
    struct page **orig_pages;
};

#define EIO 5
#define ENOMEM 12
#define GFP_NOFS 0
#define WARN_ON(condition) ((void)0)

static struct fuse_conn *get_fuse_conn(struct inode *inode) { return NULL; }
static int is_bad_inode(struct inode *inode) { return 0; }
static void *kcalloc(size_t n, size_t size, int flags) { return NULL; }
static void kfree(const void *objp) {}
static int write_cache_pages(struct address_space *mapping, 
                           struct writeback_control *wbc,
                           void *filler, 
                           struct fuse_fill_wb_data *data) { return 0; }
static void fuse_writepages_send(struct fuse_fill_wb_data *data) {}
static void fuse_file_put(void *ff, bool arg1, bool arg2) {}
static int fuse_writepages_fill(struct page *page, 
                              struct writeback_control *wbc, 
                              void *data) { return 0; }