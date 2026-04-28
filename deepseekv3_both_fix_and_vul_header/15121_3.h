#include <stddef.h>
#include <time.h>
#include <stdlib.h>

struct sockaddr;

struct list_head {
    struct list_head *next, *prev;
};

struct spinlock {
    int lock;
};
typedef struct spinlock spinlock_t;

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline void list_add_tail(struct list_head *new, struct list_head *head) { (void)new; (void)head; }

struct nfs_fattr {
    unsigned long fsid_major;
    unsigned long fsid_minor;
};

struct nfs_fh {
    unsigned char data[64];
};

struct rpc_xprt {
    unsigned int prot;
};

struct rpc_ops {
    void *file_inode_ops;
};

struct rpc_client {
    struct rpc_xprt *cl_xprt;
};

struct nfs_client {
    struct sockaddr *cl_ipaddr;
    unsigned int retrans_timeo;
    unsigned int retrans_count;
    struct list_head cl_superblocks;
    struct rpc_client *client;
    struct rpc_ops *rpc_ops;
};

struct nfs_server {
    struct nfs_client *nfs_client;
    struct rpc_client *client;
    unsigned int caps;
    unsigned int namelen;
    struct {
        unsigned long major;
        unsigned long minor;
    } fsid;
    struct list_head client_link;
    struct list_head master_link;
    unsigned long mount_time;
};

struct nfs_clone_mount {
    void *sb;
    const char *hostname;
    struct sockaddr *addr;
    int authflavor;
    const char *mnt_path;
};

#define ERR_PTR(err) ((void *)((long)(err)))
#define ENOMEM 12
#define NFS4_MAXNAMLEN 255
#define NFS_CAP_ATOMIC_OPEN (1 << 0)
#define BUG_ON(condition) do { if (condition) abort(); } while (0)

extern struct list_head nfs_volume_list;
extern spinlock_t nfs_client_lock;
extern int nfs4_set_client(struct nfs_server *, const char *, const struct sockaddr *,
                          const struct sockaddr *, int, unsigned int,
                          unsigned int, unsigned int);
extern void nfs_server_copy_userdata(struct nfs_server *, struct nfs_server *);
extern int nfs_init_server_rpcclient(struct nfs_server *, int);
extern int nfs4_path_walk(struct nfs_server *, struct nfs_fh *, const char *);
extern int nfs_probe_fsinfo(struct nfs_server *, struct nfs_fh *, struct nfs_fattr *);
extern struct nfs_server *nfs_alloc_server(void);
extern void nfs_free_server(struct nfs_server *);
extern struct nfs_server *NFS_SB(void *sb);
extern void dprintk(const char *fmt, ...);
extern unsigned long jiffies;