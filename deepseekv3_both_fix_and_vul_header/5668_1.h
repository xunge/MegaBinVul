#include <stdint.h>

typedef struct _packet_info packet_info;
typedef struct _proto_tree proto_tree;
typedef struct _tvbuff_t tvbuff_t;
typedef struct _expert_field expert_field;

#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 0

typedef uint32_t guint32;
typedef uint8_t guint8;

extern int hf_ieee80211_tag_tfs_request_id;
extern int hf_ieee80211_tag_tfs_request_ac_delete_after_match;
extern int hf_ieee80211_tag_tfs_request_ac_notify;
extern int hf_ieee80211_tag_tfs_request_subelem_id;
extern int hf_ieee80211_tag_tfs_request_subelem_len;
extern int hf_ieee80211_tag_tfs_request_subelem;
extern expert_field ei_ieee80211_missing_data;
extern expert_field ei_ieee80211_tag_length;
extern expert_field ei_ieee80211_extra_data;

#define TFS_REQ_SUBELEM_TFS 0

extern int add_tagged_field(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, int ftype);