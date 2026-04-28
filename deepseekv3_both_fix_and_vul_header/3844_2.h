#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

typedef int boolean_t;
typedef struct vnode {
    int v_type;
} vnode_t;

typedef struct znode {
    uint64_t z_pflags;
    uint64_t z_uid;
    uint64_t z_gid;
    mode_t z_mode;
    pthread_mutex_t z_acl_lock;
} znode_t;

typedef struct cred {
    uid_t cr_uid;
    gid_t cr_gid;
} cred_t;

#define B_FALSE 0
#define B_TRUE 1

#define ZFS_AV_QUARANTINED 0x1
#define ZFS_XATTR 0x2
#define ZFS_NO_EXECS_DENIED 0x4

#define S_IXUSR 0100
#define S_IXGRP 0010
#define S_IXOTH 0001

#define VDIR 1

#define FUID_INDEX(x) ((uint32_t)((x) >> 32))

static inline vnode_t* ZTOV(znode_t *zdp) { return (vnode_t*)zdp; }
static inline uid_t crgetuid(cred_t *cr) { return cr->cr_uid; }
static inline int groupmember(gid_t gid, cred_t *cr) { return cr->cr_gid == gid; }
static inline void mutex_enter(pthread_mutex_t *lock) { pthread_mutex_lock(lock); }
static inline void mutex_exit(pthread_mutex_t *lock) { pthread_mutex_unlock(lock); }