#include <stdint.h>
#include <stddef.h>

typedef void *xfs_failaddr_t;

struct xfs_attr_sf_hdr {
    uint8_t count;
};

struct xfs_attr_sf_entry {
    uint8_t namelen;
    uint8_t flags;
};

struct xfs_attr_shortform {
    struct xfs_attr_sf_hdr hdr;
    struct xfs_attr_sf_entry list[];
};

struct xfs_ifork {
    unsigned int if_format;
    union {
        void *if_data;
    } if_u1;
    int64_t if_bytes;
};

struct xfs_inode {
    struct xfs_ifork *i_afp;
};

#define XFS_DINODE_FMT_LOCAL 1
#define XFS_ATTR_FORK 0
#define XFS_ATTR_NSP_ONDISK_MASK 0
#define __this_address ((void *)1)

#define XFS_IFORK_PTR(ip, fork) ((ip)->i_afp)
#define XFS_ATTR_SF_NEXTENTRY(sfep) \
    ((struct xfs_attr_sf_entry *)((char *)(sfep) + sizeof(struct xfs_attr_sf_entry) + (sfep)->namelen))

#define ASSERT(expr) ((void)0)

static inline int hweight8(uint8_t w) {
    int res = 0;
    while (w) {
        res += w & 1;
        w >>= 1;
    }
    return res;
}