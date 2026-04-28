#include <stdatomic.h>
#include <stdint.h>
#include <stddef.h>

#define NET_RX_SUCCESS 0
#define _RET_IP_ __builtin_return_address(0)

struct sock {
    struct {
        struct {
            int dep_map;
        } sk_lock;
        atomic_int sk_drops;
    };
};

struct sk_buff {
    void* dev;
};

void bh_lock_sock(struct sock* sk);
void bh_lock_sock_nested(struct sock* sk);
void bh_unlock_sock(struct sock* sk);
int sk_filter(struct sock* sk, struct sk_buff* skb);
int sk_backlog_rcv(struct sock* sk, struct sk_buff* skb);
int sk_add_backlog_limited(struct sock* sk, struct sk_buff* skb);
int sock_owned_by_user(struct sock* sk);
void sock_put(struct sock* sk);
void kfree_skb(struct sk_buff* skb);
void mutex_acquire(void* lock, int a, int b, void* ip);
void mutex_release(void* lock, int a, void* ip);