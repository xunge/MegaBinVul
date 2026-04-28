#include <sys/socket.h>
#include <sys/uio.h>
#include <errno.h>
#include <stddef.h>

struct kiocb;

struct socket {
    int dummy;
};

struct vsock_sock {
    struct socket sk;
};

struct vmci_datagram {
    size_t payload_size;
    struct {
        int context;
        int resource;
    } src;
};

struct sockaddr_vm {
    int dummy;
};

struct sk_buff {
    void *data;
    size_t len;
    struct socket *sk;
};

static void vsock_addr_init(struct sockaddr_vm *vm_addr, int context, int resource) {}
static struct sk_buff *skb_recv_datagram(struct socket *sk, int flags, int noblock, int *err) { return NULL; }
static int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *to, int len) { return 0; }
static void skb_free_datagram(struct socket *sk, struct sk_buff *skb) {}