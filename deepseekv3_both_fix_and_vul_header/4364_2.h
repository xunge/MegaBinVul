#include <stddef.h>
#include <stdlib.h>
#include <errno.h>

#define GFP_KERNEL 0
#define ENOMEM 12

struct inode;
struct file {
    void *private_data;
};
struct list_head {
    struct list_head *next, *prev;
};
struct fuse_conn {
    void (*release)(struct fuse_conn *);
    int initialized;
};
struct cuse_conn {
    struct fuse_conn fc;
    struct list_head list;
};

static void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}
static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}
static void cuse_fc_release(struct fuse_conn *fc) {}
static int cuse_send_init(struct cuse_conn *cc) { return 0; }
static void fuse_conn_init(struct fuse_conn *fc) {}
static void fuse_conn_put(struct fuse_conn *fc) {}