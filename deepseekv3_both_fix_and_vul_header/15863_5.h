#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;

struct sk_buff {
    u16 protocol;
};

struct net_device;

struct brcmf_bus {
    struct device *dev;
};

struct brcmf_driver {
    struct brcmf_bus *bus_if;
};

struct brcmf_if {
    struct net_device *ndev;
    struct brcmf_driver *drvr;
};

struct brcmf_msgbuf {
    struct brcmf_driver *drvr;
    void *rx_pktids;
    u16 rx_dataoffset;
    u32 cur_eventbuf;
};

struct msgbuf_rx_event {
    struct {
        u32 request_id;
        u16 ifidx;
    } msg;
    u16 event_data_len;
};

u32 le32_to_cpu(u32 val);
u16 le16_to_cpu(u16 val);
void brcmf_msgbuf_rxbuf_event_post(struct brcmf_msgbuf *msgbuf);
struct sk_buff *brcmf_msgbuf_get_pktid(struct device *dev, void *rx_pktids, u32 idx);
struct brcmf_if *brcmf_get_ifp(struct brcmf_driver *drvr, u16 ifidx);
void brcmf_err(const char *fmt, ...);
void brcmf_fweh_process_skb(struct brcmf_driver *drvr, struct sk_buff *skb, ...);
void brcmu_pkt_buf_free_skb(struct sk_buff *skb);
void skb_pull(struct sk_buff *skb, unsigned int len);
void skb_trim(struct sk_buff *skb, unsigned int len);
u16 eth_type_trans(struct sk_buff *skb, struct net_device *dev);