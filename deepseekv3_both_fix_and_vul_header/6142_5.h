#include <stddef.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define INET6_ADDRSTRLEN 46
#define NFS4_MAX_MINOR_VERSION 1
#define EINVAL 22
#define CONFIG_NFS_V4_1 1
#define IS_ENABLED(x) (x)

struct list_head {
    struct list_head *next, *prev;
};

struct nfs_client {
    struct list_head cl_ds_clients;
    struct list_head pending_cb_stateids;
    unsigned long cl_flags;
    unsigned long cl_res_state;
    unsigned long cl_state;
    int cl_mig_gen;
    const void *cl_mvops;
    void *cl_rpcclient;
    char cl_ipaddr[INET6_ADDRSTRLEN + 1];
    void *cl_lock;
    void *cl_renewd;
    void *cl_rpcwaitq;
    void *cl_lock_waitq;
};

struct nfs_client_initdata {
    const char *ip_addr;
    int minorversion;
};

struct nfs4_minor_version_ops;
extern struct nfs4_minor_version_ops *nfs_v4_minor_ops[];

enum {
    NFS4CLNT_LEASE_EXPIRED,
    NFS_CS_INFINITE_SLOTS,
    NFS_CS_DISCRTRY,
    NFS_CS_NO_RETRANS_TIMEOUT,
    NFS_CS_IDMAP
};

enum rpc_auth_flavor {
    RPC_AUTH_GSS_KRB5I,
    RPC_AUTH_UNIX
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define ERR_PTR(err) ((void *)(long)(err))
#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define spin_lock_init(lock) do { } while (0)
#define INIT_DELAYED_WORK(work, func) do { } while (0)
#define __set_bit(nr, addr) do { } while (0)
#define dprintk(fmt, ...) do { } while (0)

static inline struct nfs_client *nfs_alloc_client(const struct nfs_client_initdata *cl_init) { return NULL; }
static inline int nfs_get_cb_ident_idr(struct nfs_client *clp, int minorversion) { return 0; }
static inline void rpc_init_wait_queue(void *queue, const char *name) {}
static inline void nfs_free_client(struct nfs_client *clp) {}
static inline int nfs_create_rpc_client(struct nfs_client *clp, const struct nfs_client_initdata *cl_init, enum rpc_auth_flavor flavor) { return 0; }
static inline int rpc_localaddr(void *client, void *addr, size_t len) { return 0; }
static inline int rpc_ntop(void *sap, char *buf, size_t buflen) { return 0; }
static inline int nfs_idmap_new(struct nfs_client *clp) { return 0; }
static inline void init_waitqueue_head(void *wq_head) {}
static inline size_t strlcpy(char *dest, const char *src, size_t size) { return strncpy(dest, src, size), strlen(src); }