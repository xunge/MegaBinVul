#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

struct cachefiles_volume {
    struct {
        unsigned int coherency_len;
        const void *coherency;
        unsigned int debug_id;
    } *vcookie;
    struct dentry *dentry;
    void *cache;
};

struct dentry;
struct inode {
    unsigned long i_ino;
};

struct user_namespace {
    // placeholder
};

struct cachefiles_vol_xattr {
    uint32_t reserved;
    char data[];
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define cpu_to_be32(x) (x)

static struct user_namespace init_user_ns;
static const char *cachefiles_xattr_cache = "cache";
static const int cachefiles_trace_setxattr_error = 0;
static const int cachefiles_coherency_vol_set_fail = 0;
static const int cachefiles_coherency_vol_set_ok = 1;

static inline void *_enter(const char *fmt, ...) { return NULL; }
static inline void _leave(const char *fmt, ...) {}
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline struct inode *d_inode(const struct dentry *dentry) { return NULL; }
static inline int cachefiles_inject_write_error(void) { return 0; }
static inline int vfs_setxattr(struct user_namespace *ns, struct dentry *dentry, 
                              const char *name, const void *value, size_t size, int flags) { return 0; }
static inline void trace_cachefiles_vfs_error(void *a, struct inode *b, int c, int d) {}
static inline void trace_cachefiles_vol_coherency(struct cachefiles_volume *a, unsigned long b, int c) {}
static inline void cachefiles_io_error(void *cache, const char *fmt, ...) {}