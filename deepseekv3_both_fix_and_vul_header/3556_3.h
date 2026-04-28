#include <stdbool.h>
#include <stddef.h>

struct mutex {};
struct hlist_head {};
struct nlmsghdr {
    int nlmsg_seq;
};

struct sk_buff {
    struct sock *sk;
    unsigned int len;
};

struct netlink_callback {
    struct nlmsghdr *nlh;
    struct sk_buff *skb;
    int args[1];
};

struct packet_diag_req;

struct net {
    struct {
        struct mutex sklist_lock;
        struct hlist_head sklist;
    } packet;
    void *user_ns;
};

struct sock;

#define CAP_NET_ADMIN 0
#define NLM_F_MULTI 0

static inline bool netlink_net_capable(struct sk_buff *skb, int cap) { return false; }
static inline bool ns_capable(void *ns, int cap) { return false; }
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline void *nlmsg_data(void *nlh) { return NULL; }
static inline bool net_eq(struct net *net1, struct net *net2) { return false; }
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline int sk_diag_fill(struct sock *sk, struct sk_buff *skb, struct packet_diag_req *req,
                              bool may_report_filterinfo, void *user_ns, int portid, 
                              int seq, int flags, int ino) { return 0; }
static inline void *sk_user_ns(struct sock *sk) { return NULL; }
static inline int sock_i_ino(struct sock *sk) { return 0; }

#define sk_for_each(sk, list) for ((sk) = NULL; (sk) != NULL; (sk) = NULL)
#define NETLINK_CB(skb) ((struct { struct sock *sk; int portid; }){0})