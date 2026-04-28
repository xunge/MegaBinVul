#include <sys/types.h>
#include <stdint.h>

#define FUID_INDEX(fuid) ((fuid) >> 32)
#define FUID_RID(fuid) ((fuid) & 0xFFFFFFFF)
#define UID_NOBODY ((uid_t)-2)

typedef enum {
    ZFS_OWNER,
    ZFS_ACE_USER
} zfs_fuid_type_t;

typedef struct zfsvfs zfsvfs_t;
typedef struct cred cred_t;
typedef int zoneid_t;

#ifdef HAVE_KSID
const char *zfs_fuid_find_by_idx(zfsvfs_t *zfsvfs, uint32_t index);
int kidmap_getuidbysid(zoneid_t zone, const char *domain, uint32_t rid, uid_t *id);
int kidmap_getgidbysid(zoneid_t zone, const char *domain, uint32_t rid, gid_t *id);
zoneid_t crgetzone(cred_t *cr);
#endif