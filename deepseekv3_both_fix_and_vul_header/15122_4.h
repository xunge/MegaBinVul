#include <stddef.h>
#include <string.h>

#define ERR_PTR(err) ((void *)((long)(err)))
#define ENOMEM 12
#define BUG_ON(condition) ((void)0)
#define dprintk(fmt, ...) ((void)0)

#define NFS3_MAXNAMLEN 255
#define NFS2_MAXNAMLEN 255
#define NFS_MOUNT_NORDIRPLUS 0x0001
#define NFS_CAP_READDIRPLUS 0x0001
#define NFS_ATTR_FATTR 0x0001

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct nfs_fh;
struct nfs_fattr;
struct nfs_server;
struct nfs_mount_data;

struct file_operations;

struct rpc_ops {
    int version;
    int (*getattr)(struct nfs_server *, struct nfs_fh *, struct nfs_fattr *);
    struct file_operations *file_inode_ops;
};

struct nfs_client {
    struct rpc_ops *rpc_ops;
    struct list_head cl_superblocks;
};

struct nfs_fattr {
    unsigned int valid;
    struct {
        unsigned long long major;
        unsigned long long minor;
    } fsid;
};

struct nfs_mount_data {
    unsigned int flags;
};

struct nfs_server {
    struct nfs_client *nfs_client;
    unsigned int namelen;
    unsigned int caps;
    struct {
        unsigned long long major;
        unsigned long long minor;
    } fsid;
    struct list_head client_link;
    struct list_head master_link;
    unsigned long mount_time;
};

static struct list_head nfs_volume_list = { &nfs_volume_list, &nfs_volume_list };
static int nfs_client_lock;
static unsigned long jiffies = 0;

static void spin_lock(int *lock) {}
static void spin_unlock(int *lock) {}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

extern struct nfs_server *nfs_alloc_server(void);
extern void nfs_free_server(struct nfs_server *server);
extern int nfs_init_server(struct nfs_server *server, const struct nfs_mount_data *data);
extern int nfs_probe_fsinfo(struct nfs_server *server, struct nfs_fh *mntfh, struct nfs_fattr *fattr);