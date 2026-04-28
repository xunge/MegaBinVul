#include <sys/socket.h>
#include <stddef.h>

struct socket;
struct msghdr;

#define __user
#define UIO_FASTIOV 8
#define EINVAL 22

struct user_msghdr {
    void *msg_name;
    int msg_namelen;
    struct iovec *msg_iov;
    size_t msg_iovlen;
    void *msg_control;
    size_t msg_controllen;
    unsigned int msg_flags;
};

extern ssize_t sendmsg_copy_msghdr(struct msghdr *msg, struct user_msghdr __user *umsg, unsigned int flags, struct iovec **iov);
extern long ____sys_sendmsg(struct socket *sock, struct msghdr *msg, unsigned int flags, void *addr, int addr_len);
extern void kfree(void *ptr);

long ___sys_sendmsg(struct socket *sock, struct user_msghdr *msg,
                   struct msghdr *msg_sys, unsigned int flags, void *addr,
                   int addr_len);