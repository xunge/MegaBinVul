#include <stdatomic.h>
#include <string.h>

typedef struct {
    int lock;
} spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff_head {
    struct list_head head;
};

struct sctp_event_subscribe {
    unsigned int sctp_data_io_event:1;
    unsigned int sctp_association_event:1;
    unsigned int sctp_address_event:1;
    unsigned int sctp_send_failure_event:1;
    unsigned int sctp_peer_error_event:1;
    unsigned int sctp_shutdown_event:1;
    unsigned int sctp_partial_delivery_event:1;
    unsigned int sctp_adaptation_layer_event:1;
};

struct sock {
    int sk_type;
    int sk_family;
    void *sk_prot;
    void (*sk_destruct)(struct sock *);
};

struct sctp_net {
    int max_burst;
    int sctp_hmac_alg;
    int max_retrans_init;
    int rto_max;
    int rto_initial;
    int rto_min;
    int max_retrans_association;
    int valid_cookie_life;
    int hb_interval;
    int max_retrans_path;
    int sack_timeout;
    int default_auto_asconf;
    struct list_head auto_asconf_splist;
    spinlock_t addr_wq_lock;
};

struct net {
    struct sctp_net sctp;
};

struct sctp_sock {
    int type;
    int default_stream;
    int default_ppid;
    int default_flags;
    int default_context;
    int default_timetolive;
    int default_rcv_context;
    int max_burst;
    int sctp_hmac_alg;
    struct {
        int sinit_num_ostreams;
        int sinit_max_instreams;
        int sinit_max_attempts;
        int sinit_max_init_timeo;
    } initmsg;
    struct {
        int srto_initial;
        int srto_max;
        int srto_min;
    } rtoinfo;
    struct {
        int sasoc_asocmaxrxt;
        int sasoc_number_peer_destinations;
        int sasoc_peer_rwnd;
        int sasoc_local_rwnd;
        int sasoc_cookie_life;
    } assocparams;
    struct sctp_event_subscribe subscribe;
    int hbinterval;
    int pathmaxrxt;
    int pathmtu;
    int sackdelay;
    int sackfreq;
    int param_flags;
    int disable_fragments;
    int nodelay;
    int recvrcvinfo;
    int recvnxtinfo;
    int v4mapped;
    int autoclose;
    int user_frag;
    int adaptation_ind;
    void *pf;
    atomic_int pd_mode;
    struct sk_buff_head pd_lobby;
    int frag_interleave;
    void *ep;
    void *hmac;
    int do_auto_asconf;
    struct list_head auto_asconf_list;
};

#define SOCK_SEQPACKET 1
#define SOCK_STREAM 2
#define SCTP_SOCKET_UDP 1
#define SCTP_SOCKET_TCP 2
#define ESOCKTNOSUPPORT 1
#define ENOMEM 2
#define GFP_KERNEL 0
#define SPP_HB_ENABLE 1
#define SPP_PMTUD_ENABLE 2
#define SPP_SACKDELAY_ENABLE 4

#define pr_debug(fmt, ...)
#define SCTP_DBG_OBJCNT_INC(x)

static struct net *sock_net(struct sock *sk) { return NULL; }
static struct sctp_sock *sctp_sk(struct sock *sk) { return NULL; }
static void sctp_destruct_sock(struct sock *sk) {}
static void *sctp_endpoint_new(struct sock *sk, int flags) { return NULL; }
static void *sctp_get_pf_specific(int family) { return NULL; }
static void local_bh_disable() {}
static void local_bh_enable() {}
static void percpu_counter_inc(void *counter) {}
static void sock_prot_inuse_add(struct net *net, void *prot, int count) {}
static void spin_lock(spinlock_t *lock) { lock->lock = 1; }
static void spin_unlock(spinlock_t *lock) { lock->lock = 0; }
static void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}
static void skb_queue_head_init(struct sk_buff_head *list) {
    list->head.next = &list->head;
    list->head.prev = &list->head;
}
static void atomic_set(atomic_int *atomic, int value) {
    *atomic = value;
}

extern int sctp_max_outstreams;
extern int sctp_max_instreams;
extern atomic_int sctp_sockets_allocated;