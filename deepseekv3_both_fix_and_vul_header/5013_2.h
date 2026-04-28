#include <stddef.h>
#include <assert.h>

#define max_hops 1
#define MAX_MODFUNCTIONS 1
#define GFP_ATOMIC 0
#define IFF_UP 1
#define CHECKSUM_UNNECESSARY 0
#define CGW_FLAGS_CAN_IIF_TX_OK 0
#define CGW_FLAGS_CAN_SRC_TSTAMP 0
#define CGW_FLAGS_CAN_ECHO 0

#define BUG_ON(condition) assert(!(condition))

struct sk_buff {
    unsigned int csum_start;
    unsigned char ip_summed;
    unsigned int len;
    void *data;
    void *dev;
    unsigned long tstamp;
};

struct net_device {
    unsigned int flags;
    int ifindex;
};

struct can_frame {
    unsigned char can_dlc;
    unsigned char data[8];
};

struct cgw_job {
    unsigned int deleted_frames;
    unsigned int dropped_frames;
    unsigned int handled_frames;
    struct {
        void (*modfunc[MAX_MODFUNCTIONS])(struct can_frame *, void *);
        struct {
            void (*crc8)(struct can_frame *, void *);
            void (*xor)(struct can_frame *, void *);
        } csumfunc;
        struct {
            unsigned char crc8;
            unsigned char xor;
        } csum;
    } mod;
    struct {
        struct net_device *dev;
        int ifindex;
    } dst;
    unsigned int flags;
    unsigned int limit_hops;
};

struct can_skb_priv {
    int ifindex;
};

static inline struct can_skb_priv *can_skb_prv(struct sk_buff *skb) {
    return (struct can_skb_priv *)skb;
}

static inline struct sk_buff *skb_copy(struct sk_buff *skb, int flags) {
    return 0;
}

static inline struct sk_buff *skb_clone(struct sk_buff *skb, int flags) {
    return 0;
}

static inline int can_send(struct sk_buff *skb, int echo) {
    return 0;
}

static inline void kfree_skb(struct sk_buff *skb) {
}