#include <stddef.h>

struct cfg80211_bss {
    struct cfg80211_bss *hidden_beacon_bss;
    struct cfg80211_bss *transmitted_bss;
};

struct cfg80211_internal_bss {
    struct cfg80211_bss pub;
    int refcount;
};

struct cfg80211_registered_device {
    int bss_lock;
};

#define lockdep_assert_held(lock) ((void)0)
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
static inline struct cfg80211_internal_bss *bss_from_pub(struct cfg80211_bss *pub) {
    return container_of(pub, struct cfg80211_internal_bss, pub);
}