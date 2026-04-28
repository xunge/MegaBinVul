#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <netinet/in.h>

#define ERR_PTR(err) ((void *)((long)(err)))
#define ENOMEM 12
#define BUG_ON(condition) do { if (condition) abort(); } while (0)
#define NFS4_MAXNAMLEN 255

typedef unsigned int rpc_authflavor_t;
typedef unsigned long spinlock_t;
typedef unsigned long jiffies_t;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct nfs_fattr {
    unsigned int dummy;
};

struct nfs4_mount_data {
    int proto;
    int timeo;
    int retrans;
};

struct rpc_ops {
    struct file_inode_ops *file_inode_ops;
};

struct file_inode_ops {
    int dummy;
};

struct nfs_client {
    struct rpc_ops *rpc_ops;
    struct list_head cl_superblocks;
};

struct nfs_server {
    struct {
        unsigned long major;
        unsigned long minor;
    } fsid;
    unsigned int namelen;
    struct nfs_client *nfs_client;
    struct list_head client_link;
    struct list_head master_link;
    jiffies_t mount_time;
};

struct nfs_fh {
    int size;
};

extern struct list_head nfs_volume_list;
extern spinlock_t nfs_client_lock;
extern jiffies_t jiffies;
extern struct nfs_server *nfs_alloc_server(void);
extern void nfs_free_server(struct nfs_server *);
extern int nfs4_set_client(struct nfs_server *, const char *, const struct sockaddr_in *, const char *, rpc_authflavor_t, int, int, int);
extern int nfs4_init_server(struct nfs_server *, const struct nfs4_mount_data *, rpc_authflavor_t);
extern int nfs4_path_walk(struct nfs_server *, struct nfs_fh *, const char *);
extern int nfs_probe_fsinfo(struct nfs_server *, struct nfs_fh *, struct nfs_fattr *);
extern void dprintk(const char *fmt, ...);

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline void list_add_tail(struct list_head *new, struct list_head *head) { (void)new; (void)head; }