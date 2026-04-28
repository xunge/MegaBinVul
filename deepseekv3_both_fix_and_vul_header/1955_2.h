#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct fuse_conn {
    void *killsb;
    void *sb;
};

struct fuse_copy_state;

struct qstr {
    const char *name;
    unsigned int len;
    unsigned int hash;
};

struct fuse_notify_inval_entry_out {
    unsigned int parent;
    unsigned int namelen;
};

#define FUSE_NAME_MAX 1024
#define ENOMEM 12
#define EINVAL 22
#define ENAMETOOLONG 36
#define ENOENT 2
#define GFP_KERNEL 0

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *p) { free(p); }
static unsigned int full_name_hash(const char *name, unsigned int len) { return 0; }
static void down_read(void *lock) {}
static void up_read(void *lock) {}
static int fuse_copy_one(struct fuse_copy_state *cs, void *data, size_t size) { return 0; }
static void fuse_copy_finish(struct fuse_copy_state *cs) {}
static int fuse_reverse_inval_entry(void *sb, unsigned int parent, struct qstr *name) { return 0; }