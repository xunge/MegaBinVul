#include <sys/socket.h>
#include <sys/uio.h>
#include <string.h>
#include <errno.h>

struct sockaddr_pn {
    unsigned short spn_family;
    char spn_data[0];
};

struct kiocb {
    int dummy;
};

struct sock {
    int dummy;
};

struct sk_buff {
    unsigned int len;
    void *data;
};

#define MSG_CMSG_COMPAT 0x80000000

static struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) {
    return NULL;
}

static void pn_skb_get_src_sockaddr(struct sk_buff *skb, struct sockaddr_pn *sa) {
}

static int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *to, int size) {
    return 0;
}

static void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {
}