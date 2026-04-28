#include <stdint.h>
#include <stddef.h>

typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct expert_field expert_field;

typedef uint8_t guint8;
typedef uint32_t guint32;

#define TAG_VENDOR_SPECIFIC_IE 0
#define TFS_REQ_SUBELEM_TFS 0
#define G_N_ELEMENTS(arr) (sizeof(arr)/sizeof(arr[0]))
#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 0

extern int hf_ieee80211_tag_tfs_request_id;
extern int hf_ieee80211_tag_tfs_request_ac_delete_after_match;
extern int hf_ieee80211_tag_tfs_request_ac_notify;
extern int hf_ieee80211_tag_tfs_request_subelem_id;
extern int hf_ieee80211_tag_tfs_request_subelem_len;
extern int hf_ieee80211_tag_tfs_request_subelem;
extern expert_field ei_ieee80211_missing_data;
extern expert_field ei_ieee80211_tag_length;
extern expert_field ei_ieee80211_extra_data;

int proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void expert_add_info_format(packet_info *pinfo, proto_tree *tree, expert_field *ei, const char *format, ...);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
int add_tagged_field(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, int ftype, ...);
void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ei, tvbuff_t *tvb, int offset, int length, const char *format, ...);