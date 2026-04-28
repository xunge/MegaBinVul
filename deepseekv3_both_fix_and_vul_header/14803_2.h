#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

#define IPCMNI 32768
#define IPCID_SEQ_MAX INT_MAX
#define ENOSPC 28
#define GFP_KERNEL 0
#define GFP_NOWAIT 0

typedef uint32_t kuid_t;
typedef uint32_t kgid_t;

struct idr {
    int dummy;
};

struct ipc_ids {
    struct idr ipcs_idr;
    int in_use;
    int next_id;
    int seq;
};

struct kern_ipc_perm {
    int lock;
    bool deleted;
    kuid_t uid;
    kuid_t cuid;
    kgid_t gid;
    kgid_t cgid;
    int seq;
    int id;
};

static inline void spin_lock_init(int *lock) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}
static inline void idr_preload(int flags) {}
static inline int idr_alloc(struct idr *idr, void *ptr, int start, int end, int flags) { return 0; }
static inline void idr_preload_end() {}
static inline void current_euid_egid(kuid_t *euid, kgid_t *egid) {}
static inline int ipcid_to_idx(int id) { return 0; }
static inline int ipcid_to_seqx(int id) { return 0; }
static inline int ipc_buildid(int id, int seq) { return 0; }