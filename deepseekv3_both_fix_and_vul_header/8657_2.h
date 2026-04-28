#include <stdint.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdbool.h>

#define TPACKET_V1 0
#define TPACKET_V2 1
#define TPACKET_V3 2
#define TPACKET_HDRLEN 0
#define TPACKET2_HDRLEN 0
#define TPACKET3_HDRLEN 0
#define TPACKET_ALIGNMENT 0
#define PAGE_ALIGNED(x) 0
#define PAGE_SIZE 4096
#define BLK_PLUS_PRIV(x) 0
#define EINVAL 22
#define EBUSY 16
#define ENOMEM 12

typedef uint16_t __be16;

struct sk_buff_head {
    int lock;
};

struct pgv {
    void *data;
};

struct packet_ring_buffer {
    struct pgv *pg_vec;
    unsigned int pg_vec_order;
    unsigned int pg_vec_len;
    unsigned int pg_vec_pages;
    unsigned int frame_max;
    unsigned int head;
    unsigned int frame_size;
    unsigned int frames_per_block;
};

struct packet_sock {
    int tp_version;
    unsigned int tp_hdrlen;
    unsigned int tp_reserve;
    struct packet_ring_buffer rx_ring;
    struct packet_ring_buffer tx_ring;
    atomic_int mapped;
    int running;
    __be16 num;
    int bind_lock;
    int pg_vec_lock;
    struct {
        void (*func)(void *, void *);
    } prot_hook;
};

struct sock {
    struct sk_buff_head sk_write_queue;
    struct sk_buff_head sk_receive_queue;
};

struct tpacket_req {
    unsigned int tp_block_nr;
    unsigned int tp_block_size;
    unsigned int tp_frame_size;
    unsigned int tp_frame_nr;
};

struct tpacket_req3 {
    unsigned int tp_sizeof_priv;
};

union tpacket_req_u {
    struct tpacket_req req;
    struct tpacket_req3 req3;
};

static inline struct packet_sock *pkt_sk(struct sock *sk) { return (struct packet_sock *)sk; }
static inline int packet_read_pending(struct packet_ring_buffer *rb) { return 0; }
static inline void init_prb_bdqc(struct packet_sock *po, struct packet_ring_buffer *rb, struct pgv *pg_vec, union tpacket_req_u *req_u) {}
static inline void __unregister_prot_hook(struct sock *sk, bool flag) {}
static inline void register_prot_hook(struct sock *sk) {}
static inline void prb_shutdown_retire_blk_timer(struct packet_sock *po, struct sk_buff_head *rb_queue) {}
static inline struct pgv *alloc_pg_vec(struct tpacket_req *req, int order) { return NULL; }
static inline void free_pg_vec(struct pgv *pg_vec, int order, int tp_block_nr) {}
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void spin_lock_bh(int *lock) {}
static inline void spin_unlock_bh(int *lock) {}
static inline void mutex_lock(int *lock) {}
static inline void mutex_unlock(int *lock) {}
static inline void synchronize_net(void) {}
static inline void skb_queue_purge(struct sk_buff_head *queue) {}
static inline int get_order(unsigned int size) { return 0; }
static inline void swap(void **a, void **b) { void *tmp = *a; *a = *b; *b = tmp; }
static inline void pr_err(const char *fmt, ...) {}
static inline int atomic_read(atomic_int *v) { return *v; }
static inline int unlikely(int x) { return x; }
static inline void net_warn_ratelimited(const char *fmt, ...) {}
static inline void tpacket_rcv(void *sk, void *skb) {}
static inline void packet_rcv(void *sk, void *skb) {}