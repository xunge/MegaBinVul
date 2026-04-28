#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define PACKET_FANOUT_HASH 0
#define PACKET_FANOUT_LB 1
#define PACKET_FANOUT_CPU 2
#define PACKET_FANOUT_RND 3
#define PACKET_FANOUT_QM 4
#define PACKET_FANOUT_ROLLOVER 5
#define PACKET_FANOUT_CBPF 6
#define PACKET_FANOUT_EBPF 7
#define PACKET_FANOUT_FLAG_ROLLOVER 0x1000
#define PACKET_FANOUT_FLAG_UNIQUEID 0x2000
#define PACKET_FANOUT_MAX 256
#define GFP_KERNEL 0

#define EINVAL 22
#define EALREADY 114
#define ENOMEM 12
#define ENOSPC 28

typedef uint16_t u16;
typedef uint8_t u8;

struct sock;
struct net;

struct packet_rollover {
    _Atomic long num;
    _Atomic long num_huge;
    _Atomic long num_failed;
};

struct list_head {
    struct list_head *next, *prev;
};

struct packet_hook {
    int type;
    void *dev;
    void (*func)(void);
    void *af_packet_priv;
    bool (*id_match)(void);
};

struct packet_fanout {
    struct net *net;
    u16 id;
    u8 type;
    u8 flags;
    struct list_head list;
    void *lock;
    _Atomic int sk_ref;
    struct packet_hook prot_hook;
};

struct packet_sock {
    struct packet_fanout *fanout;
    struct packet_rollover *rollover;
    struct packet_hook prot_hook;
    void *bind_lock;
    int running;
};

extern struct {
    int (*lock)(void*);
    int (*unlock)(void*);
} fanout_mutex;

extern struct list_head fanout_list;

static void packet_rcv_fanout(void) {}
static bool match_fanout_group(void) { return false; }

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)))

static inline struct packet_sock *pkt_sk(struct sock *sk) { return (struct packet_sock *)sk; }
static inline bool fanout_find_new_id(struct sock *sk, u16 *id) { return false; }
static inline void fanout_init_data(struct packet_fanout *f) {}
static inline void __fanout_link(struct sock *sk, struct packet_sock *po) {}
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline void write_pnet(struct net **net, struct net *val) { *net = val; }
static inline struct net *read_pnet(const struct net * const *net) { return *net; }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void INIT_LIST_HEAD(struct list_head *list) { list->next = list->prev = list; }
static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}
static inline void list_del(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}
static inline void spin_lock_init(void *lock) {}
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void refcount_set(_Atomic int *r, int value) { atomic_store(r, value); }
static inline int refcount_read(_Atomic int *r) { return atomic_load(r); }
static inline void atomic_long_set(_Atomic long *v, long i) { atomic_store(v, i); }
static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}
static inline void __dev_remove_pack(struct packet_hook *hook) {}