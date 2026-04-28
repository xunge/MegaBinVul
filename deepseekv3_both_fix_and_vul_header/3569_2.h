#include <stdint.h>
#include <string.h>

typedef uint8_t u8;

#define CAP_NET_ADMIN 0
#define EPERM 1
#define EINVAL 2
#define EPFNOSUPPORT 3
#define AF_CAN 4
#define CGW_TYPE_CAN_CAN 5

struct sk_buff;
struct nlmsghdr;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct cf_mod {
    // Placeholder for CAN frame modification structure
    int dummy;
};

struct can_can_gw {
    int src_idx;
    int dst_idx;
};

struct cgw_job {
    int flags;
    u8 limit_hops;
    struct cf_mod mod;
    struct can_can_gw ccgw;
    struct hlist_node list;
};

struct rtcanmsg {
    int can_family;
    int gwtype;
    int flags;
};

extern struct hlist_head cgw_list;
extern struct kmem_cache *cgw_cache;

#define ASSERT_RTNL()

static inline int capable(int cap) { return 0; }
static inline int nlmsg_len(struct nlmsghdr *nlh) { return 0; }
static inline void *nlmsg_data(struct nlmsghdr *nlh) { return NULL; }
static inline void hlist_del(struct hlist_node *n) {}
static inline void kmem_cache_free(struct kmem_cache *cache, void *obj) {}

int cgw_parse_attr(struct nlmsghdr *nlh, struct cf_mod *mod, int cgwtype, struct can_can_gw *ccgw, u8 *limhops);
void cgw_remove_all_jobs(void);
void cgw_unregister_filter(struct cgw_job *gwj);

#define hlist_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos; pos = NULL)