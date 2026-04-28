#include <stdatomic.h>
#include <string.h>

#define SCTP_DEBUG_PRINTK(fmt, ...)
#define SCTP_DBG_OBJCNT_INC(obj)
#define SCTP_STATIC static
#define GFP_KERNEL 0

struct sock {
    int sk_type;
    int sk_family;
    struct {
        int limit;
    } sk_backlog;
    void *sk_prot;
};

struct sctp_endpoint;

struct sctp_event_subscribe {
    unsigned int sctp_data_io_event;
    unsigned int sctp_association_event;
    unsigned int sctp_address_event;
    unsigned int sctp_send_failure_event;
    unsigned int sctp_peer_error_event;
    unsigned int sctp_shutdown_event;
    unsigned int sctp_partial_delivery_event;
    unsigned int sctp_adaptation_layer_event;
};

struct sctp_sock {
    int type;
    unsigned int default_stream;
    unsigned int default_ppid;
    unsigned int default_flags;
    unsigned int default_context;
    unsigned int default_timetolive;
    unsigned int default_rcv_context;
    unsigned int max_burst;
    struct {
        unsigned int sinit_num_ostreams;
        unsigned int sinit_max_instreams;
        unsigned int sinit_max_attempts;
        unsigned int sinit_max_init_timeo;
    } initmsg;
    struct {
        unsigned int srto_initial;
        unsigned int srto_max;
        unsigned int srto_min;
    } rtoinfo;
    struct {
        unsigned int sasoc_asocmaxrxt;
        unsigned int sasoc_number_peer_destinations;
        unsigned int sasoc_peer_rwnd;
        unsigned int sasoc_local_rwnd;
        unsigned int sasoc_cookie_life;
    } assocparams;
    struct sctp_event_subscribe subscribe;
    unsigned int hbinterval;
    unsigned int pathmaxrxt;
    unsigned int pathmtu;
    unsigned int sackdelay;
    unsigned int sackfreq;
    unsigned int param_flags;
    unsigned int disable_fragments;
    unsigned int nodelay;
    unsigned int v4mapped;
    unsigned int autoclose;
    unsigned int user_frag;
    unsigned int adaptation_ind;
    void *pf;
    atomic_int pd_mode;
    struct {
        void *next;
        void *prev;
    } pd_lobby;
    unsigned int frag_interleave;
    struct sctp_endpoint *ep;
    void *hmac;
};

#define SOCK_SEQPACKET 1
#define SOCK_STREAM 2
#define SCTP_SOCKET_UDP 0
#define SCTP_SOCKET_TCP 1

#define ESOCKTNOSUPPORT (-1)
#define ENOMEM (-2)

#define SPP_HB_ENABLE (1 << 0)
#define SPP_PMTUD_ENABLE (1 << 1)
#define SPP_SACKDELAY_ENABLE (1 << 2)

extern int sctp_max_burst;
extern int sctp_max_outstreams;
extern int sctp_max_instreams;
extern int sctp_max_retrans_init;
extern int sctp_rto_max;
extern int sctp_rto_initial;
extern int sctp_rto_min;
extern int sctp_max_retrans_association;
extern int sctp_valid_cookie_life;
extern int sctp_hb_interval;
extern int sctp_max_retrans_path;
extern int sctp_sack_timeout;
extern int sysctl_sctp_rmem[3];
extern atomic_int sctp_sockets_allocated;

static inline struct sctp_sock *sctp_sk(const struct sock *sk) { return (struct sctp_sock *)sk; }
static inline void *sctp_endpoint_new(struct sock *sk, int flags) { return NULL; }
static inline void *sctp_get_pf_specific(int family) { return NULL; }
static inline void sock_prot_inuse_add(void *net, void *prot, int val) {}
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline void local_bh_disable(void) {}
static inline void local_bh_enable(void) {}
static inline void skb_queue_head_init(void *list) {}
static inline void percpu_counter_inc(atomic_int *fbc) { atomic_fetch_add(fbc, 1); }
static inline void atomic_set(atomic_int *v, int i) { atomic_store(v, i); }