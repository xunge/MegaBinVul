#include <string.h>
#include <stdlib.h>

#define XATTR_NAME_MAX 255
#define XATTR_SIZE_MAX 65536
#define XATTR_CREATE 0x1
#define XATTR_REPLACE 0x2

#define EINVAL 22
#define ERANGE 34
#define E2BIG 7
#define ENOMEM 12
#define EFAULT 14

#define GFP_KERNEL 0

struct dentry;

#define __user

void *kvmalloc(size_t size, int flags);
void kvfree(const void *addr);
int strncpy_from_user(char *dest, const char *src, long count);
long copy_from_user(void *to, const void *from, unsigned long n);
int vfs_setxattr(struct dentry *dentry, const char *name, const void *value, size_t size, int flags);
void posix_acl_fix_xattr_from_user(void *kvalue, size_t size);
int cap_convert_nscap(struct dentry *dentry, void **ivalue, size_t size);

#define XATTR_NAME_POSIX_ACL_ACCESS "system.posix_acl_access"
#define XATTR_NAME_POSIX_ACL_DEFAULT "system.posix_acl_default"
#define XATTR_NAME_CAPS "security.capability"