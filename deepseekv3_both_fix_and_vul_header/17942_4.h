#include <stdint.h>
#include <errno.h>
#include <stdlib.h>

#define XFS_ACL_MAX_ENTRIES 25
#define ACL_UNDEFINED_ID (-1)
#define GFP_KERNEL 0

struct posix_acl_entry {
    int e_tag;
    int e_perm;
    int e_id;
};

struct posix_acl {
    int a_count;
    struct posix_acl_entry a_entries[];
};

struct xfs_acl_entry {
    uint32_t ae_tag;
    uint16_t ae_perm;
    uint32_t ae_id;
};

struct xfs_acl {
    uint32_t acl_cnt;
    struct xfs_acl_entry acl_entry[];
};

#define ACL_USER 0x01
#define ACL_GROUP 0x02
#define ACL_USER_OBJ 0x04
#define ACL_GROUP_OBJ 0x08
#define ACL_MASK 0x10
#define ACL_OTHER 0x20

#define EFSCORRUPTED 117
#define ENOMEM 12
#define EINVAL 22

static inline uint32_t be32_to_cpu(uint32_t x) { return x; }
static inline uint16_t be16_to_cpu(uint16_t x) { return x; }

#define ERR_PTR(err) ((void *)(long)(err))

static struct posix_acl *posix_acl_alloc(int count, int flags) {
    struct posix_acl *acl = malloc(sizeof(struct posix_acl) + 
                                 count * sizeof(struct posix_acl_entry));
    if (acl) {
        acl->a_count = count;
    }
    return acl;
}

static void posix_acl_release(struct posix_acl *acl) {
    free(acl);
}

typedef struct posix_acl posix_acl;