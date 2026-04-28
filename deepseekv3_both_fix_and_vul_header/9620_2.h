#include <stddef.h>
#include <stdio.h>
#include <string.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct sock {
    int sk_state;
};

struct bt_sock {
    char src[6];
    char dst[6];
};

struct rfcomm_pinfo {
    int channel;
};

struct class;
struct class_attribute;

extern struct rfcomm_sk_list {
    struct hlist_head head;
    int lock;
} rfcomm_sk_list;

#define PAGE_SIZE 4096
#define sk_for_each(__sk, __node, __list) \
    for (__sk = NULL, __node = NULL; __sk != NULL; __sk = NULL)

static inline struct bt_sock *bt_sk(const struct sock *sk) {
    return (struct bt_sock *)sk;
}

static inline struct rfcomm_pinfo *rfcomm_pi(const struct sock *sk) {
    return (struct rfcomm_pinfo *)sk;
}

static inline void read_lock_bh(int *lock) {}
static inline void read_unlock_bh(int *lock) {}

char *batostr(const void *addr) {
    static char str[18];
    return str;
}