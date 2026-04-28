#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
};

#define BT_DBG(fmt, ...)
#define GFP_KERNEL 0
#define EOPNOTSUPP 95
#define ENOMEM 12
#define EFAULT 14
#define ENOTCONN 107
#define BT_CONNECTED 1

void *kmalloc(size_t size, int flags);
void kfree(const void *objp);
int memcpy_from_msg(void *buf, struct msghdr *msg, size_t len);
void lock_sock(struct sock *sk);
void release_sock(struct sock *sk);
int sock_error(struct sock *sk);
int sco_send_frame(struct sock *sk, void *buf, size_t len, ...);