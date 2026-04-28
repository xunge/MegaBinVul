#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

struct class;
struct class_attribute;

struct sock {
    int sk_state;
};

struct hlist_node {
    struct hlist_node *next;
};

struct bt_sk {
    char src[6];
    char dst[6];
};

struct l2cap_pinfo {
    unsigned short psm;
    unsigned short scid;
    unsigned short dcid;
    int imtu;
    int omtu;
    int sec_level;
};

struct l2cap_sk_list {
    int lock;
    struct hlist_node head;
} l2cap_sk_list;

typedef ssize_t ssize_t;

#define PAGE_SIZE 4096
#define __le16_to_cpu(x) (x)

static inline void read_lock_bh(int *lock) {}
static inline void read_unlock_bh(int *lock) {}
#define sk_for_each(sk, node, list) for (sk = NULL, node = NULL; 0; )

struct l2cap_pinfo *l2cap_pi(struct sock *sk);
struct bt_sk *bt_sk(struct sock *sk);
char *batostr(const char *addr);