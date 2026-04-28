struct sock;
struct udp_sock {
    int len;
    int pending;
};
struct flowi4;
struct sk_buff;

struct inet_sock {
    struct {
        struct {
            union {
                struct flowi4 *ip4;
            } u;
        } fl;
    } cork;
};

static inline struct udp_sock *udp_sk(const struct sock *sk) { return (struct udp_sock *)sk; }
static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static struct sk_buff *ip_finish_skb(struct sock *sk, struct flowi4 *fl4) { return 0; }
static int udp_send_skb(struct sk_buff *skb, struct flowi4 *fl4) { return 0; }