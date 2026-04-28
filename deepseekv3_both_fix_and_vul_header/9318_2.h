#include <stdio.h>
#include <sys/types.h>
#include <time.h>

#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)

struct sock {
    int sk_err;
};

struct sctp_transport {
    struct {
        unsigned long expires;
    } T3_rtx_timer;
    struct sctp_association *asoc;
    int dead;
};

struct sctp_association {
    struct {
        struct sock *sk;
    } base;
    struct sctp_endpoint *ep;
    int state;
};

struct net;
struct sctp_endpoint;

#define HZ 100
#define GFP_ATOMIC 0
#define SCTP_EVENT_T_TIMEOUT 0
#define SCTP_EVENT_TIMEOUT_T3_RTX 0
#define SCTP_ST_TIMEOUT(x) (x)

extern unsigned long jiffies;
extern struct net *sock_net(struct sock *sk);
extern void bh_lock_sock(struct sock *sk);
extern void bh_unlock_sock(struct sock *sk);
extern int sock_owned_by_user(const struct sock *sk);
extern int mod_timer(void *timer, unsigned long expires);
extern void sctp_transport_hold(struct sctp_transport *transport);
extern void sctp_transport_put(struct sctp_transport *transport);
extern int sctp_do_sm(struct net *net, int event_type, int state, int asoc_state,
                     struct sctp_endpoint *ep, struct sctp_association *asoc,
                     struct sctp_transport *transport, int gfp);