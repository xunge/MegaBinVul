#include <stdint.h>

#define OFPMT_STANDARD 0
#define OFPMT_OXM 1

typedef uint16_t guint16;
typedef int32_t gint32;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

#define _U_ __attribute__((unused))
#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

extern int ett_openflow_v5_match;
extern int hf_openflow_v5_match_type;
extern int hf_openflow_v5_match_length;
extern int hf_openflow_v5_match_pad;
extern expert_field ei_openflow_v5_length_too_short;
extern expert_field ei_openflow_v5_match_undecoded;

extern proto_tree* proto_tree_add_subtree(proto_tree*, tvbuff_t*, int, int, int, proto_item**, const char*);
extern guint16 tvb_get_ntohs(tvbuff_t*, int);
extern proto_item* proto_tree_add_item(proto_tree*, int, tvbuff_t*, int, int, int);
extern void proto_item_set_len(proto_item*, int);
extern void expert_add_info(packet_info*, proto_item*, expert_field*);
extern void proto_tree_add_expert_format(proto_tree*, packet_info*, expert_field*, tvbuff_t*, int, int, const char*);

extern int dissect_openflow_oxm_v5(tvbuff_t*, packet_info*, proto_tree*, int, guint16);