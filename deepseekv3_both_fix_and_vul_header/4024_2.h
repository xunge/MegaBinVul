#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct bpf_map {
    u32 key_size;
};

struct bpf_shtab {
    struct bpf_map map;
};

struct bpf_shtab_bucket {
    struct hlist_head head;
    int lock;
};

struct bpf_shtab_elem {
    struct hlist_node node;
    void *sk;
};

struct sock;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define raw_spin_lock_bh(lock) (void)(lock)
#define raw_spin_unlock_bh(lock) (void)(lock)
#define hlist_del_rcu(node) (void)(node)

#define ENOENT 2

static u32 sock_hash_bucket_hash(void *key, u32 key_size) { return 0; }
static struct bpf_shtab_bucket *sock_hash_select_bucket(struct bpf_shtab *htab, u32 hash) { return NULL; }
static struct bpf_shtab_elem *sock_hash_lookup_elem_raw(struct hlist_head *head, u32 hash, void *key, u32 key_size) { return NULL; }
static void sock_map_unref(struct sock *sk, struct bpf_shtab_elem *elem) {}
static void sock_hash_free_elem(struct bpf_shtab *htab, struct bpf_shtab_elem *elem) {}