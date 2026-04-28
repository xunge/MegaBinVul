#include <sys/socket.h>
#include <errno.h>
#include <stddef.h>

struct sk_buff;

struct nlmsghdr {
    unsigned int nlmsg_len;
};

struct sock_diag_req {
    unsigned short sdiag_family;
};

struct sock_diag_handler {
    int (*dump)(struct sk_buff *, struct nlmsghdr *);
};

static inline void *nlmsg_data(const struct nlmsghdr *nlh) {
    return (void *)((char *)nlh + sizeof(struct nlmsghdr));
}

static inline int nlmsg_len(const struct nlmsghdr *nlh) {
    return nlh->nlmsg_len - sizeof(struct nlmsghdr);
}

static const struct sock_diag_handler *sock_diag_lock_handler(int family) {
    return NULL;
}

static void sock_diag_unlock_handler(const struct sock_diag_handler *h) {
}