#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

struct sk_buff {
    struct net_device *dev;
    void *head;
    void *data;
};

struct iphdr {
    uint32_t saddr;
};

struct dst_entry {
    struct net_device *dev;
};

struct net_device {
    struct ec_device *ec_ptr;
};

struct ec_device {
    uint8_t net;
};

struct sock;

struct aunhdr {
    uint16_t port;
    uint16_t cb;
    uint32_t handle;
};

#define GFP_ATOMIC 0
#define KERN_DEBUG ""

static inline struct iphdr *ip_hdr(const struct sk_buff *skb) { return (struct iphdr *)skb->head; }
static inline struct dst_entry *skb_dst(const struct sk_buff *skb) { return NULL; }
static inline struct sk_buff *alloc_skb(unsigned int size, int priority) { return NULL; }
static inline void *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void sock_put(struct sock *sk) {}
static inline int printk(const char *fmt, ...) { return 0; }

extern struct sock *ec_listening_socket(uint16_t port, uint8_t stn, uint8_t net);
extern int ec_queue_packet(struct sock *sk, struct sk_buff *skb, uint8_t stn, uint8_t net, uint16_t cb, uint16_t port);
extern void aun_send_response(uint32_t saddr, uint32_t handle, int code, int pad);