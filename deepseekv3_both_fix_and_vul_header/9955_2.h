#include <sys/socket.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <linux/if_arp.h>

#define MSG_CMSG_COMPAT 0x80000000
#define EINVAL 22
#define ENETDOWN 100
#define EPROTOTYPE 91
#define EMSGSIZE 90
#define E2BIG 7
#define ENOMEM 12
#define IFF_UP 0x1
#define AUN_PORT 32768
#define HZ 100
#define LL_ALLOCATED_SPACE(dev) 0
#define LL_RESERVED_SPACE(dev) 0

struct sockaddr_ec {
    unsigned short addr_type;
    unsigned short port;
    unsigned char cb;
    struct {
        unsigned char station;
        unsigned char net;
    } addr;
    unsigned long cookie;
};

struct ec_addr {
    unsigned char station;
    unsigned char net;
};

struct ec_cb {
    unsigned long cookie;
    struct sockaddr_ec sec;
    void (*sent)(void *);
    unsigned long timeout;
    unsigned long start;
    unsigned long seq;
};

struct ec_framehdr {
    unsigned char cb;
    unsigned char port;
};

struct aunhdr {
    unsigned char port;
    unsigned char cb;
    unsigned char code;
    unsigned char pad;
    unsigned long handle;
};

struct net_device {
    unsigned short type;
    unsigned int mtu;
    unsigned int flags;
};

struct sk_buff {
    void *data;
    unsigned int len;
    void *cb;
    struct net_device *dev;
    unsigned short protocol;
    unsigned int priority;
};

struct sockaddr_in {
    short sin_family;
    unsigned short sin_port;
    unsigned long sin_addr;
};

struct socket;
struct sock;
struct kiocb;
struct msghdr;
struct in_device;

extern pthread_mutex_t econet_mutex;
extern struct net_device *net2dev_map[];
extern struct socket *udpsock;
extern unsigned long aun_seq;
extern struct sk_buff_head aun_queue;
extern unsigned long jiffies;

static inline void mutex_lock(pthread_mutex_t *mutex) { pthread_mutex_lock(mutex); }
static inline void mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }
static inline void dev_hold(struct net_device *dev) {}
static inline void dev_put(struct net_device *dev) {}
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}
static inline void set_fs(unsigned long fs) {}
static inline unsigned long get_fs() { return 0; }
static inline unsigned long ntohl(unsigned long val) { return val; }
static inline unsigned short ntohs(unsigned short val) { return val; }
static inline unsigned long htonl(unsigned long val) { return val; }
static inline unsigned short htons(unsigned short val) { return val; }