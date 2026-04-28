#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define TPACKET_ALIGNMENT 16
#define TPACKET_HDRLEN 32
#define TPACKET2_HDRLEN 48
#define TPACKET3_HDRLEN 64
#define PAGE_SIZE 4096
#define PAGE_ALIGNED(addr) (!((addr) & (PAGE_SIZE - 1)))
#define GFP_KERNEL 0
#define __GFP_NOWARN 0
#define __GFP_ZERO 0
#define EBUSY 16
#define EINVAL 22
#define ENOMEM 12
#define BLK_PLUS_PRIV(size) (size)
#define WRITE_ONCE(var, val) (var = val)
#define unlikely(x) (x)

typedef uint16_t __be16;
typedef uint64_t u64;

enum tpacket_versions {
    TPACKET_V1,
    TPACKET_V2,
    TPACKET_V3
};

struct tpacket_req {
    unsigned int tp_block_size;
    unsigned int tp_block_nr;
    unsigned int tp_frame_size;
    unsigned int tp_frame_nr;
};

struct tpacket_req3 {
    unsigned int tp_block_size;
    unsigned int tp_block_nr;
    unsigned int tp_frame_size;
    unsigned int tp_frame_nr;
    unsigned int tp_retire_blk_tov;
    unsigned int tp_sizeof_priv;
    unsigned int tp_feature_req_word;
};

union tpacket_req_u {
    struct tpacket_req req;
    struct tpacket_req3 req3;
};

struct pgv {
    char *buffer;
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
    unsigned long *rx_owner_map;
};

struct sk_buff_head {
    int lock;
};

struct packet_sock {
    struct packet_ring_buffer rx_ring;
    struct packet_ring_buffer tx_ring;
    int mapped;
    int running;
    __be16 num;
    int tp_version;
    unsigned int tp_hdrlen;
    unsigned int tp_reserve;
    int pg_vec_lock;
    int bind_lock;
    struct {
        void (*func)(void *sk);
    } prot_hook;
};

struct sock {
    struct sk_buff_head sk_write_queue;
    struct sk_buff_head sk_receive_queue;
};

static inline struct packet_sock *pkt_sk(struct sock *sk) { return (struct packet_sock *)sk; }
static inline int packet_read_pending(struct packet_ring_buffer *rb) { return 0; }
static inline void init_prb_bdqc(struct packet_sock *po, struct packet_ring_buffer *rb, struct pgv *pg_vec, union tpacket_req_u *req_u) {}
static inline void __unregister_prot_hook(struct sock *sk, bool sync) {}
static inline void register_prot_hook(struct sock *sk) {}
static inline void prb_shutdown_retire_blk_timer(struct packet_sock *po, struct sk_buff_head *rb_queue) {}
static inline struct pgv *alloc_pg_vec(struct tpacket_req *req, int order) { return NULL; }
static inline void free_pg_vec(struct pgv *pg_vec, int order, int tp_block_nr) {}
static inline unsigned long *bitmap_alloc(int nbits, int flags) { return NULL; }
static inline void bitmap_free(unsigned long *bitmap) {}
static inline int atomic_read(int *v) { return *v; }
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void mutex_lock(int *lock) {}
static inline void mutex_unlock(int *lock) {}
static inline void spin_lock_bh(int *lock) {}
static inline void spin_unlock_bh(int *lock) {}
static inline void synchronize_net(void) {}
static inline void skb_queue_purge(struct sk_buff_head *list) {}
static inline int get_order(unsigned long size) { return 0; }
static inline void swap(void *a, void *b) { void *tmp = *(void**)a; *(void**)a = *(void**)b; *(void**)b = tmp; }
static inline void pr_err(const char *fmt, ...) {}
static inline void tpacket_rcv(void *sk) {}
static inline void packet_rcv(void *sk) {}