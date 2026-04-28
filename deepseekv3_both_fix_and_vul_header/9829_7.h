#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <sys/uio.h>
#include <linux/types.h>

struct kiocb;
struct socket {
    struct sock *sk;
    int type;
};
struct sock {
    unsigned int sk_priority;
};
struct sockaddr_ec {
    struct {
        unsigned char station;
        unsigned char net;
    } addr;
    unsigned char port;
    unsigned char cb;
    unsigned long cookie;
};
struct net_device {
    unsigned short type;
    unsigned int mtu;
    unsigned int flags;
};
struct ec_addr {
    unsigned char station;
    unsigned char net;
};
struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned short protocol;
    struct net_device *dev;
    unsigned int priority;
    char cb[48];
};
struct ec_cb {
    unsigned long cookie;
    unsigned long timeout;
    unsigned long start;
    unsigned long seq;
    struct sockaddr_ec sec;
    void (*sent)(struct sk_buff *);
};
struct aunhdr {
    unsigned char port;
    unsigned char cb;
    unsigned char code;
    unsigned char pad;
    unsigned long handle;
};
struct in_device {
    struct in_ifaddr *ifa_list;
};
struct in_ifaddr {
    unsigned long ifa_address;
};
struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};
struct econet_sock {
    unsigned char station;
    unsigned char net;
    unsigned char port;
    unsigned char cb;
};
struct ec_framehdr {
    unsigned char cb;
    unsigned char port;
};

typedef unsigned long mm_segment_t;

extern pthread_mutex_t econet_mutex;
extern struct net_device *net2dev_map[];
extern struct socket *udpsock;
extern unsigned long aun_seq;
extern struct sk_buff_head aun_queue;
extern unsigned long jiffies;
extern void ec_tx_done(struct sk_buff *);

#define AUN_PORT 0x8000
#define CONFIG_ECONET_AUNUDP
#define CONFIG_ECONET_NATIVE
#define ARPHRD_ECONET 0x0001
#define IFF_UP 0x1
#define EINVAL 22
#define ENETDOWN 100
#define EMSGSIZE 90
#define EPROTOTYPE 91
#define EFAULT 14
#define HZ 100
#define KERNEL_DS ((mm_segment_t) {0})
#define VERIFY_READ 0
#define MSG_CMSG_COMPAT 0x80000000
#define LL_ALLOCATED_SPACE(dev) (16)
#define LL_RESERVED_SPACE(dev) (16)
#define __user

/* Function prototypes */
static inline struct econet_sock *ec_sk(const struct sock *sk) { return NULL; }
static inline void mutex_lock(pthread_mutex_t *mutex) {}
static inline void mutex_unlock(pthread_mutex_t *mutex) {}
static inline void dev_hold(struct net_device *dev) {}
static inline void dev_put(struct net_device *dev) {}
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, unsigned long size, int flags, int *err) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline void skb_reset_network_header(struct sk_buff *skb) {}
static inline int dev_hard_header(struct sk_buff *skb, struct net_device *dev, unsigned short type, const void *daddr, const void *saddr, unsigned len) { return 0; }
static inline void skb_reset_tail_pointer(struct sk_buff *skb) {}
static inline int memcpy_fromiovec(unsigned char *kdata, struct iovec *iov, int len) { return 0; }
static inline unsigned char *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline void dev_queue_xmit(struct sk_buff *skb) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void rcu_read_lock(void) {}
static inline struct in_device *__in_dev_get_rcu(const struct net_device *dev) { return NULL; }
static inline void rcu_read_unlock(void) {}
static inline int access_ok(int type, const void *addr, unsigned long size) { return 1; }
static inline void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk) {}
static inline mm_segment_t get_fs(void) { return KERNEL_DS; }
static inline void set_fs(mm_segment_t fs) {}
static inline int sock_sendmsg(struct socket *sock, struct msghdr *msg, size_t len) { return 0; }