#include <stdint.h>

#define TFS_RESP_SUBELEM_TFS_STATUS 1
#define TFS_RESP_SUBELEM_TFS 2
#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 1

typedef uint8_t guint8;
typedef uint32_t guint32;

typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct expert_field expert_field;

extern int hf_ieee80211_tag_tfs_response_subelem_id;
extern int hf_ieee80211_tag_tfs_response_subelem_len;
extern int hf_ieee80211_tag_tfs_response_status;
extern int hf_ieee80211_tag_tfs_response_id;
extern int hf_ieee80211_tag_tfs_response_subelem;
extern expert_field ei_ieee80211_tag_length;
extern expert_field ei_ieee80211_extra_data;

guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void expert_add_info_format(packet_info *pinfo, proto_tree *tree, expert_field *ei, const char *fmt, ...);
void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ei, tvbuff_t *tvb, int start, int length, const char *fmt, ...);
int add_tagged_field(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, int ftype);