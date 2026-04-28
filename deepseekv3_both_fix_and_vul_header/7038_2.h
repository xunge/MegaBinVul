#include <stdint.h>
#include <stddef.h>

#define PID_LIST_END 0x00000001

typedef struct type_mapping {
    uint64_t type_id;
} type_mapping;

extern int ett_rtps_type_object;
extern struct expert_field ei_rtps_parameter_value_invalid;

typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct tvbuff_t tvbuff_t;
typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;
typedef uint64_t guint64;

proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, gint offset, guint32 size, int ett, void* null, const char* name);
void expert_add_info_format(packet_info *pinfo, proto_tree *tree, struct expert_field *field, const char *format);
uint32_t tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding);

void rtps_util_dissect_parameter_header(tvbuff_t *tvb, gint *offset, guint encoding, guint32 *member_id, guint32 *member_length);
void rtps_util_add_type_library(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, gint offset, guint encoding, guint32 size);
void rtps_util_add_type_id(proto_tree *tree, tvbuff_t *tvb, gint offset, guint encoding, gint parent_offset, gint hf_index, const char *label, guint64 *type_id);