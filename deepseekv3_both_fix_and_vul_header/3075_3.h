#include <sys/types.h>
#include <sys/socket.h>

struct sock;
struct udp_sock {
    int len;
    int pending;
};
struct inet_sock {
    struct {
        struct {
            union {
                struct {
                    int dummy;
                } ip4;
            } u;
        } fl;
    } cork;
};
struct flowi4 {
    int dummy;
};
struct sk_buff;

static inline struct udp_sock *udp_sk(const struct sock *sk) { return (struct udp_sock *)sk; }
static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static struct sk_buff *ip_finish_skb(struct sock *sk, struct flowi4 *fl4) { return 0; }
static int udp_send_skb(struct sk_buff *skb, struct flowi4 *fl4) { return 0; }