#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

typedef struct zfsvfs zfsvfs_t;
typedef struct cred cred_t;
typedef struct zfs_fuid_info zfs_fuid_info_t;
typedef struct zfs_fuid zfs_fuid_t;
typedef struct list list_t;

typedef enum {
    ZFS_OWNER,
    ZFS_GROUP,
    ZFS_ACE_USER,
    ZFS_ACE_GROUP
} zfs_fuid_type_t;

typedef enum {
    IDMAP_SUCCESS,
    IDMAP_ERR_OTHER
} idmap_stat;

typedef enum {
    B_FALSE = 0,
    B_TRUE = 1
} boolean_t;

#define HAVE_KSID
#define FUID_INDEX(id) ((id) >> 32)
#define FUID_RID(id) ((id) & 0xFFFFFFFF)
#define FUID_ENCODE(idx, rid) (((uint64_t)(idx) << 32) | (rid))
#define IS_EPHEMERAL(id) ((id) > UINT32_MAX)
#define UID_NOBODY 65534
#define VERIFY3U(a, op, b) do { } while (0)

extern idmap_stat kidmap_getsidbyuid(void *, uint64_t, const char **, uint32_t *);
extern idmap_stat kidmap_getsidbygid(void *, uint64_t, const char **, uint32_t *);
extern void *crgetzone(cred_t *);
extern uint64_t zfs_fuid_find_by_domain(zfsvfs_t *, const char *, char **, boolean_t);
extern void zfs_fuid_node_add(zfs_fuid_info_t **, char *, uint32_t, uint64_t, uint64_t, zfs_fuid_type_t);
extern zfs_fuid_t *list_head(list_t *);
extern void list_remove(list_t *, zfs_fuid_t *);
extern void kmem_free(void *, size_t);

static const char *nulldomain = "";

struct zfs_fuid {
    uint64_t z_logfuid;
    struct zfs_fuid *z_next;
};

struct list {
    zfs_fuid_t *head;
};

struct zfs_fuid_info {
    uint64_t z_fuid_owner;
    uint64_t z_fuid_group;
    list_t z_fuids;
    char **z_domain_table;
};

struct zfsvfs {
    int z_use_fuids;
    int z_replay;
    zfs_fuid_info_t *z_fuid_replay;
};