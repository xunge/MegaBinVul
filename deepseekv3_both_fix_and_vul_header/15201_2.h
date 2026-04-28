#include <stddef.h>

struct neigh_table {
    int family;
    char *id;
    void *lock;
};

struct neigh_parms;
struct sk_buff;
struct netlink_callback;

struct nlmsghdr {
    unsigned int nlmsg_len;
    unsigned short nlmsg_type;
    unsigned short nlmsg_flags;
    unsigned int nlmsg_seq;
    unsigned int nlmsg_pid;
};

struct ndtmsg {
    unsigned char ndtm_family;
    unsigned char ndtm_pad1;
    unsigned short ndtm_pad2;
};

#define RTM_NEWNEIGHTBL 0
#define NLM_F_MULTI 0
#define NDTA_NAME 0

#define NLMSG_NEW_ANSWER(skb, cb, type, len, flags) ((struct nlmsghdr *)0)
#define NLMSG_DATA(nlh) ((void*)(((char*)nlh) + sizeof(struct nlmsghdr)))
#define NLMSG_END(skb, nlh) 0
#define NLMSG_CANCEL(skb, nlh) -1
#define RTA_PUT_STRING(skb, attrtype, attrdata) -1

static inline void read_lock_bh(void *lock) {}
static inline void read_unlock_bh(void *lock) {}
static inline int neightbl_fill_parms(struct sk_buff *skb, struct neigh_parms *parms) { return 0; }