#include <stdint.h>

typedef uint32_t u32;

struct tcf_result {
    u32 classid;
};

struct tcf_exts {
    int dummy;
};

struct fw_head {
    u32 mask;
};

struct fw_filter {
    struct tcf_result res;
    struct tcf_exts exts;
    int ifindex;
};

struct tcf_proto {
    struct fw_head *root;
};

struct net;
struct netlink_ext_ack;
struct nlattr;

#define TCA_RATE 1
#define TCA_FW_CLASSID 2
#define TCA_FW_INDEV 3
#define TCA_FW_MASK 4
#define EINVAL 22

static inline struct fw_head *rtnl_dereference(struct fw_head *p) { return p; }
static inline u32 nla_get_u32(struct nlattr *attr) { return 0; }
static inline int tcf_exts_validate(struct net *net, struct tcf_proto *tp, 
                                  struct nlattr **tb, struct nlattr *rate,
                                  struct tcf_exts *exts, u32 flags,
                                  struct netlink_ext_ack *extack) { return 0; }
static inline void tcf_bind_filter(struct tcf_proto *tp, struct tcf_result *r,
                                 unsigned long base) {}
static inline int tcf_change_indev(struct net *net, struct nlattr *indev_attr,
                                 struct netlink_ext_ack *extack) { return 0; }