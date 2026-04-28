#include <stdlib.h>
#include <string.h>

#define GFP_KERNEL 0
#define RCU_INIT_POINTER(p, v) ((p) = (v))
#define struct_size(p, member, n) (sizeof(*(p)) + sizeof((p)->member[0]) * (n))
#define TCA_U32_ACT 0
#define TCA_U32_POLICE 0

struct net;
struct tcf_proto;

struct tc_u32_key {
    unsigned int val;
    unsigned int mask;
    int off;
    int offmask;
};

struct tc_u32_sel {
    unsigned char nkeys;
    struct tc_u32_key keys[];
};

struct tcf_exts {
    int dummy;
};

struct tc_u_hnode {
    int refcnt;
    struct tc_u_knode *next;
};

struct tc_u_knode {
    struct tc_u_hnode *ht_down;
    struct tc_u_knode *next;
    struct tc_u_hnode *ht_up;
    unsigned int handle;
    int ifindex;
    int fshift;
    struct tc_u32_sel sel;
    struct tcf_exts exts;
    int flags;
    struct tc_u32_sel *res;
    void *pf;
    unsigned int val;
    unsigned int mask;
    void *pcpu_success;
};

static inline struct tc_u_hnode *rtnl_dereference(void *p) {
    return p;
}

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static void kfree(void *ptr) {
    free(ptr);
}

static int tcf_exts_init(struct tcf_exts *exts, struct net *net, int act, int police) {
    return 0;
}