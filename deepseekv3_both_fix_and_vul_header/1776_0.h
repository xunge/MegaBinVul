#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <poll.h>
#include <errno.h>

#define SHUTDOWN_MASK 3
#define SOCK_WAKE_WAITD 1
#define POLL_HUP 0x10
#define ECONNRESET 104
#define TCP_LISTEN 10
#define TCP_CLOSE 7
#define SOCK_STREAM 1
#define SOCK_SEQPACKET 5

struct sock {
    int sk_shutdown;
    int sk_state;
    int sk_type;
    int sk_err;
    void *sk_receive_queue;
    void (*sk_state_change)(struct sock *);
    struct sock *peer;
};

struct path {
    void *dentry;
    void *mnt;
};

struct unix_sock {
    struct path path;
    void *peer_wait;
    struct sk_buff *oob_skb;
};

struct sk_buff {
    struct sock *sk;
    int len;
};

struct UNIXCB {
    int consumed;
};

#define unix_sk(sk) ((struct unix_sock *)(sk))
#define unix_peer(sk) ((sk)->peer)
#define skb_queue_empty(queue) (0)
#define skb_dequeue(queue) ((struct sk_buff *)0)
#define kfree_skb(skb) 
#define path_put(path) 
#define sock_put(sk) 
#define wake_up_interruptible_all(wait) 
#define unix_state_lock(sk) 
#define unix_state_unlock(sk) 
#define sock_orphan(sk) 
#define unix_remove_socket(net, sk) 
#define unix_remove_bsd_socket(sk) 
#define sk_wake_async(sk, type, mask) 
#define unix_dgram_peer_wake_disconnect(sk, skpair) 
#define unix_tot_inflight (0)
#define unix_gc() 
#define UNIXCB(skb) (*(struct UNIXCB *)0)
#define sock_net(sk) (0)
#define IS_ENABLED(x) (0)
#define CONFIG_AF_UNIX_OOB 0