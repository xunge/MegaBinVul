#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define FCS_LEN 4
#define BIT(n) (1U << (n))
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define unlikely(x) (x)

typedef uint16_t u16;
typedef uint8_t u8;

struct sk_buff {
    unsigned int len;
    void *data;
    unsigned char cb[48];
};

struct net_device {
    struct {
        void *ieee80211_ptr;
    } *ieee80211_ptr;
};

struct ieee80211_local {
    struct {
        struct {
            struct ieee80211_supported_band **bands;
        } *wiphy;
        unsigned int max_rate_tries;
    } hw;
};

struct ieee80211_radiotap_iterator {
    int this_arg_index;
    unsigned char *this_arg;
    unsigned int _max_length;
};

struct ieee80211_radiotap_header {
    uint8_t it_version;
};

struct ieee80211_tx_info {
    unsigned int flags;
    unsigned int band;
    struct {
        struct {
            int idx;
            unsigned int flags;
            unsigned int count;
        } rates[4];
        unsigned int flags;
    } control;
};

struct ieee80211_supported_band {
    unsigned int n_bitrates;
    struct {
        unsigned int bitrate;
    } *bitrates;
};

#define IEEE80211_SKB_CB(skb) ((struct ieee80211_tx_info *)((skb)->cb))
#define wdev_priv(dev) ((struct ieee80211_local *)((dev)->ieee80211_ptr))

enum {
    IEEE80211_RADIOTAP_FLAGS,
    IEEE80211_RADIOTAP_TX_FLAGS,
    IEEE80211_RADIOTAP_RATE,
    IEEE80211_RADIOTAP_DATA_RETRIES,
    IEEE80211_RADIOTAP_MCS,
    IEEE80211_RADIOTAP_VHT,
};

#define IEEE80211_TX_MAX_RATES 4
#define IEEE80211_TX_INTFL_DONT_ENCRYPT BIT(0)
#define IEEE80211_TX_CTL_DONTFRAG BIT(1)
#define IEEE80211_TX_CTL_NO_ACK BIT(2)
#define IEEE80211_TX_CTRL_NO_SEQNO BIT(3)
#define IEEE80211_TX_CTRL_DONT_REORDER BIT(4)
#define IEEE80211_TX_CTL_LDPC BIT(5)
#define IEEE80211_TX_CTRL_RATE_INJECT BIT(6)
#define IEEE80211_TX_RC_MCS BIT(7)
#define IEEE80211_TX_RC_SHORT_GI BIT(8)
#define IEEE80211_TX_RC_40_MHZ_WIDTH BIT(9)
#define IEEE80211_TX_RC_80_MHZ_WIDTH BIT(10)
#define IEEE80211_TX_RC_160_MHZ_WIDTH BIT(11)
#define IEEE80211_TX_RC_VHT_MCS BIT(12)
#define IEEE80211_TX_CTL_STBC BIT(13)

#define IEEE80211_RADIOTAP_F_FCS BIT(0)
#define IEEE80211_RADIOTAP_F_WEP BIT(1)
#define IEEE80211_RADIOTAP_F_FRAG BIT(2)
#define IEEE80211_RADIOTAP_F_TX_NOACK BIT(3)
#define IEEE80211_RADIOTAP_F_TX_NOSEQNO BIT(4)
#define IEEE80211_RADIOTAP_F_TX_ORDER BIT(5)

#define IEEE80211_RADIOTAP_MCS_HAVE_MCS BIT(0)
#define IEEE80211_RADIOTAP_MCS_HAVE_GI BIT(1)
#define IEEE80211_RADIOTAP_MCS_SGI BIT(2)
#define IEEE80211_RADIOTAP_MCS_BW_MASK 0x3
#define IEEE80211_RADIOTAP_MCS_BW_40 1
#define IEEE80211_RADIOTAP_MCS_HAVE_BW BIT(3)
#define IEEE80211_RADIOTAP_MCS_HAVE_FEC BIT(4)
#define IEEE80211_RADIOTAP_MCS_FEC_LDPC BIT(5)
#define IEEE80211_RADIOTAP_MCS_HAVE_STBC BIT(6)
#define IEEE80211_RADIOTAP_MCS_STBC_MASK 0x3

#define IEEE80211_RADIOTAP_VHT_KNOWN_GI BIT(0)
#define IEEE80211_RADIOTAP_VHT_FLAG_SGI BIT(0)
#define IEEE80211_RADIOTAP_VHT_KNOWN_BANDWIDTH BIT(1)

#define ENOENT 2

static inline uint16_t get_unaligned_le16(const void *p) {
    const uint8_t *ptr = p;
    return ptr[0] | (ptr[1] << 8);
}

static inline int ieee80211_radiotap_iterator_init(
    struct ieee80211_radiotap_iterator *iterator,
    struct ieee80211_radiotap_header *radiotap_header,
    int max_length, void *arg) { return 0; }

static inline int ieee80211_radiotap_iterator_next(
    struct ieee80211_radiotap_iterator *iterator) { return 0; }

static inline unsigned int ieee80211_get_radiotap_len(const void *data) { return 0; }

static inline void ieee80211_rate_set_vht(struct ieee80211_tx_info *info,
                    uint8_t mcs, uint8_t nss) {}

static inline uint8_t u8_get_bits(uint8_t val, uint8_t mask) { return val & mask; }
static inline uint32_t u32_encode_bits(uint32_t val, uint32_t mask) { return val & mask; }
static inline void skb_trim(struct sk_buff *skb, unsigned int len) { skb->len = len; }