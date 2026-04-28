#include <sys/socket.h>
#include <stdlib.h>

struct socket;
struct msghdr;
struct user_msghdr;
struct sockaddr;
struct sockaddr_storage;

#define __user
#define UIO_FASTIOV 8
#define EINVAL 22

ssize_t recvmsg_copy_msghdr(struct msghdr *msg, struct user_msghdr __user *umsg,
                           unsigned int flags, struct sockaddr __user **uaddr,
                           struct iovec **iov);
long ____sys_recvmsg(struct socket *sock, struct msghdr *msg_sys,
                    struct user_msghdr __user *umsg, struct sockaddr __user *uaddr,
                    unsigned int flags, int dummy);