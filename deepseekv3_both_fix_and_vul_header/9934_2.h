#include <stddef.h>

struct sock {
    struct {
        struct sk_buff *head;
        struct sk_buff *tail;
        int len;
    } sk_backlog;
};

struct sk_buff {
    struct sk_buff *next;
};

void bh_unlock_sock(struct sock *sk);
void bh_lock_sock(struct sock *sk);
int sk_backlog_rcv(struct sock *sk, struct sk_buff *skb);
void cond_resched_softirq(void);