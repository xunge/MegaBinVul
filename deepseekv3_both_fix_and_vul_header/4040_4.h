#include <stdint.h>
#include <stddef.h>

struct net;
struct netlink_ext_ack;
struct nlattr;

struct tcf_proto {
    void *data;
};

struct tc_u_hnode {
    unsigned int refcnt;
    int is_root;
};

struct tc_u_knode {
    struct tc_u_hnode *ht_down;
    struct {
        uint32_t classid;
    } res;
    int ifindex;
    struct {
        /* dummy exts structure */
    } exts;
};

#define TCA_U32_LINK 1
#define TCA_U32_CLASSID 2
#define TCA_U32_INDEV 3

#define TC_U32_KEY(h) ((h) & 0x80000000)
#define EINVAL 22

typedef uint32_t u32;

/* Dummy function declarations */
int tcf_exts_validate_ex(struct net *net, struct tcf_proto *tp, struct nlattr **tb,
                        struct nlattr *est, void *exts, u32 flags, u32 fl_flags,
                        struct netlink_ext_ack *extack);
u32 nla_get_u32(struct nlattr *attr);
void NL_SET_ERR_MSG_MOD(struct netlink_ext_ack *extack, const char *msg);
struct tc_u_hnode *u32_lookup_ht(void *data, u32 handle);
struct tc_u_hnode *rtnl_dereference(void *ptr);
void rcu_assign_pointer(void *ptr, void *val);
void tcf_bind_filter(struct tcf_proto *tp, void *res, unsigned long base);
int tcf_change_indev(struct net *net, struct nlattr *attr, struct netlink_ext_ack *extack);