#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef uint8_t u8;

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct mutex {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct ucma_file {
    struct mutex mut;
};

struct ucma_context {
    void *cm_id;
};

struct ucma_multicast {
    int id;
    u8 join_state;
    int uid;
    struct sockaddr addr;
    struct list_head list;
};

struct rdma_ucm_join_mcast {
    struct sockaddr addr;
    int addr_size;
    int join_flags;
    int id;
    int uid;
    uint64_t response;
};

struct rdma_ucm_create_id_resp {
    int id;
};

struct idr {
    int dummy;
};
extern struct idr multicast_idr;
extern struct mutex mut;

#define ENOSPC 1
#define EINVAL 2
#define ENOMEM 3
#define EFAULT 4

#define BIT(n) (1 << (n))
#define FULLMEMBER_JOIN 0
#define SENDONLY_FULLMEMBER_JOIN 1

#define RDMA_MC_JOIN_FLAG_FULLMEMBER 0
#define RDMA_MC_JOIN_FLAG_SENDONLY_FULLMEMBER 1

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000)
#define PTR_ERR(x) ((long)(x))

static inline void *u64_to_user_ptr(uint64_t addr) {
    return (void *)(uintptr_t)addr;
}

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void list_del(struct list_head *entry) {}
static inline void kfree(const void *objp) {}
static inline int idr_remove(struct idr *idp, int id) { return 0; }

static inline size_t rdma_addr_size(struct sockaddr *addr) {
    return sizeof(struct sockaddr);
}

static inline struct ucma_context *ucma_get_ctx_dev(struct ucma_file *file, int id) {
    return NULL;
}

static inline struct ucma_multicast *ucma_alloc_multicast(struct ucma_context *ctx) {
    return NULL;
}

static inline int rdma_join_multicast(void *cm_id, struct sockaddr *addr, u8 join_state, struct ucma_multicast *mc) {
    return 0;
}

static inline void ucma_put_ctx(struct ucma_context *ctx) {}

static inline void rdma_leave_multicast(void *cm_id, struct sockaddr *addr) {}

static inline void ucma_cleanup_mc_events(struct ucma_multicast *mc) {}