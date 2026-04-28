#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint16_t u16;
typedef uint8_t u8;

#define PACKET_FANOUT_HASH 0
#define PACKET_FANOUT_LB 1
#define PACKET_FANOUT_CPU 2
#define PACKET_FANOUT_RND 3
#define PACKET_FANOUT_QM 4
#define PACKET_FANOUT_CBPF 5
#define PACKET_FANOUT_EBPF 6
#define PACKET_FANOUT_ROLLOVER 7

#define PACKET_FANOUT_FLAG_ROLLOVER 0x1000
#define PACKET_FANOUT_MAX 256

#define GFP_KERNEL 0
#define EINVAL 22
#define EALREADY 114
#define ENOMEM 12
#define ENOSPC 28

struct sock;
struct net;
struct sk_buff;
struct net_device;

struct packet_rollover {
    long num;
    long num_huge;
    long num_failed;
};

struct packet_type {
    int type;
    struct net_device *dev;
    void (*func)(struct sk_buff *, struct net_device *,
                struct packet_type *, struct net_device *);
    void *af_packet_priv;
    int (*id_match)(struct sk_buff *, struct sock *);
};

struct packet_sock {
    int running;
    struct packet_fanout *fanout;
    struct packet_rollover *rollover;
    struct packet_type prot_hook;
};

struct list_head {
    struct list_head *next, *prev;
};

struct packet_fanout {
    struct net *net;
    u16 id;
    u8 type;
    u8 flags;
    struct list_head list;
    int lock;
    int sk_ref;
    struct packet_type prot_hook;
};

static struct list_head fanout_list = { &fanout_list, &fanout_list };
static int fanout_mutex;

static inline struct packet_sock *pkt_sk(struct sock *sk) { return (struct packet_sock *)sk; }
static inline struct net *sock_net(struct sock *sk) { return (struct net *)0; }
static inline int read_pnet(struct net **net) { return 0; }
static inline void write_pnet(struct net **net, struct net *val) { *net = val; }
static inline void fanout_init_data(struct packet_fanout *f) {}
static inline void __fanout_link(struct sock *sk, struct packet_sock *po) {}
static inline void dev_add_pack(struct packet_type *pt) {}
static inline void __dev_remove_pack(struct packet_type *pt) {}
static inline int match_fanout_group(struct sk_buff *skb, struct sock *sk) { return 0; }
static inline void packet_rcv_fanout(struct sk_buff *skb, struct net_device *dev,
                                   struct packet_type *pt, struct net_device *orig_dev) {}

static inline void mutex_lock(int *lock) {}
static inline void mutex_unlock(int *lock) {}
static inline void INIT_LIST_HEAD(struct list_head *list) { list->next = list->prev = list; }
static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}
static inline void spin_lock_init(int *lock) {}
static inline void atomic_set(int *v, int i) { *v = i; }
static inline int atomic_read(int *v) { return *v; }
static inline void atomic_inc(int *v) { (*v)++; }
static inline void atomic_long_set(long *v, long i) { *v = i; }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }

#define list_for_each_entry(f, head, member) \
    for (f = (struct packet_fanout *)((char *)((head)->next) - offsetof(struct packet_fanout, member)); \
         &f->member != (head); \
         f = (struct packet_fanout *)((char *)(f->member.next) - offsetof(struct packet_fanout, member)))