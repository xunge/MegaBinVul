#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

struct socket {
    struct sock *sk;
};

struct sock {
    struct proto *sk_prot;
};

struct proto {
    ssize_t (*sendpage)(struct sock *sk, struct page *page, int offset, size_t size, int flags);
};

struct page;

#define unlikely(x) __builtin_expect(!!(x), 0)

extern int inet_send_prepare(struct sock *sk);
extern ssize_t sock_no_sendpage(struct socket *sock, struct page *page, int offset, size_t size, int flags);