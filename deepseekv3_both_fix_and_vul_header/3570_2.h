#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;

#define CAP_NET_ADMIN 1
#define EPERM 1
#define EINVAL 2
#define EPFNOSUPPORT 3
#define ENOMEM 4
#define ENODEV 5
#define AF_CAN 1
#define CGW_TYPE_CAN_CAN 1
#define ARPHRD_CAN 1
#define GFP_KERNEL 0

struct sk_buff;
struct nlmsghdr;

struct net_device {
    unsigned short type;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct rtcanmsg {
    int can_family;
    int gwtype;
    int flags;
};

struct cgw_job {
    unsigned long handled_frames;
    unsigned long dropped_frames;
    unsigned long deleted_frames;
    u8 flags;
    u8 gwtype;
    u8 limit_hops;
    struct {
        struct net_device *dev;
    } src, dst;
    struct {
        int src_idx;
        int dst_idx;
    } ccgw;
    struct {
        /* mod structure fields */
    } mod;
    struct hlist_node list;
};

extern struct kmem_cache *cgw_cache;
extern struct hlist_head cgw_list;
extern int cgw_parse_attr(struct nlmsghdr *nlh, void *mod, int gwtype, void *ccgw, u8 *limhops);
extern int cgw_register_filter(struct cgw_job *gwj);
extern int capable(int cap);
extern size_t nlmsg_len(struct nlmsghdr *nlh);
extern void *nlmsg_data(struct nlmsghdr *nlh);
extern void *kmem_cache_alloc(struct kmem_cache *cache, int flags);
extern void kmem_cache_free(struct kmem_cache *cache, void *obj);
extern void hlist_add_head_rcu(struct hlist_node *n, struct hlist_head *h);
extern struct net_device *__dev_get_by_index(void *net, int ifindex);
extern void ASSERT_RTNL(void);

static struct {
    struct net_device *dev;
} init_net;