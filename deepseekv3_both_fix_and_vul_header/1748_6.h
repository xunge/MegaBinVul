#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint16_t __le16;

struct sk_buff {
    void *data;
    unsigned int len;
    unsigned char cb[48];
};

struct ieee80211_sta {
    int ptk_idx;
    struct ieee80211_key *ptk[4];
};

struct ieee80211_link_sta {
    struct ieee80211_key *gtk[4];
};

struct ieee80211_link {
    struct ieee80211_key *gtk[4];
    struct ieee80211_key *default_mgmt_key;
};

struct ieee80211_sdata {
    struct ieee80211_key *keys[4];
    struct net_device *dev;
};

struct ieee80211_rx_data {
    struct sk_buff *skb;
    struct ieee80211_key *key;
    struct ieee80211_sta *sta;
    struct ieee80211_link_sta *link_sta;
    struct ieee80211_link *link;
    struct ieee80211_sdata *sdata;
};

struct ieee80211_rx_status {
    unsigned int flag;
};

struct ieee80211_hdr {
    __le16 frame_control;
    uint8_t addr1[6];
};

struct ieee80211_key {
    unsigned int flags;
    struct {
        int cipher;
    } conf;
};

typedef enum {
    RX_CONTINUE,
    RX_DROP_UNUSABLE,
    RX_DROP_MONITOR
} ieee80211_rx_result;

#define IEEE80211_SKB_RXCB(skb) ((struct ieee80211_rx_status *)((skb)->cb))
#define NUM_DEFAULT_KEYS 4
#define NUM_DEFAULT_MGMT_KEYS 2
#define NUM_DEFAULT_BEACON_KEYS 2
#define WLAN_STA_MFP 0x00000010
#define KEY_FLAG_TAINTED 0x00000001
#define IEEE80211_CCMP_MIC_LEN 8
#define IEEE80211_CCMP_256_MIC_LEN 16
#define RX_FLAG_DECRYPTED 0x00000002
#define RX_FLAG_IV_STRIPPED 0x00000004

#define WLAN_CIPHER_SUITE_WEP40 0x000FAC01
#define WLAN_CIPHER_SUITE_WEP104 0x000FAC05
#define WLAN_CIPHER_SUITE_TKIP 0x000FAC02
#define WLAN_CIPHER_SUITE_CCMP 0x000FAC04
#define WLAN_CIPHER_SUITE_CCMP_256 0x000FAC10
#define WLAN_CIPHER_SUITE_AES_CMAC 0x000FAC06
#define WLAN_CIPHER_SUITE_BIP_CMAC_256 0x000FAC12
#define WLAN_CIPHER_SUITE_BIP_GMAC_128 0x000FAC13
#define WLAN_CIPHER_SUITE_BIP_GMAC_256 0x000FAC14
#define WLAN_CIPHER_SUITE_GCMP 0x000FAC08
#define WLAN_CIPHER_SUITE_GCMP_256 0x000FAC09

static inline bool ieee80211_is_ext(__le16 fc) { return false; }
static inline bool ieee80211_has_protected(__le16 fc) { return false; }
static inline bool ieee80211_is_beacon(__le16 fc) { return false; }
static inline bool ieee80211_is_mgmt(__le16 fc) { return false; }
static inline bool ieee80211_is_group_privacy_action(struct sk_buff *skb) { return false; }
static inline int ieee80211_get_keyid(struct sk_buff *skb) { return 0; }
static inline int ieee80211_get_mmie_keyidx(struct sk_buff *skb) { return 0; }
static inline bool test_sta_flag(struct ieee80211_sta *sta, int flag) { return false; }
static inline struct ieee80211_key *ieee80211_rx_get_bigtk(struct ieee80211_rx_data *rx, int idx) { return NULL; }
static inline bool is_multicast_ether_addr(const uint8_t *addr) { return false; }
static inline void cfg80211_rx_unprot_mlme_mgmt(struct net_device *dev, void *data, unsigned int len) {}

#define rcu_dereference(p) (p)
#define unlikely(x) (x)
#define debug_noinline __attribute__((noinline))

static inline ieee80211_rx_result ieee80211_crypto_wep_decrypt(struct ieee80211_rx_data *rx) { return RX_CONTINUE; }
static inline ieee80211_rx_result ieee80211_crypto_tkip_decrypt(struct ieee80211_rx_data *rx) { return RX_CONTINUE; }
static inline ieee80211_rx_result ieee80211_crypto_ccmp_decrypt(struct ieee80211_rx_data *rx, int mic_len) { return RX_CONTINUE; }
static inline ieee80211_rx_result ieee80211_crypto_aes_cmac_decrypt(struct ieee80211_rx_data *rx) { return RX_CONTINUE; }
static inline ieee80211_rx_result ieee80211_crypto_aes_cmac_256_decrypt(struct ieee80211_rx_data *rx) { return RX_CONTINUE; }
static inline ieee80211_rx_result ieee80211_crypto_aes_gmac_decrypt(struct ieee80211_rx_data *rx) { return RX_CONTINUE; }
static inline ieee80211_rx_result ieee80211_crypto_gcmp_decrypt(struct ieee80211_rx_data *rx) { return RX_CONTINUE; }

struct net_device;