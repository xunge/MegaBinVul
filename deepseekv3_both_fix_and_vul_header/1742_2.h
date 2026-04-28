#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t u8;
typedef uint32_t u32;

struct ieee802_11_elems {
    const u8 *ie_start;
    size_t total_len;
    size_t scratch_len;
    u8 *scratch_pos;
    u8 *scratch;
    u32 crc;
    int parse_error;
    const struct ieee80211_tim_ie *tim;
    u8 dtim_period;
    u8 dtim_count;
    const struct ieee80211_bssid_index *bssid_index;
    size_t bssid_index_len;
};

struct ieee80211_elems_parse_params {
    const u8 *start;
    size_t len;
    int action;
    u8 link_id;
    const u8 *bss;
};

struct element {
    u8 id;
    u8 datalen;
    u8 data[];
};

struct ieee80211_tim_ie {
    u8 dtim_count;
    u8 dtim_period;
    u8 bitmap_control;
    u8 virtual_map[];
};

struct ieee80211_bssid_index {
    u8 dtim_period;
    u8 dtim_count;
};

#define GFP_ATOMIC 0
#define WLAN_EID_EXT_NON_INHERITANCE 0

#define offsetofend(TYPE, MEMBER) (offsetof(TYPE, MEMBER) + sizeof(((TYPE *)0)->MEMBER))

void *kzalloc(size_t size, int flags);
int ieee802_11_find_bssid_profile(const u8 *start, size_t len,
                                struct ieee802_11_elems *elems,
                                const u8 *bss, u8 *profile);
u32 _ieee802_11_parse_elems_full(struct ieee80211_elems_parse_params *params,
                               struct ieee802_11_elems *elems,
                               const struct element *non_inherit);
const struct element *cfg80211_find_ext_elem(u8 id, const u8 *ies, size_t len);