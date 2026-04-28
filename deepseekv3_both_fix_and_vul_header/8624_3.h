#include <stdint.h>
#include <stddef.h>

#define OFPTT_MAX 0xfe
#define OFPFME_INITIAL 0
#define OFPFME_ADDED 1
#define OFPFME_REMOVED 2
#define OFPFME_MODIFIED 3
#define OFPFME_ABBREV 4
#define OFPFME_PAUSED 5
#define OFPFME_RESUMED 6

#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

typedef uint16_t guint16;
typedef int32_t gint32;
typedef uint8_t guint8;

typedef struct _tvbuff tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _expert_field expert_field;

extern int ett_openflow_v5_flow_update;
extern int hf_openflow_v5_flow_update_length;
extern int hf_openflow_v5_flow_update_event;
extern int hf_openflow_v5_flow_update_full_table_id;
extern int hf_openflow_v5_flow_update_full_table_id_reserved;
extern int hf_openflow_v5_flow_update_full_reason;
extern int hf_openflow_v5_flow_update_full_zero;
extern int hf_openflow_v5_flow_update_full_idle_timeout;
extern int hf_openflow_v5_flow_update_full_hard_timeout;
extern int hf_openflow_v5_flow_update_full_priority;
extern int hf_openflow_v5_flow_update_full_zeros;
extern int hf_openflow_v5_flow_update_full_cookie;
extern int hf_openflow_v5_flow_update_abbrev_xid;
extern int hf_openflow_v5_flow_update_paused_zeros;
extern expert_field ei_openflow_v5_length_too_short;
extern expert_field ei_openflow_v5_flow_update_undecoded;

guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *text);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, int encoding);
void expert_add_info(packet_info *pinfo, proto_item *ti, expert_field *expert);
void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *expert, tvbuff_t *tvb, int offset, int length, const char *format, ...);

int dissect_openflow_match_v5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length);
int dissect_openflow_instruction_v5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length);

#define _U_ __attribute__((unused))