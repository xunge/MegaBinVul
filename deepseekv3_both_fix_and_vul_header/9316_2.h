#include <sys/socket.h>
#include <time.h>

struct sock {
    int sk_err;
};

struct sctp_transport {
    void *hb_timer;
    struct sctp_association *asoc;
    int dead;
};

struct sctp_association {
    struct {
        struct sock *sk;
    } base;
    void *ep;
    int state;
};

struct net;

#define SCTP_EVENT_T_TIMEOUT 0
#define SCTP_EVENT_TIMEOUT_HEARTBEAT 0
#define SCTP_ST_TIMEOUT(x) (x)
#define GFP_ATOMIC 0
#define HZ 100
#define pr_debug(fmt, ...)

extern unsigned long jiffies;
extern int mod_timer(void *timer, unsigned long expires);
extern void sctp_transport_hold(struct sctp_transport *transport);
extern void sctp_transport_put(struct sctp_transport *transport);
extern struct net *sock_net(struct sock *sk);
extern void bh_lock_sock(struct sock *sk);
extern void bh_unlock_sock(struct sock *sk);
extern int sock_owned_by_user(const struct sock *sk);
extern int sctp_do_sm(struct net *net, int event_type, int timeout_type, int state, void *ep, struct sctp_association *asoc, struct sctp_transport *transport, int gfp);