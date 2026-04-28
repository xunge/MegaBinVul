#include <stdatomic.h>
#include <stddef.h>

struct sk_buff {
    int peeked;
    int len;
    atomic_int users;
    struct sk_buff *next;
};

struct sk_buff_head {
    int lock;
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sock {
    int sk_err;
    struct sk_buff_head sk_receive_queue;
};

#define MSG_DONTWAIT 0x40
#define MSG_PEEK 0x02
#define EAGAIN 11

int sock_error(struct sock *sk);
long sock_rcvtimeo(struct sock *sk, int flags);
void spin_lock_irqsave(int *lock, unsigned long flags);
void spin_unlock_irqrestore(int *lock, unsigned long flags);
void __skb_unlink(struct sk_buff *skb, struct sk_buff_head *queue);
int wait_for_packet(struct sock *sk, int *err, long *timeo);

#define skb_queue_walk(queue, skb) \
    for (skb = (queue)->next; skb != (struct sk_buff *)(queue); skb = skb->next)