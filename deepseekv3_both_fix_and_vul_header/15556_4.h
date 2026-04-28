#include <sys/ioctl.h>
#include <unistd.h>

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_sndbuf;
    struct {
        int lock;
    } sk_receive_queue;
};

struct sk_buff {
    int len;
};

struct ddpehdr {
    int dummy;
};

#define ENOIOCTLCMD 515
#define EPERM 1
#define CAP_NET_ADMIN 12

#define TIOCOUTQ 0x5411
#define SIOCADDRT 0x890B
#define SIOCDELRT 0x890C
#define SIOCGIFADDR 0x8915
#define SIOCSIFADDR 0x8916
#define SIOCGIFBRDADDR 0x8919
#define SIOCATALKDIFADDR 0x8940
#define SIOCDIFADDR 0x8936
#define SIOCSARP 0x8955
#define SIOCDARP 0x8953

static inline long sk_wmem_alloc_get(struct sock *sk) { return 0; }
static inline struct sk_buff *skb_peek(void *queue) { return NULL; }
static inline int put_user(long amount, int *argp) { return 0; }
static inline int capable(int cap) { return 0; }
static inline void rtnl_lock(void) {}
static inline void rtnl_unlock(void) {}
static inline void spin_lock_irq(int *lock) {}
static inline void spin_unlock_irq(int *lock) {}

extern int atrtr_ioctl(unsigned int cmd, void *argp);
extern int atif_ioctl(unsigned int cmd, void *argp);

#define __user
typedef void *user_ptr_t;