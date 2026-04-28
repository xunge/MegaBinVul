#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct inode;
struct ncp_server;

struct dentry {
    struct inode *d_inode;
    struct list_head d_subdirs;
    union {
        struct list_head d_child;
        struct {
            struct list_head d_u;
            struct list_head d_child;
        } d_u;
    };
    void *d_fsdata;
    int d_lock;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (struct dentry*)((head)->next); \
         &pos->member != (head); \
         pos = (struct dentry*)(pos->member.next))

#define spin_lock(lock) (void)(lock)
#define spin_unlock(lock) (void)(lock)
#define NCP_SERVER(inode) ((struct ncp_server *)NULL)

void ncp_age_dentry(struct ncp_server *server, struct dentry *dentry);
void ncp_new_dentry(struct dentry *dentry);