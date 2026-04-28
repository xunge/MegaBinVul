#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

typedef int32_t key_serial_t;
typedef uid_t kuid_t;
typedef gid_t kgid_t;

struct key_user {
    void *lock;
    int nkeys;
    int nikeys;
    unsigned qnkeys;
    unsigned qnbytes;
};

struct key {
    void *sem;
    struct key_user *user;
    kuid_t uid;
    kgid_t gid;
    unsigned long flags;
    size_t quotalen;
    int state;
};

typedef long key_ref_t;

#define KEY_LOOKUP_CREATE 0x01
#define KEY_LOOKUP_PARTIAL 0x02
#define KEY_NEED_SETATTR 0x10

#define KEY_FLAG_IN_QUOTA 0
#define KEY_FLAG_INSTANTIATED 1
#define KEY_IS_UNINSTANTIATED 0

#define CAP_SYS_ADMIN 0

#define EINVAL 22
#define EACCES 13
#define ENOMEM 12
#define EDQUOT 122

#define GLOBAL_ROOT_UID 0

#define IS_ERR(x) ((x) < 0)
#define PTR_ERR(x) (x)

static inline bool uid_eq(kuid_t left, kuid_t right) { return left == right; }
static inline bool gid_eq(kgid_t left, kgid_t right) { return left == right; }
static inline kuid_t make_kuid(void *ns, uid_t uid) { return uid; }
static inline kgid_t make_kgid(void *ns, gid_t gid) { return gid; }
static inline bool uid_valid(kuid_t uid) { return uid != (uid_t)-1; }
static inline bool gid_valid(kgid_t gid) { return gid != (gid_t)-1; }
static inline int capable(int cap) { return 1; }
static inline bool in_group_p(kgid_t grp) { return true; }
static inline void down_write(void *sem) {}
static inline void up_write(void *sem) {}
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline int test_bit(int nr, unsigned long *addr) { return (*addr >> nr) & 1; }

static inline void atomic_dec(int *v) { (*v)--; }
static inline void atomic_inc(int *v) { (*v)++; }

extern void *current_user_ns(void);
extern key_ref_t lookup_user_key(key_serial_t id, unsigned long flags, int need_perm);
extern struct key *key_ref_to_ptr(key_ref_t key_ref);
extern void key_put(struct key *key);
extern struct key_user *key_user_lookup(kuid_t uid);
extern void key_user_put(struct key_user *user);

extern unsigned key_quota_root_maxkeys;
extern unsigned key_quota_root_maxbytes;
extern unsigned key_quota_maxkeys;
extern unsigned key_quota_maxbytes;