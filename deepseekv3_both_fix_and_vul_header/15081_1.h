#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

struct file;
struct file_lock;
struct inode;
struct file_mapping {
    struct inode *host;
};

struct file {
    struct file_mapping *f_mapping;
};

struct nfs_server_info {
    unsigned int flags;
};

#define NFS_MOUNT_NONLM 0x0001
#define EINTR 4
#define ERESTARTSYS 512

static void lock_kernel(void) {}
static void unlock_kernel(void) {}
static int nfs_sync_mapping(struct file_mapping *mapping) { return 0; }
static int do_vfs_lock(struct file *filp, struct file_lock *fl) { return 0; }
static void nfs_zap_caches(struct inode *inode) {}

#define NFS_SERVER(inode) ((struct nfs_server_info *)0)
#define NFS_PROTO(inode) ((struct { int (*lock)(struct file*, int, struct file_lock*); }*)0)