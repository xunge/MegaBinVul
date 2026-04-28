#include <stdint.h>

typedef struct _tvbuff tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _proto_tree proto_tree;
typedef struct _expert_field_info expert_field_info;

#define _U_ __attribute__((unused))
typedef uint8_t guint8;

extern expert_field_info ei_ieee80211_bad_length;
extern int hf_ieee80211_wfa_ie_owe_bssid;
extern int hf_ieee80211_wfa_ie_owe_ssid_length;
extern int hf_ieee80211_wfa_ie_owe_ssid;
extern int hf_ieee80211_wfa_ie_owe_band_info;
extern int hf_ieee80211_wfa_ie_owe_channel_info;

#define ENC_NA 0
#define ENC_ASCII 0

static int tvb_captured_length(tvbuff_t *tvb) { return 0; }
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding) {}
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, uint32_t value) {}
void expert_add_info(packet_info *pinfo, proto_tree *tree, expert_field_info *expert_info) {}