#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#define ATTR_SIZE          0x0001
#define ATTR_UID          0x0002
#define ATTR_GID          0x0004
#define ATTR_MODE         0x0008
#define ATTR_MTIME_SET    0x0010
#define ATTR_ATIME_SET    0x0020
#define ATTR_TIMES_SET    0x0040
#define ATTR_FORCE        0x0080

#define CAP_CHOWN         0
#define CAP_FSETID        4

#define S_ISGID           02000

#define EPERM             1

struct inode {
    uid_t i_uid;
    gid_t i_gid;
};

struct iattr {
    unsigned int ia_valid;
    off_t ia_size;
    uid_t ia_uid;
    gid_t ia_gid;
    mode_t ia_mode;
};

static inline bool uid_eq(uid_t left, uid_t right) { return left == right; }
static inline bool gid_eq(gid_t left, gid_t right) { return left == right; }

static inline uid_t current_fsuid(void) { return getuid(); }
static inline bool in_group_p(gid_t grp) { return getgid() == grp || getegid() == grp; }

static inline bool inode_owner_or_capable(const struct inode *inode) { return false; }
static inline bool inode_capable(const struct inode *inode, int cap) { return false; }
static inline int inode_newsize_ok(const struct inode *inode, off_t size) { return 0; }