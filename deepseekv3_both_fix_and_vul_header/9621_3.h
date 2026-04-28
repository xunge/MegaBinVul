#include <stddef.h>
#include <stdio.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct sock {
    void *sk;
};

struct socket {
    struct sock *sk;
};

struct bt_sk {
    unsigned char src[6];
    unsigned char dst[6];
};

struct rfcomm_session {
    struct list_head list;
    struct list_head dlcs;
    struct socket *sock;
};

struct rfcomm_dlc {
    struct list_head list;
    long state;
    int dlci;
    int mtu;
    int rx_credits;
    int tx_credits;
};

struct class;
struct class_attribute;

#define PAGE_SIZE 4096

extern struct list_head session_list;
extern void rfcomm_lock(void);
extern void rfcomm_unlock(void);
extern char *batostr(const unsigned char *addr);
extern struct bt_sk *bt_sk(struct sock *sk);