#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef enum { B_FALSE, B_TRUE } boolean_t;

typedef struct zfsvfs {
    // dummy structure
} zfsvfs_t;

typedef struct cred {
    // dummy structure
} cred_t;

typedef struct ksid_domain {
    char *kd_name;
} ksid_domain_t;

typedef struct ksid {
    uint64_t ks_id;
    ksid_domain_t *ks_domain;
    uint32_t ks_rid;
} ksid_t;

typedef struct ksidlist {
    ksid_t *ksl_sids;
    uint32_t ksl_nsid;
} ksidlist_t;

typedef unsigned int uid_t;

#define HAVE_KSID
#define KSID_GROUP 0
#define IDMAP_WK_CREATOR_GROUP_GID 0
#define IDMAP_WK_CREATOR_SID_AUTHORITY ""
#define ZFS_GROUP 0
#define FUID_INDEX(id) ((id) >> 32)
#define FUID_RID(id) ((id) & 0xFFFFFFFF)

static ksid_t *crgetsid(cred_t *cr, int type) { return NULL; }
static ksidlist_t *crgetsidlist(cred_t *cr) { return NULL; }
static const char *zfs_fuid_find_by_idx(zfsvfs_t *zfsvfs, uint32_t idx) { return NULL; }
static uid_t zfs_fuid_map_id(zfsvfs_t *zfsvfs, uint64_t id, cred_t *cr, int type) { return 0; }
static boolean_t groupmember(uid_t gid, cred_t *cr) { return B_FALSE; }