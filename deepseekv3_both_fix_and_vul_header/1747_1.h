#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct cfg80211_bss {
    struct list_head nontrans_list;
    unsigned char bssid[6];
};

struct element {
    unsigned char *data;
    unsigned char datalen;
};

#define WLAN_EID_SSID 0
#define EINVAL 22

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (head); pos = pos->member.next)

static inline void list_add_tail(struct list_head *new, struct list_head *head) {}

static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}

static inline const struct element *ieee80211_bss_get_elem(struct cfg80211_bss *bss, int id) { return NULL; }
static inline int is_bss(struct cfg80211_bss *bss, const unsigned char *bssid, const unsigned char *data, unsigned char len) { return 0; }