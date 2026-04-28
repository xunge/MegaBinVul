#include <string.h>
#include <errno.h>

#define XATTR_SYSTEM_PREFIX "system."
#define XATTR_SYSTEM_PREFIX_LEN (sizeof(XATTR_SYSTEM_PREFIX) - 1)
#define XATTR_TRUSTED_PREFIX "trusted."
#define XATTR_TRUSTED_PREFIX_LEN (sizeof(XATTR_TRUSTED_PREFIX) - 1)
#define XATTR_SECURITY_PREFIX "security."
#define XATTR_SECURITY_PREFIX_LEN (sizeof(XATTR_SECURITY_PREFIX) - 1)
#define XATTR_USER_PREFIX "user."
#define XATTR_USER_PREFIX_LEN (sizeof(XATTR_USER_PREFIX) - 1)
#define XATTR_OS2_PREFIX "os2."
#define XATTR_OS2_PREFIX_LEN (sizeof(XATTR_OS2_PREFIX) - 1)

struct inode;

static int can_set_system_xattr(struct inode *inode, const char *name,
			 const void *value, size_t value_len);