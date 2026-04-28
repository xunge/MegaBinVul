#include <sys/socket.h>
#include <time.h>

typedef int sctp_event_timeout_t;

struct sock {
    int sk_err;
};

struct sctp_association {
    struct {
        struct sock *sk;
        int dead;
    } base;
    void *timers;
    int state;
    void *ep;
};

struct net;

#define HZ 100
#define GFP_ATOMIC 0
#define pr_debug(fmt, ...) 
#define SCTP_EVENT_T_TIMEOUT 0
#define SCTP_ST_TIMEOUT(x) (x)

unsigned long jiffies = 0;

static inline void bh_lock_sock(struct sock *sk) {}
static inline void bh_unlock_sock(struct sock *sk) {}
static inline int sock_owned_by_user(struct sock *sk) { return 0; }
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline int mod_timer(void *timer, unsigned long expires) { return 0; }
static inline void sctp_association_hold(struct sctp_association *asoc) {}
static inline void sctp_association_put(struct sctp_association *asoc) {}
static inline int sctp_do_sm(struct net *net, int event_type, int state, int assoc_state, void *ep, struct sctp_association *asoc, void *arg, int gfp) { return 0; }