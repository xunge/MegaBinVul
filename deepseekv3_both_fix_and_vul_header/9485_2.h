#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define FCS_LEN 4
#define IEEE80211_ENCRYPT_TAILROOM 18
#define EINVAL 22
#define ENOMEM 12

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    unsigned char cb[48];
    int priority;
    void *dev;
    struct sk_buff_head list;
};

struct ieee80211_tx_data {
    struct ieee80211_local *local;
    struct sk_buff_head skbs;
    struct ieee80211_sub_if_data *sdata;
};

struct ieee80211_local {
    unsigned int tx_headroom;
};

struct ieee80211_sub_if_data {
    unsigned int encrypt_headroom;
};

struct ieee80211_tx_info {
    uint32_t flags;
};

#define IEEE80211_TX_CTL_CLEAR_PS_FILT 0x00000001
#define IEEE80211_TX_CTL_FIRST_FRAGMENT 0x00000002
#define IEEE80211_TX_CTL_MORE_FRAMES 0x00000004

#define IEEE80211_SKB_CB(skb) ((struct ieee80211_tx_info *)((skb)->cb))
#define WARN_ON(condition) (condition)

struct sk_buff *dev_alloc_skb(unsigned int size);
void skb_reserve(struct sk_buff *skb, unsigned int len);
void __skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk);
void skb_copy_queue_mapping(struct sk_buff *new, struct sk_buff *old);
unsigned char *skb_put(struct sk_buff *skb, unsigned int len);