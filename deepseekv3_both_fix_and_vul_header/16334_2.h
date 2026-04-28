#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>

struct file;
struct socket;
struct io_ring_ctx {
    struct socket *ring_sock;
};

extern const struct file_operations io_uring_fops;
extern struct net init_net;