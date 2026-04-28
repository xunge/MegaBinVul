#include <stdatomic.h>
#include <stddef.h>

#define SCTP_SOCKET_UDP 1
#define SCTP_SOCKET_TCP 2
#define SPP_HB_ENABLE 1
#define SPP_PMTUD_ENABLE 2
#define SPP_SACKDELAY_ENABLE 4
#define SCTP_SS_DEFAULT 0
#define SKB_GSO_SCTP 1
#define GFP_KERNEL 0
#define ENOMEM 1
#define ESOCKTNOSUPPORT 2
#define SOCK_SEQPACKET 1
#define SOCK_STREAM 2

struct sock {
    int sk_type;
    unsigned int sk_gso_type;
    int sk_family;
    void (*sk_destruct)(struct sock *);
    void *sk_prot;
};

struct list_head {
    struct list_head *next, *prev;
};

struct net_sctp {
    unsigned int max_burst;
    unsigned int sctp_hmac_alg;
    unsigned int max_retrans_init;
    unsigned int rto_max;
    unsigned int rto_initial;
    unsigned int rto_min;
    unsigned int max_retrans_association;
    unsigned int valid_cookie_life;
    unsigned int hb_interval;
    unsigned int udp_port;
    unsigned int encap_port;
    unsigned int max_retrans_path;
    unsigned int pf_retrans;
    unsigned int ps_retrans;
    unsigned int pf_expose;
    unsigned int sack_timeout;
    unsigned int default_auto_asconf;
    struct list_head auto_asconf_splist;
    void *addr_wq_lock;
};

struct net {
    struct net_sctp sctp;
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
    unsigned int sctp_hmac_alg;
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
    unsigned int subscribe;
    unsigned int hbinterval;
    unsigned short udp_port;
    unsigned short encap_port;
    unsigned int pathmaxrxt;
    unsigned int pf_retrans;
    unsigned int ps_retrans;
    unsigned int pf_expose;
    unsigned int pathmtu;
    unsigned int sackdelay;
    unsigned int sackfreq;
    unsigned int param_flags;
    unsigned int default_ss;
    unsigned int disable_fragments;
    unsigned int nodelay;
    unsigned int recvrcvinfo;
    unsigned int recvnxtinfo;
    unsigned int v4mapped;
    unsigned int autoclose;
    unsigned int user_frag;
    unsigned int adaptation_ind;
    void *pf;
    atomic_int pd_mode;
    void *pd_lobby;
    unsigned int frag_interleave;
    void *ep;
    void *hmac;
    struct list_head auto_asconf_list;
    unsigned int do_auto_asconf;
};

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline struct sctp_sock *sctp_sk(struct sock *sk) { return NULL; }
static inline void *sctp_endpoint_new(struct sock *sk, int flags) { return NULL; }
static inline void sctp_destruct_sock(struct sock *sk) {}
static inline void *sctp_get_pf_specific(int family) { return NULL; }
static inline void skb_queue_head_init(void *list) {}
static inline void local_bh_disable(void) {}
static inline void local_bh_enable(void) {}
static inline void sk_sockets_allocated_inc(struct sock *sk) {}
static inline void sock_prot_inuse_add(struct net *net, void *prot, int val) {}
static inline unsigned short htons(unsigned short val) { return val; }
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}
#define pr_debug(fmt, ...)
#define SCTP_DBG_OBJCNT_INC(name)
#define atomic_set(ptr, val) (*(ptr) = (val))

extern unsigned int sctp_max_outstreams;
extern unsigned int sctp_max_instreams;