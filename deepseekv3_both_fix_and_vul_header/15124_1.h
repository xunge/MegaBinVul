#include <stddef.h>
#include <stdint.h>

#define NFS2_MAXNAMLEN 255
#define NFS3_MAXNAMLEN 255
#define HZ 100
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define dprintk(fmt, ...) do {} while (0)

struct nfs_server {
    struct nfs_client *nfs_client;
    unsigned int flags;
    unsigned int rsize;
    unsigned int wsize;
    unsigned int acregmin;
    unsigned int acregmax;
    unsigned int acdirmin;
    unsigned int acdirmax;
    unsigned int namelen;
    unsigned int caps;
};

struct nfs_client {
    int cl_nfsversion;
};

struct nfs_mount_data {
    const char *hostname;
    void *addr;
    unsigned int flags;
    unsigned int rsize;
    unsigned int wsize;
    unsigned int acregmin;
    unsigned int acregmax;
    unsigned int acdirmin;
    unsigned int acdirmax;
    unsigned int namlen;
    unsigned int pseudoflavor;
};

#define NFS_MOUNT_VER3 0x0001
#define NFS_MOUNT_FLAGMASK 0xFFFF
#define NFS_MOUNT_NORDIRPLUS 0x0002
#define NFS_CAP_READDIRPLUS 0x0001
#define CONFIG_NFS_V3 1