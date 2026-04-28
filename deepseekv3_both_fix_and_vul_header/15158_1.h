#include <sys/types.h>
#include <fcntl.h>
#include <linux/net.h>
#include <linux/socket.h>
#include <linux/types.h>

struct file {
    struct socket *private_data;
    unsigned int f_flags;
};

struct socket {
    struct proto_ops *ops;
};

struct proto_ops {
    ssize_t (*sendpage)(struct socket *sock, struct page *page, int offset, size_t size, int flags);
};

struct page;

#define MSG_DONTWAIT 0x40
#define MSG_MORE 0x8000