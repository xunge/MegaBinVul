#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <endian.h>

#define IEEE80211_WMM_IE_AP_QOSINFO_PARAM_SET_CNT_MASK 0x0f
#define WLAN_EID_VENDOR_SPECIFIC 0xdd
#define TLV_TYPE_WMMQSTATUS 0x01
#define INFO 0
#define CMD 1

typedef uint8_t u8;
typedef uint16_t u16;

struct mwifiex_adapter;

struct mwifiex_wmm_ac_status {
    u8 disabled;
    u8 flow_required;
    u8 flow_created;
};

struct mwifiex_wmm_info {
    struct mwifiex_wmm_ac_status ac_status[4];
};

struct ieee_types_wmm_parameter {
    struct {
        u8 element_id;
        u8 len;
    } vend_hdr;
    u8 oui[3];
    u8 oui_type;
    u8 oui_subtype;
    u8 version;
    u8 qos_info_bitmap;
    u8 reserved;
    u8 ac_params[4][4];
};

struct mwifiex_bss_descriptor {
    struct ieee_types_wmm_parameter wmm_ie;
};

struct mwifiex_bss_param {
    struct mwifiex_bss_descriptor bss_descriptor;
};

struct mwifiex_private {
    struct mwifiex_adapter *adapter;
    struct mwifiex_wmm_info wmm;
    struct mwifiex_bss_param curr_bss_params;
};

struct host_cmd_ds_command_params {
    struct {
        u8 get_wmm_status[0];
    } get_wmm_status;
};

struct host_cmd_ds_command {
    u16 size;
    struct host_cmd_ds_command_params params;
};

struct mwifiex_ie_types_header {
    u16 type;
    u16 len;
};

struct mwifiex_ie_types_data {
    struct mwifiex_ie_types_header header;
    u8 data[1];
};

struct mwifiex_ie_types_wmm_queue_status {
    struct mwifiex_ie_types_header header;
    u8 queue_index;
    u8 flow_required;
    u8 disabled;
    u8 flow_created;
};

static inline uint16_t le16_to_cpu(uint16_t x) {
    return le16toh(x);
}

void mwifiex_dbg(void *adapter, int level, const char *fmt, ...);
void mwifiex_wmm_setup_queue_priorities(struct mwifiex_private *priv, 
                                      struct ieee_types_wmm_parameter *wmm_param_ie);
void mwifiex_wmm_setup_ac_downgrade(struct mwifiex_private *priv);