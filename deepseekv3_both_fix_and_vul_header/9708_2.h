#include <string.h>
#include <stddef.h>

#define CFSIZ 16
#define BCM_CAN_DLC_MASK 0x0F
#define AF_CAN 29

struct sk_buff {
    unsigned char *cb;
    unsigned long tstamp;
};

struct can_frame {
    unsigned char can_dlc;
};

struct sockaddr_can {
    int can_family;
    int can_ifindex;
};

struct sock;
struct bcm_sock {
    int dropped_usr_msgs;
};

struct bcm_op {
    struct sock *sk;
    unsigned long rx_stamp;
    int rx_ifindex;
};

struct bcm_msg_head {
    int nframes;
};

static inline struct bcm_sock *bcm_sk(const struct sock *sk) { return (struct bcm_sock *)sk; }
static inline void *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline void *skb_tail_pointer(struct sk_buff *skb) { return NULL; }
static inline struct sk_buff *alloc_skb(unsigned int size, int priority) { return NULL; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline int sock_queue_rcv_skb(struct sock *sk, struct sk_buff *skb) { return 0; }
#define gfp_any() 0
#define BUILD_BUG_ON(cond)