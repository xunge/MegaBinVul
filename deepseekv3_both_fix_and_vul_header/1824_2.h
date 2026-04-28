#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

#define ETH_ALEN 6
#define ARPOP_REQUEST 1
#define ARPOP_REPLY 2
#define RLB_UPDATE_DELAY 1

struct slave {
    struct net_device *dev;
};

struct bonding {
    struct net_device *dev;
    struct {
        int rlb_update_delay_counter;
    } alb_info;
};

struct net_device {
    unsigned char dev_addr[ETH_ALEN];
    unsigned char addr_len;
    char *name;
};

struct sk_buff;
struct arp_pkt {
    unsigned char mac_src[ETH_ALEN];
    uint32_t ip_src;
    uint16_t op_code;
};

static struct slave *rlb_choose_channel(struct sk_buff *skb, struct bonding *bond, struct arp_pkt *arp);
bool bond_slave_has_mac_rx(const struct bonding *bond, const unsigned char *mac_addr);
void bond_hw_addr_copy(unsigned char *dst, const unsigned char *src, unsigned int len);
void rlb_req_update_subnet_clients(struct bonding *bond, uint32_t ip_src);
struct net_device *ip_dev_find(void *net, uint32_t addr);
int pskb_network_may_pull(struct sk_buff *skb, unsigned int len);
void *skb_network_header(struct sk_buff *skb);
void *dev_net(struct net_device *dev);
int netif_is_bridge_master(struct net_device *dev);
void netdev_dbg(struct net_device *dev, const char *fmt, ...);