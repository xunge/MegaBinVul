#include <stddef.h>

struct dentry {
    void *d_inode;
    void *d_lock;
    void *d_subdirs;
    void *d_fsdata;
    struct {
        struct dentry *d_child;
    } d_u;
};

struct ncp_server;

#define NCP_SERVER(x) ((struct ncp_server*)NULL)

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void ncp_age_dentry(struct ncp_server *server, struct dentry *dentry) {}

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (head); pos = NULL)