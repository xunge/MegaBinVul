#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2
#define EBUSY 3

#define TCA_TCINDEX_ACT 0
#define TCA_TCINDEX_POLICE 1
#define TCA_TCINDEX_HASH 2
#define TCA_TCINDEX_MASK 3
#define TCA_TCINDEX_SHIFT 4
#define TCA_TCINDEX_FALL_THROUGH 5
#define TCA_TCINDEX_CLASSID 6

#define PERFECT_HASH_THRESHOLD 16
#define DEFAULT_HASH_SIZE 64

typedef unsigned int u32;
typedef unsigned short u16;

struct net;
struct tcf_proto {
    void *root;
};
struct nlattr;
struct netlink_ext_ack;

struct rcu_work {
    int dummy;
};

struct tcf_result {
    u32 classid;
};

struct tcf_exts {
    int dummy;
};

struct tcindex_filter_result {
    struct tcf_exts exts;
    struct tcf_result res;
};

struct tcindex_filter {
    struct tcindex_filter_result result;
    struct tcindex_filter *next;
    u32 key;
    struct rcu_work rwork;
};

struct tcindex_data {
    struct tcindex_filter_result *perfect;
    struct tcindex_filter **h;
    u32 mask;
    u32 shift;
    u32 hash;
    u32 alloc_hash;
    u32 fall_through;
    struct tcf_proto *tp;
    struct rcu_work rwork;
    int refcnt;
};

static inline int min(int a, int b) { return a < b ? a : b; }
static inline void refcount_set(int *r, int value) { *r = value; }

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static void kfree(void *ptr) { free(ptr); }

static int tcf_exts_init(struct tcf_exts *exts, struct net *net, int act, int police) { return 0; }
static int tcf_exts_validate(struct net *net, struct tcf_proto *tp, struct nlattr **tb, 
                           struct nlattr *est, struct tcf_exts *exts, u32 flags,
                           struct netlink_ext_ack *extack) { return 0; }
static void tcf_exts_destroy(struct tcf_exts *exts) {}
static void tcf_exts_change(struct tcf_exts *dst, struct tcf_exts *src) {}

static u32 nla_get_u32(struct nlattr *nla) { return 0; }
static u16 nla_get_u16(struct nlattr *nla) { return 0; }

static int tcindex_filter_result_init(struct tcindex_filter_result *r, 
                                    struct tcindex_data *p, struct net *net) { return 0; }
static int tcindex_alloc_perfect_hash(struct net *net, struct tcindex_data *cp) { return 0; }
static void tcindex_free_perfect_hash(struct tcindex_data *cp) {}
static bool valid_perfect_hash(struct tcindex_data *cp) { return false; }
static bool tcindex_lookup(struct tcindex_data *cp, u32 handle) { return false; }

static void tcf_bind_filter(struct tcf_proto *tp, struct tcf_result *r, unsigned long base) {}
static void tcf_queue_work(struct rcu_work *rwork, void (*func)(struct rcu_work *)) {}
static void tcf_exts_get_net(struct tcf_exts *exts) {}

static void tcindex_destroy_fexts_work(struct rcu_work *work) {}
static void tcindex_partial_destroy_work(struct rcu_work *work) {}

#define rcu_assign_pointer(p, v) ((p) = (v))
#define rtnl_dereference(p) (p)
#define rcu_dereference_bh_rtnl(p) (p)
#define rcu_replace_pointer(p, v, f) ((p) = (v))
#define __rcu