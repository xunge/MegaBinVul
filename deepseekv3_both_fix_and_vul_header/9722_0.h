#include <string.h>
#include <stdbool.h>

#define XATTR_SYSTEM_PREFIX "system."
#define XATTR_SYSTEM_PREFIX_LEN (sizeof(XATTR_SYSTEM_PREFIX) - 1)
#define XATTR_USER_PREFIX "user."
#define XATTR_USER_PREFIX_LEN (sizeof(XATTR_USER_PREFIX) - 1)
#define XATTR_SECURITY_PREFIX "security."
#define XATTR_SECURITY_PREFIX_LEN (sizeof(XATTR_SECURITY_PREFIX) - 1)
#define XATTR_TRUSTED_PREFIX "trusted."
#define XATTR_TRUSTED_PREFIX_LEN (sizeof(XATTR_TRUSTED_PREFIX) - 1)

struct jfs_ea {
    int namelen;
    char *name;
};