#include <stdint.h>
#include <stddef.h>

#define ZBEE_TLV_HEADER_LENGTH 2
#define ZBEE_TLV_MAX_RECURSION_DEPTH 10

typedef uint32_t guint;
typedef uint8_t guint8;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct expert_field expert_field_t;

extern int proto_zbee_tlv;
extern int ett_zbee_tlv;
extern expert_field_t ei_zbee_tlv_max_recursion_depth_reached;

extern guint dissect_zbee_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, void *data, guint8 source_type, guint cmd_id);
extern unsigned p_get_proto_depth(packet_info *pinfo, int proto);
extern void p_set_proto_depth(packet_info *pinfo, int proto, unsigned depth);
extern int tvb_bytes_exist(const tvbuff_t *tvb, int offset, int length);
extern guint8 tvb_get_guint8(const tvbuff_t *tvb, int offset);
extern guint tvb_reported_length_remaining(const tvbuff_t *tvb, int offset);
extern proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, void* ptr, const char *text);
extern void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field_t *ef, tvbuff_t *tvb, int offset, int length);

#define _U_ __attribute__((unused))