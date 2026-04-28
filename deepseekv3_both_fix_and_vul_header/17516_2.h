#include <stdint.h>
#include <string.h>

#define SLC_CMD_LEN 1
#define SLC_SFF_ID_LEN 3
#define SLC_EFF_ID_LEN 8
#define CAN_RTR_FLAG 0x40000000
#define CAN_EFF_FLAG 0x80000000
#define ETH_P_CAN 0x000C
#define PACKET_BROADCAST 1
#define CHECKSUM_UNNECESSARY 0

typedef uint32_t u32;
typedef uint64_t u64;

struct net_device_stats {
    unsigned long rx_packets;
    unsigned long rx_bytes;
};

struct net_device {
    int ifindex;
    struct net_device_stats stats;
};

struct slcan {
    char rbuff[256];
    struct net_device *dev;
};

struct can_frame {
    uint32_t can_id;
    uint8_t can_dlc;
    uint8_t data[8];
};

struct sk_buff {
    struct net_device *dev;
    uint16_t protocol;
    uint8_t pkt_type;
    uint8_t ip_summed;
    void* data;
};

struct can_skb_priv {
    int ifindex;
};

static inline uint16_t htons(uint16_t x) {
    return ((x & 0xFF) << 8) | ((x & 0xFF00) >> 8);
}

static inline int hex_to_bin(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'A' && ch <= 'F') return 10 + ch - 'A';
    if (ch >= 'a' && ch <= 'f') return 10 + ch - 'a';
    return -1;
}

static inline int kstrtou32(const char *s, unsigned int base, u32 *res) {
    char *end;
    unsigned long val = strtoul(s, &end, base);
    if (*end != '\0' || end == s) return -1;
    *res = (u32)val;
    return 0;
}

static inline struct sk_buff *dev_alloc_skb(unsigned int size) {
    return (struct sk_buff *)malloc(sizeof(struct sk_buff));
}

static inline void can_skb_reserve(struct sk_buff *skb) {
    // Dummy implementation
}

static inline struct can_skb_priv *can_skb_prv(struct sk_buff *skb) {
    return (struct can_skb_priv *)(skb + 1);
}

static inline void *skb_put(struct sk_buff *skb, unsigned int len) {
    void *tmp = skb->data;
    skb->data += len;
    return tmp;
}

static inline int netif_rx_ni(struct sk_buff *skb) {
    free(skb);
    return 0;
}