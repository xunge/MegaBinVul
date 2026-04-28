#include <stdlib.h>
#include <errno.h>

#define PAGE_SIZE 4096
#define GFP_KERNEL 0

#define ACL_TYPE_ACCESS 0
#define ACL_TYPE_DEFAULT 1

#define XATTR_NAME_POSIX_ACL_ACCESS "system.posix_acl_access"
#define XATTR_NAME_POSIX_ACL_DEFAULT "system.posix_acl_default"

#define ENODATA 61
#define EOPNOTSUPP 95
#define ERANGE 34
#define E2BIG 7
#define ENOMEM 12

struct fuse_conn {
    int posix_acl;
    int no_getxattr;
    void *user_ns;
};

struct inode;
struct posix_acl;

#define ERR_PTR(err) ((void *)(long)(err))

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}