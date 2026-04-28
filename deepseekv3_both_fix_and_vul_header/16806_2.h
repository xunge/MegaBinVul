#include <stddef.h>
#include <stdint.h>
#include <string.h>

struct dentry;
struct user_namespace;
struct super_block;

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    struct user_namespace *s_user_ns;
};

typedef uint32_t __u32;
typedef uint32_t __le32;
typedef int kuid_t;
typedef int uid_t;

struct vfs_cap_data {
    __le32 magic_etc;
    __le32 data[2 * 2];
};

struct vfs_ns_cap_data {
    __le32 magic_etc;
    __le32 rootid;
    __le32 data[2 * 2];
};

#define VFS_CAP_REVISION_3 0x03000000
#define VFS_CAP_FLAGS_EFFECTIVE 0x000001
#define XATTR_CAPS_SZ_2 (sizeof(struct vfs_cap_data))
#define VFS_CAP_U32 2
#define GFP_ATOMIC 0
#define ENOMEM 12
#define EINVAL 22
#define EPERM 1
#define CAP_SETFCAP 0

static inline __le32 cpu_to_le32(__u32 x) { return x; }
static inline __u32 le32_to_cpu(__le32 x) { return x; }
static inline int uid_valid(kuid_t uid) { return 1; }
static inline uid_t from_kuid(struct user_namespace *ns, kuid_t uid) { return uid; }

void *kmalloc(size_t size, int flags);
void kvfree(const void *addr);
struct inode *d_backing_inode(struct dentry *dentry);
struct user_namespace *current_user_ns();
int capable_wrt_inode_uidgid(struct inode *inode, int cap);
int ns_capable(struct user_namespace *ns, int cap);
kuid_t rootid_from_xattr(const void *value, size_t size, struct user_namespace *ns);
int validheader(size_t size, const struct vfs_cap_data *cap);