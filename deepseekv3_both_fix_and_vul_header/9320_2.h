#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <stdint.h>

#define PAGE_CACHE_SIZE 4096
#define PAGE_CACHE_SHIFT 12
#define EFAULT 14
#define ENOMEM 12

typedef uint64_t pgoff_t;
typedef int64_t loff_t;

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

struct page {};
struct inode {
    struct address_space *i_mapping;
};
struct address_space {
    struct inode *host;
};
struct iov_iter {};
struct fuse_req {
    struct {
        int argpages;
    } in;
    struct page **pages;
    struct {
        unsigned int offset;
        size_t length;
    } *page_descs;
    unsigned int num_pages;
    unsigned int max_pages;
};
struct fuse_conn {
    size_t max_write;
    int big_writes;
};

static struct fuse_conn *get_fuse_conn(struct inode *inode) { return NULL; }
static size_t iov_iter_count(struct iov_iter *i) { return 0; }
static int iov_iter_fault_in_readable(struct iov_iter *i, size_t bytes) { return 0; }
static struct page *grab_cache_page_write_begin(struct address_space *mapping, pgoff_t index, unsigned flags) { return NULL; }
static int mapping_writably_mapped(struct address_space *mapping) { return 0; }
static void flush_dcache_page(struct page *page) {}
static size_t iov_iter_copy_from_user_atomic(struct page *page, struct iov_iter *i, unsigned offset, size_t bytes) { return 0; }
static void unlock_page(struct page *page) {}
static void page_cache_release(struct page *page) {}
static size_t iov_iter_single_seg_count(struct iov_iter *i) { return 0; }
static void iov_iter_advance(struct iov_iter *i, size_t bytes) {}