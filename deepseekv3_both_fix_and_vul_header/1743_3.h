#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t __le16;
typedef uint64_t __le64;

#define WLAN_EID_SSID 0
#define WLAN_EID_MULTIPLE_BSSID 1
#define GFP_ATOMIC 0

struct element {
    u8 id;
    u8 datalen;
    u8 data[];
};

struct ieee80211_mgmt {
    __le16 frame_control;
    union {
        struct {
            __le64 timestamp;
            u8 variable[];
        } probe_resp;
    } u;
};

struct cfg80211_bss_ies {
    size_t len;
    __le64 tsf;
    bool from_beacon;
    u8 data[];
};

struct cfg80211_bss {
    struct cfg80211_bss_ies *ies;
    struct cfg80211_bss_ies *proberesp_ies;
    struct cfg80211_bss_ies *beacon_ies;
};

struct wiphy;
struct rdev;

void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
void kfree_rcu(void *ptr, const char *name);

#define lockdep_assert_held(lock) ((void)0)
#define rcu_access_pointer(p) (p)
#define rcu_assign_pointer(p, v) ((p) = (v))
#define le64_to_cpu(x) (x)
#define rcu_head "rcu_head"

static inline bool ieee80211_is_beacon(__le16 fc) { return false; }
static inline bool ieee80211_is_probe_resp(__le16 fc) { return false; }
static inline const struct element *ieee80211_bss_get_elem(struct cfg80211_bss *bss, int id) { return NULL; }
static inline const u8 *cfg80211_find_ie(int id, const u8 *ies, int len) { return NULL; }
static inline struct rdev *wiphy_to_rdev(struct wiphy *wiphy) { return NULL; }