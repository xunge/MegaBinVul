#include <linux/fs.h>
#include <linux/nfs_fs.h>
#include <linux/nfs4.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <stddef.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <linux/stddef.h>

struct super_block;
struct nfs_sb_info {
    struct super_block *sb;
};

struct inode {
    struct nfs_sb_info *i_sb;
};

struct nfs_server;
struct nfs_inode {
    struct inode vfs_inode;
    unsigned long cache_validity;
};

#define NFS_SERVER(inode) (NFS_SB((inode)->i_sb))
#define NFS_I(inode) ((struct nfs_inode *)(inode))
#define NFS_INO_INVALID_ACL 0x0004
#define EOPNOTSUPP 95
#define ENOENT 2

static inline struct nfs_server *NFS_SB(struct nfs_sb_info *sb) { return (struct nfs_server *)sb; }
static inline int nfs4_server_supports_acls(struct nfs_server *server) { return 0; }
static inline int nfs_revalidate_inode(struct nfs_server *server, struct inode *inode) { return 0; }
static inline void nfs_zap_acl_cache(struct inode *inode) {}
static inline ssize_t nfs4_read_cached_acl(struct inode *inode, void *buf, size_t buflen) { return -ENOENT; }
static inline ssize_t nfs4_get_acl_uncached(struct inode *inode, void *buf, size_t buflen) { return -ENOENT; }