#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define GFP_KERNEL 0
#define EOPNOTSUPP 95
#define EINVAL 22
#define EINPROGRESS 115
#define ENOMEM 12
#define IEEE80211_NUM_BANDS 2
#define IEEE80211_MAX_SSID_LEN 32
#define WIPHY_FLAG_SUPPORTS_SCHED_SCAN (1 << 0)
#define NL80211_ATTR_IE 1
#define NL80211_ATTR_SCHED_SCAN_INTERVAL 2
#define NL80211_ATTR_SCAN_FREQUENCIES 3
#define NL80211_ATTR_SCAN_SSIDS 4
#define NL80211_CMD_START_SCHED_SCAN 5
#define IEEE80211_CHAN_DISABLED (1 << 0)

typedef uint32_t u32;
typedef uint8_t u8;

enum ieee80211_band {
    IEEE80211_BAND_2GHZ,
    IEEE80211_BAND_5GHZ,
};

struct sk_buff;
struct genl_info {
    void *user_ptr[2];
    struct nlattr *attrs[10];
};
struct nlattr;
struct net_device;
struct wiphy {
    u32 flags;
    u32 max_scan_ssids;
    size_t max_scan_ie_len;
    struct {
        struct {
            struct ieee80211_channel *channels;
            u32 n_channels;
        } *bands[IEEE80211_NUM_BANDS];
    };
};

struct ieee80211_channel {
    u32 center_freq;
    u32 hw_value;
    u32 flags;
};

struct cfg80211_ssid {
    u8 ssid[IEEE80211_MAX_SSID_LEN];
    u8 ssid_len;
};

struct cfg80211_sched_scan_request {
    struct cfg80211_ssid *ssids;
    struct ieee80211_channel **channels;
    u8 *ie;
    u32 n_ssids;
    u32 n_channels;
    u32 interval;
    size_t ie_len;
    struct net_device *dev;
    struct wiphy *wiphy;
};

struct cfg80211_registered_device {
    struct wiphy wiphy;
    struct cfg80211_sched_scan_request *sched_scan_req;
    struct {
        int (*sched_scan_start)(struct wiphy *, struct net_device *, 
                               struct cfg80211_sched_scan_request *);
    } *ops;
};

static inline int is_valid_ie_attr(struct nlattr *attr) { return 1; }
static inline int validate_scan_freqs(struct nlattr *attr) { return 1; }
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline struct ieee80211_channel *ieee80211_get_channel(struct wiphy *wiphy, u32 freq) { return NULL; }
static inline u32 nla_get_u32(struct nlattr *attr) { return 0; }
static inline size_t nla_len(struct nlattr *attr) { return 0; }
static inline void *nla_data(struct nlattr *attr) { return NULL; }
static inline void nl80211_send_sched_scan(struct cfg80211_registered_device *rdev,
                                         struct net_device *dev, int cmd) {}
#define nla_for_each_nested(attr, nattr, rem) \
    for (attr = nattr, rem = 0; rem < 1; rem++)