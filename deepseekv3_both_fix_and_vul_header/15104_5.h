#include <sys/socket.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <linux/types.h>

#define SOCK_ZAPPED 0x0100
#define SEND_SHUTDOWN 1
#define TCP_ESTABLISHED 1
#define X25_MAX_L2_LEN 18
#define X25_EXT_MIN_LEN 5
#define X25_STD_MIN_LEN 3
#define X25_GFI_EXTSEQ 0x10
#define X25_GFI_STDSEQ 0x00
#define X25_INTERRUPT 0x23
#define X25_DATA 0x00
#define X25_Q_BIT 0x80
#define MSG_CMSG_COMPAT 0x80000000

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock {
    unsigned short sk_state;
    unsigned int sk_shutdown;
};
struct x25_address {
    char x25_addr[16];
};
struct sockaddr_x25 {
    unsigned short sx25_family;
    struct x25_address sx25_addr;
};
struct sk_buff_head {
    struct sk_buff *next;
};
struct sk_buff {
    unsigned char *data;
    unsigned char cb[48];
    struct sk_buff_head *list;
};
struct x25_neighbour {
    unsigned int extended;
};
struct x25_sock {
    struct x25_address dest_addr;
    struct x25_neighbour *neighbour;
    unsigned int qbitincl;
    unsigned short lci;
    struct sk_buff_head interrupt_out_queue;
};

#define SOCK_DEBUG(sk, fmt, ...) 
#define X25_SKB_CB(skb) ((struct x25_skb_cb *)&((skb)->cb[0]))
#define current (struct task_struct *)0

struct x25_skb_cb {
    unsigned int flags;
};

static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, size_t size, int noblock, int *rc) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline void skb_reset_transport_header(struct sk_buff *skb) {}
static inline void *skb_transport_header(struct sk_buff *skb) { return NULL; }
static inline void skb_put(struct sk_buff *skb, int len) {}
static inline int memcpy_fromiovec(void *dst, struct iovec *iov, int len) { return 0; }
static inline void skb_pull(struct sk_buff *skb, int len) {}
static inline unsigned char *skb_push(struct sk_buff *skb, int len) { return NULL; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline void x25_kick(struct sock *sk) {}
static inline int x25_output(struct sock *sk, struct sk_buff *skb) { return 0; }
static inline void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *skb) {}
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline void send_sig(int sig, void *p, int priv) {}
static inline struct x25_sock *x25_sk(struct sock *sk) { return NULL; }