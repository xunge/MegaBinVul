#include <string.h>

struct sk_buff;
struct sock;

struct x25_facilities {
    int reverse;
    int throughput;
    int pacsize_in;
    int pacsize_out;
    int winsize_in;
    int winsize_out;
};

struct x25_dte_facilities {
    char dummy;  // placeholder since actual members are unknown
};

struct x25_sock {
    struct x25_facilities facilities;
    int vc_facil_mask;
};

#define SOCK_DEBUG(sk, msg)

static inline struct x25_sock *x25_sk(struct sock *sk) { return (struct x25_sock *)sk; }

int x25_parse_facilities(struct sk_buff *skb, struct x25_facilities *facilities,
                        struct x25_dte_facilities *dte, int *vc_facil_mask);