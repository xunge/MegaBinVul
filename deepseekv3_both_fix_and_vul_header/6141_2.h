#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define INET6_ADDRSTRLEN 46
#define NFS_CS_READY 0
#define NFS_CS_INFINITE_SLOTS 0
#define NFS_CS_DISCRTRY 0
#define NFS_CS_NO_RETRANS_TIMEOUT 0
#define NFS_CS_IDMAP 0
#define NFS_CS_TSM_POSSIBLE 0
#define RPC_AUTH_GSS_KRB5I 0
#define RPC_AUTH_UNIX 1
#define EINVAL 22
#define EPERM 1

struct nfs_client {
    int cl_cons_state;
    void *rpc_ops;
    unsigned long cl_flags;
    unsigned long cl_res_state;
    char cl_ipaddr[INET6_ADDRSTRLEN + 1];
    int cl_minorversion;
    void *cl_rpcclient;
    bool cl_preserve_clid;
};

struct nfs_client_initdata {
    const char *ip_addr;
};

struct nfs_v4_clientops;
extern struct nfs_v4_clientops nfs_v4_clientops;

#define __set_bit(nr, addr) ((*(addr)) |= (1UL << (nr)))
#define clear_bit(nr, addr) ((*(addr)) &= ~(1UL << (nr)))

static inline void *ERR_PTR(long error) {
    return (void *)error;
}

static inline size_t strlcpy(char *dest, const char *src, size_t size) {
    strncpy(dest, src, size);
    dest[size-1] = '\0';
    return strlen(src);
}

int nfs_create_rpc_client(struct nfs_client *, const struct nfs_client_initdata *, int);
int nfs_idmap_new(struct nfs_client *);
int nfs4_init_client_minor_version(struct nfs_client *);
int nfs4_discover_server_trunking(struct nfs_client *, struct nfs_client **);
void nfs_mark_client_ready(struct nfs_client *, int);
void nfs_put_client(struct nfs_client *);
int rpc_localaddr(void *, struct sockaddr *, int);
int rpc_ntop(const struct sockaddr *, char *, size_t);
int dprintk(const char *format, ...);