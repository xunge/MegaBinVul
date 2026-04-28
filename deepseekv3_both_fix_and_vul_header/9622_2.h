#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct sock {
    int sk_state;
};

struct class;
struct class_attribute;
struct sco_sk_list {
    struct hlist_node head;
    int lock;
};

#define PAGE_SIZE 4096

char *batostr(void *addr);
struct bt_sock {
    void *src;
    void *dst;
};

#define bt_sk(sk) ((struct bt_sock *)sk)
#define read_lock_bh(lock) 
#define read_unlock_bh(lock) 
#define sk_for_each(sk, node, head) for (sk = NULL, node = NULL; 0; )