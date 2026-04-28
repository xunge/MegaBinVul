#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define ETH_ALEN 6
#define SNAP_SIZE 6
#define IEEE80211_3ADDR_LEN 24
#define IEEE80211_4ADDR_LEN 30
#define ETH_P_PAE 0x888E
#define ETH_P_AARP 0x80F3
#define ETH_P_IPX 0x8137
#define ETH_HLEN 14

#define WLAN_FC_GET_TYPE(fc) (((fc) & 0x000c) >> 2)
#define WLAN_FC_GET_STYPE(fc) (((fc) & 0x00f0) >> 4)
#define WLAN_GET_SEQ_FRAG(sc) ((sc) & 0x000f)
#define WLAN_GET_SEQ_SEQ(sc) (((sc) & 0xfff0) >> 4)

#define IEEE80211_FCTL_FROMDS 0x0100
#define IEEE80211_FCTL_TODS 0x0200
#define IEEE80211_FCTL_PROTECTED 0x4000
#define IEEE80211_FCTL_MOREFRAGS 0x0004

#define IEEE80211_STYPE_QOS_DATA 0x0080
#define IEEE80211_STYPE_DATA 0x0000
#define IEEE80211_STYPE_DATA_CFACK 0x0010
#define IEEE80211_STYPE_DATA_CFPOLL 0x0020
#define IEEE80211_STYPE_DATA_CFACKPOLL 0x0030
#define IEEE80211_STYPE_NULLFUNC 0x0040

#define SEC_ALG_WEP 0
#define SEC_ALG_TKIP 1
#define SEC_ALG_CCMP 2

#define IW_MODE_MONITOR 6
#define IW_MODE_MASTER 3
#define IW_MODE_REPEAT 4

#define CHECKSUM_NONE 0

struct net_device_stats {
    unsigned long rx_packets;
    unsigned long rx_bytes;
    unsigned long rx_dropped;
};

struct net_device {
    char name[16];
    unsigned long last_rx;
    struct net_device_stats stats;
};

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    void *dev;
    u16 protocol;
    unsigned char cb[48];
    unsigned char *tail;
    unsigned char *end;
    int ip_summed;
};

struct ieee80211_stats {
    unsigned long rx_discards_undecryptable;
};

struct ieee80211_device {
    struct net_device *dev;
    struct net_device_stats stats;
    struct ieee80211_stats ieee_stats;
    u16 prev_seq_ctl;
    int host_mc_decrypt;
    int host_decrypt;
    int open_wep;
    int host_strip_iv_icv;
    struct {
        int encode_alg[4];
    } sec;
    struct ieee80211_crypt_data *crypt[4];
    int iw_mode;
};

struct ieee80211_rx_stats {
    int mask;
    int rssi;
    int noise;
    int signal;
};

struct ieee80211_hdr_4addr {
    u16 frame_ctl;
    u16 seq_ctl;
    u8 addr1[6];
    u8 addr2[6];
    u8 addr3[6];
    u8 addr4[6];
};

struct ieee80211_crypt_ops {
    int (*decrypt_mpdu)(void);
};

struct ieee80211_crypt_data {
    struct ieee80211_crypt_ops *ops;
};

static const u8 rfc1042_header[] = {0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00};
static const u8 bridge_tunnel_header[] = {0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8};

static inline u16 le16_to_cpu(u16 val) {
    return val;
}

static inline u16 htons(u16 val) {
    return ((val >> 8) | (val << 8));
}

static inline int is_multicast_ether_addr(const u8 *addr) {
    return (addr[0] & 0x01);
}

static inline int is_broadcast_ether_addr(const u8 *addr) {
    return (addr[0] & addr[1] & addr[2] & addr[3] & addr[4] & addr[5]) == 0xff;
}

static inline size_t ieee80211_get_hdrlen(u16 fc) {
    int hdrlen = 24;
    if ((fc & IEEE80211_FCTL_FROMDS) && (fc & IEEE80211_FCTL_TODS))
        hdrlen = 30;
    return hdrlen;
}

static inline void *skb_put(struct sk_buff *skb, unsigned int len) {
    void *tmp = skb->tail;
    skb->tail += len;
    skb->len += len;
    return tmp;
}

static inline void skb_pull(struct sk_buff *skb, unsigned int len) {
    skb->data += len;
    skb->len -= len;
}

static inline void *skb_push(struct sk_buff *skb, unsigned int len) {
    skb->data -= len;
    skb->len += len;
    return skb->data;
}

static inline void __skb_trim(struct sk_buff *skb, unsigned int len) {
    skb->len = len;
    skb->tail = skb->data + len;
}

static inline void dev_kfree_skb_any(struct sk_buff *skb) {
    (void)skb;
}

static inline u16 eth_type_trans(struct sk_buff *skb, struct net_device *dev) {
    (void)skb; (void)dev;
    return 0;
}

static inline int netif_rx(struct sk_buff *skb) {
    (void)skb;
    return 0;
}

static inline int ieee80211_is_eapol_frame(struct ieee80211_device *ieee, struct sk_buff *skb) {
    (void)ieee; (void)skb;
    return 0;
}

static inline int ieee80211_rx_frame_decrypt(struct ieee80211_device *ieee, 
                                           struct sk_buff *skb,
                                           struct ieee80211_crypt_data *crypt) {
    (void)ieee; (void)skb; (void)crypt;
    return 0;
}

static inline int ieee80211_rx_frame_decrypt_msdu(struct ieee80211_device *ieee,
                                                struct sk_buff *skb,
                                                int keyidx,
                                                struct ieee80211_crypt_data *crypt) {
    (void)ieee; (void)skb; (void)keyidx; (void)crypt;
    return 0;
}

static inline struct sk_buff *ieee80211_frag_cache_get(struct ieee80211_device *ieee,
                                                     struct ieee80211_hdr_4addr *hdr) {
    (void)ieee; (void)hdr;
    return NULL;
}

static inline void ieee80211_frag_cache_invalidate(struct ieee80211_device *ieee,
                                                 struct ieee80211_hdr_4addr *hdr) {
    (void)ieee; (void)hdr;
}

static inline void ieee80211_monitor_rx(struct ieee80211_device *ieee,
                                      struct sk_buff *skb,
                                      struct ieee80211_rx_stats *rx_stats) {
    (void)ieee; (void)skb; (void)rx_stats;
}

static inline void skb_copy_from_linear_data(struct sk_buff *skb, void *to, unsigned int len) {
    memcpy(to, skb->data, len);
}

static inline void skb_copy_from_linear_data_offset(struct sk_buff *skb, unsigned int offset,
                                                  void *to, unsigned int len) {
    memcpy(to, skb->data + offset, len);
}

#define printk(...)
#define KERN_INFO ""
#define KERN_DEBUG ""
#define KERN_WARNING ""
#define IEEE80211_DEBUG_DROP(...)
#define IEEE80211_DEBUG(...)
#define IEEE80211_DEBUG_FRAG(...)
#define NET_RX_DROP 0
#define jiffies 0