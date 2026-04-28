#include <stddef.h>
#include <stdlib.h>

#define EIO 5
#define EOPNOTSUPP 95
#define EINVAL 22
#define E2BIG 7
#define ENOMEM 12
#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define ACL_TYPE_ACCESS 0
#define ACL_TYPE_DEFAULT 1
#define XATTR_NAME_POSIX_ACL_ACCESS "system.posix_acl_access"
#define XATTR_NAME_POSIX_ACL_DEFAULT "system.posix_acl_default"

struct inode;
struct posix_acl {
    int a_count;
};
struct fuse_conn {
    int posix_acl;
    int no_setxattr;
    void *user_ns;
};
struct fuse_conn *get_fuse_conn(struct inode *inode);
int fuse_is_bad(struct inode *inode);
size_t posix_acl_xattr_size(int count);
int posix_acl_to_xattr(void *user_ns, struct posix_acl *acl, void *value, size_t size);
int fuse_setxattr(struct inode *inode, const char *name, void *value, size_t size, int flags);
int fuse_removexattr(struct inode *inode, const char *name);
void forget_all_cached_acls(struct inode *inode);
void fuse_invalidate_attr(struct inode *inode);
void *kmalloc(size_t size, int flags);
void kfree(void *ptr);