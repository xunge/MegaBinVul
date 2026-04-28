#include <stddef.h>

#define __must_check
#define max(a, b) ((a) > (b) ? (a) : (b))
#define ENOBUFS 105

struct sock {
    struct {
        size_t len;
        size_t limit;
    } sk_backlog;
    size_t sk_rcvbuf;
};

struct sk_buff {
    size_t truesize;
};

void __sk_add_backlog(struct sock *sk, struct sk_buff *skb);