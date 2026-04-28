#include <sys/types.h>
#include <time.h>

struct sock;
struct sctp_association {
    int state;
    void *ep;
};
struct sctp_transport {
    struct {
        unsigned long expires;
    } proto_unreach_timer;
};

#define SCTP_DEBUG_PRINTK(fmt, ...)
#define SCTP_EVENT_T_OTHER 0
#define SCTP_EVENT_ICMP_PROTO_UNREACH 0
#define SCTP_ST_OTHER(x) (x)
#define GFP_ATOMIC 0
#define HZ 100

int sock_owned_by_user(struct sock *sk);
int timer_pending(void *timer);
int mod_timer(void *timer, unsigned long expires);
void sctp_association_hold(struct sctp_association *asoc);
int del_timer(void *timer);
void sctp_association_put(struct sctp_association *asoc);
void sctp_do_sm(int event_type, int state, int asoc_state, void *ep,
                struct sctp_association *asoc, struct sctp_transport *t, int gfp);

extern unsigned long jiffies;