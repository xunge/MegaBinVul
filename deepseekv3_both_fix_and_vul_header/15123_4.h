#include <stdint.h>
#include <errno.h>
#include <time.h>

typedef int spinlock_t;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct nfs_fh {
    uint8_t data[64];
    uint32_t size;
};

struct fsid {
    uint64_t major;
    uint64_t minor;
};

struct nfs_fattr {
    struct fsid fsid;
};

struct nfs_client {
    int cl_count;
    struct list_head cl_superblocks;
};

struct nfs_server {
    struct nfs_client *nfs_client;
    struct {
        struct {
            struct {
                int au_flavor;
            } *cl_auth;
        } *client;
    };
    void *client_acl;
    struct fsid fsid;
    unsigned int namelen;
    struct list_head client_link;
    struct list_head master_link;
    time_t mount_time;
};

extern struct nfs_server *nfs_alloc_server(void);
extern void nfs_free_server(struct nfs_server *);
extern void nfs_server_copy_userdata(struct nfs_server *, struct nfs_server *);
extern int nfs_init_server_rpcclient(struct nfs_server *, int);
extern void nfs_init_server_aclclient(struct nfs_server *);
extern int nfs_probe_fsinfo(struct nfs_server *, struct nfs_fh *, struct nfs_fattr *);
extern int nfs_start_lockd(struct nfs_server *);

spinlock_t nfs_client_lock;
struct list_head nfs_volume_list;

#define dprintk(fmt, ...) do {} while (0)
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define ERR_PTR(x) ((void *)(long)(x))
#define ENOMEM 12
#define NFS4_MAXNAMLEN 255
#define jiffies time(NULL)

static inline void atomic_inc(int *v) { (*v)++; }
static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}