#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

typedef unsigned short kgid_t;

struct sock;
struct net;
struct group_info {
    int ngroups;
    int nblocks;
    kgid_t **blocks;
};

#define NGROUPS_PER_BLOCK 32
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline int gid_lte(kgid_t left, kgid_t right) {
    return left <= right;
}

static inline struct net *sock_net(struct sock *sk) {
    return NULL;
}

static inline kgid_t current_egid(void) {
    return 0;
}

static inline struct group_info *get_current_groups(void) {
    return NULL;
}

static inline void inet_get_ping_group_range_net(struct net *net, kgid_t *low, kgid_t *high) {
    *low = 0;
    *high = 0;
}