#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef bool gboolean;

#define TRUE true
#define FALSE false
#define NULL ((void*)0)

#define ENC_NA 0
#define ENC_BIG_ENDIAN 0
#define ENC_LITTLE_ENDIAN 0
#define ENC_UCS_2 0
#define ENC_ASCII 0

extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
extern int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);

extern proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **tree_item, const char *text);
extern proto_tree* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **tree_item, const char *format, ...);
extern void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);
extern void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *expert, const char *format, ...);

extern const char* val_to_str(int val, const void *vals, const char *fmt);

extern const void *lltd_tlv_type_vals;
extern expert_field ei_lltd_tlv_length_invalid;
extern expert_field ei_lltd_char_reserved;
extern expert_field ei_lltd_tlv_type;
extern expert_field ei_lltd_too_many_paths;

extern int hf_lltd_tlv_type;
extern int hf_lltd_tlv_length;
extern int hf_lltd_host_id;
extern int hf_lltd_char_p;
extern int hf_lltd_char_x;
extern int hf_lltd_char_f;
extern int hf_lltd_char_m;
extern int hf_lltd_char_l;
extern int hf_lltd_char_reserved;
extern int hf_lltd_physical_medium;
extern int hf_lltd_wireless_mode;
extern int hf_lltd_bssid;
extern int hf_lltd_ssid;
extern int hf_lltd_ipv4_address;
extern int hf_lltd_ipv6_address;
extern int hf_lltd_max_operation_rate;
extern int hf_lltd_performance_count_freq;
extern int hf_lltd_link_speed;
extern int hf_lltd_rssi;
extern int hf_lltd_machine_name;
extern int hf_lltd_support_info;
extern int hf_lltd_device_uuid;
extern int hf_lltd_qos_char_e;
extern int hf_lltd_qos_char_q;
extern int hf_lltd_qos_char_p;
extern int hf_lltd_qos_char_reserved;
extern int hf_lltd_80211_physical_medium;
extern int hf_lltd_sees_list_working_set;
extern int hf_lltd_repeater_ap_lineage;

extern int ett_tlv_item;
extern int ett_characteristics;
extern int ett_qos_characteristics;
extern int ett_repeater_ap_lineage;

#define LLTD_CHARACTERISTIC_RESERVE_MASK 0
#define LLTD_QOS_CHARACTERISTIC_RESERVE_MASK 0