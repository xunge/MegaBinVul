#include <stdint.h>

#define OFPMBT_DROP 1
#define OFPMBT_DSCP_REMARK 2
#define OFPMBT_EXPERIMENTER 0xFFFF

#define _U_ __attribute__((unused))
#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

typedef uint16_t guint16;
typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern int ett_openflow_v5_meter_band;
extern int hf_openflow_v5_meter_band_type;
extern int hf_openflow_v5_meter_band_len;
extern int hf_openflow_v5_meter_band_rate;
extern int hf_openflow_v5_meter_band_burst_size;
extern int hf_openflow_v5_meter_band_drop_pad;
extern int hf_openflow_v5_meter_band_dscp_remark_prec_level;
extern int hf_openflow_v5_meter_band_dscp_remark_pad;
extern int hf_openflow_v5_meter_band_experimenter_experimenter;
extern expert_field ei_openflow_v5_length_too_short;
extern expert_field ei_openflow_v5_meter_band_undecoded;

proto_tree* proto_tree_add_subtree(proto_tree*, tvbuff_t*, int, int, int, proto_item**, const char*);
guint16 tvb_get_ntohs(tvbuff_t*, int);
proto_item* proto_tree_add_item(proto_tree*, int, tvbuff_t*, int, int, int);
void proto_item_set_len(proto_item*, guint16);
void expert_add_info(packet_info*, proto_item*, expert_field*);
void proto_tree_add_expert_format(proto_tree*, packet_info*, expert_field*, tvbuff_t*, int, int, const char*);