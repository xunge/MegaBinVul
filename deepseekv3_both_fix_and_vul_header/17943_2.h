#include <stdint.h>
#include <errno.h>

#define XFS_ACL_MAX_ENTRIES 25
#define ACL_UNDEFINED_ID (-1)

#define ACL_USER 0x01
#define ACL_GROUP 0x02
#define ACL_USER_OBJ 0x04
#define ACL_GROUP_OBJ 0x08
#define ACL_MASK 0x10
#define ACL_OTHER 0x20

#define GFP_KERNEL 0
#define EFSCORRUPTED 117

struct xfs_acl_entry {
    uint32_t ae_tag;
    uint16_t ae_perm;
    uint32_t ae_id;
};

struct xfs_acl {
    uint32_t acl_cnt;
    struct xfs_acl_entry acl_entry[];
};

struct posix_acl_entry {
    uint16_t e_tag;
    uint16_t e_perm;
    uint32_t e_id;
};

struct posix_acl {
    int a_count;
    struct posix_acl_entry a_entries[];
};

static inline uint16_t be16_to_cpu(uint16_t x) { return x; }
static inline uint32_t be32_to_cpu(uint32_t x) { return x; }

#define ERR_PTR(x) ((struct posix_acl *)(long)(x))

struct posix_acl *posix_acl_alloc(int count, int flags);
void posix_acl_release(struct posix_acl *acl);

typedef struct posix_acl posix_acl;