#include <stddef.h>
#include <stdbool.h>

typedef unsigned int gfp_t;

struct fuse_conn {
    bool cache_symlinks;
};

struct inode;
struct dentry;
struct delayed_call;
struct page;

#define GFP_KERNEL 0
#define EIO 1
#define ECHILD 2
#define ENOMEM 3

static inline struct fuse_conn *get_fuse_conn(struct inode *inode) { return NULL; }
static inline bool is_bad_inode(struct inode *inode) { return false; }
static inline const char *page_get_link(struct dentry *dentry, struct inode *inode, struct delayed_call *callback) { return NULL; }
static inline void set_delayed_call(struct delayed_call *callback, void (*fn)(void *), void *arg) {}
static inline void page_put_link(void *arg) {}
static inline void *ERR_PTR(long error) { return NULL; }
static inline void *page_address(struct page *page) { return NULL; }
static inline struct page *alloc_page(gfp_t gfp_mask) { return NULL; }
static inline void __free_page(struct page *page) {}
static inline int fuse_readlink_page(struct inode *inode, struct page *page) { return 0; }