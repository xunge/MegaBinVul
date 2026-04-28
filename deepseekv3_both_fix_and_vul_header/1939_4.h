#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define EINVAL 1
#define EOPNOTSUPP 2
#define EBUSY 3
#define ENOMEM 4
#define GFP_KERNEL 0
#define IEEE80211_MAX_SSID_LEN 32
#define IEEE80211_CHAN_DISABLED 0x0002
#define NL80211_ATTR_IE 0
#define NL80211_ATTR_SCAN_FREQUENCIES 1
#define NL80211_ATTR_SCAN_SSIDS 2

enum ieee80211_band {
    IEEE80211_BAND_2GHZ = 0,
    IEEE80211_BAND_5GHZ,
    IEEE80211_BAND_60GHZ,
    IEEE80211_NUM_BANDS
};

struct sk_buff;
struct genl_info {
    void *user_ptr[2];
    void *attrs[3];
};
struct nlattr;
struct net_device;
struct ieee80211_channel {
    int flags;
};
struct wiphy {
    int max_scan_ssids;
    size_t max_scan_ie_len;
    struct {
        int n_channels;
        struct ieee80211_channel *channels;
    } *bands[IEEE80211_NUM_BANDS];
};
struct cfg80211_scan_request {
    struct net_device *dev;
    struct wiphy *wiphy;
    struct ieee80211_channel **channels;
    struct {
        unsigned char ssid[IEEE80211_MAX_SSID_LEN];
        size_t ssid_len;
    } *ssids;
    void *ie;
    int n_channels;
    int n_ssids;
    size_t ie_len;
};
struct cfg80211_registered_device {
    struct wiphy wiphy;
    struct {
        int (*scan)(struct wiphy *, struct net_device *, struct cfg80211_scan_request *);
    } *ops;
    struct cfg80211_scan_request *scan_req;
};

static inline int nla_len(const struct nlattr *nla) { return 0; }
static inline void *nla_data(const struct nlattr *nla) { return NULL; }
static inline unsigned int nla_get_u32(const struct nlattr *nla) { return 0; }
static inline int is_valid_ie_attr(const struct nlattr *attr) { return 1; }
static inline int validate_scan_freqs(const struct nlattr *attr) { return 1; }
static inline struct ieee80211_channel *ieee80211_get_channel(struct wiphy *wiphy, unsigned int freq) { return NULL; }
static inline void nl80211_send_scan_start(struct cfg80211_registered_device *rdev, struct net_device *dev) {}
static inline void dev_hold(struct net_device *dev) {}
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
#define nla_for_each_nested(attr, nla, rem) for (attr = NULL; attr != NULL; attr = NULL)