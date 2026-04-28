#include <stdatomic.h>
#include <stddef.h>

#define NET_RX_SUCCESS 0
#define _RET_IP_ (void *)0

struct sock {
    struct {
        struct {
            int dep_map;
        } sk_lock;
        int sk_drops;
    };
};

struct sk_buff {
    void* dev;
};

void bh_lock_sock_nested(struct sock* sk);
void bh_lock_sock(struct sock* sk);
void bh_unlock_sock(struct sock* sk);
int sock_owned_by_user(struct sock* sk);
int sk_filter(struct sock* sk, struct sk_buff* skb);
int sk_backlog_rcv(struct sock* sk, struct sk_buff* skb);
int sk_add_backlog(struct sock* sk, struct sk_buff* skb);
void sock_put(struct sock* sk);
void kfree_skb(struct sk_buff* skb);