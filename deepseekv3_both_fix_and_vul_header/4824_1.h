#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define WILC_INVALID_CHANNEL 0
#define IEEE80211_P2P_ATTR_CHANNEL_LIST 0
#define IEEE80211_P2P_ATTR_OPER_CHANNEL 0
#define WILC_WLAN_OPERATING_CLASS_2_4GHZ 0

struct wilc_attr_entry {
    u8 attr_type;
    u16 attr_len;
};

struct wilc_attr_ch_list {
    u16 attr_len;
    u8 elem[];
};

struct wilc_attr_oper_ch {
    u8 op_class;
    u8 op_channel;
};

struct wilc_ch_list_elem {
    u8 op_class;
    u8 no_of_channels;
    u8 ch_list[];
};

static inline u16 le16_to_cpu(u16 val) {
    return val;
}