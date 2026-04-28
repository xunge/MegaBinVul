#include <stdbool.h>
#include <string.h>
#include <stddef.h>

#define WLAN_EID_MESH_ID 114
#define WLAN_EID_MESH_CONFIG 113
#define IEEE80211_MESH_CONFIG_LEN 7

typedef unsigned char u8;

struct cfg80211_bss {
    const u8 *bssid;
    const u8 *information_elements;
    size_t len_information_elements;
};

static inline bool is_zero_ether_addr(const u8 *addr) {
    return !(addr[0] | addr[1] | addr[2] | addr[3] | addr[4] | addr[5]);
}

static const u8 *find_ie(int ie_id, const u8 *ies, size_t len) {
    const u8 *ie;
    for (ie = ies; ie + 2 <= ies + len; ie += ie[1] + 2) {
        if (ie[0] == ie_id)
            return ie;
    }
    return NULL;
}