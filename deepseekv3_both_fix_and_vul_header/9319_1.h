#include <sys/types.h>
#include <stddef.h>

struct sctp_transport {
    struct sctp_association *asoc;
    void *proto_unreach_timer;
};

struct sctp_association {
    struct {
        void *sk;
        int dead;
    } base;
    void *state;
    void *ep;
};

struct net;

#define HZ 100
#define GFP_ATOMIC 0
#define SCTP_EVENT_T_OTHER 0
#define SCTP_EVENT_ICMP_PROTO_UNREACH 0
#define SCTP_ST_OTHER(x) (x)

extern unsigned long jiffies;
extern struct net init_net;

#define sock_net(sk) (&init_net)
#define pr_debug(fmt, ...) 
#define bh_lock_sock(sk) 
#define bh_unlock_sock(sk) 
#define sock_owned_by_user(sk) (0)
#define mod_timer(timer, expires) (0)
#define sctp_association_hold(asoc) 
#define sctp_association_put(asoc) 
#define sctp_do_sm(net, type, st, state, ep, asoc, transport, gfp)