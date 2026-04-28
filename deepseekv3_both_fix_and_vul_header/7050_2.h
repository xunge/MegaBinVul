#include <stdint.h>
#include <stddef.h>

typedef int32_t gint;
typedef uint32_t guint;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef char gchar;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff_t tvbuff_t;

#define ENC_ASCII 0

extern gint ett_rtps_topic_query_tree;
extern gint ett_rtps_topic_query_selection_tree;
extern gint ett_rtps_topic_query_filter_params_tree;

extern int hf_rtps_encapsulation_id;
extern int hf_rtps_encapsulation_options;
extern int hf_rtps_topic_query_selection_filter_class_name;
extern int hf_rtps_topic_query_selection_filter_expression;
extern int hf_rtps_topic_query_selection_num_parameters;
extern int hf_rtps_topic_query_selection_filter_parameter;
extern int hf_rtps_topic_query_topic_name;
extern int hf_rtps_topic_query_original_related_reader_guid;
extern int hf_rtps_param_host_id;
extern int hf_rtps_param_app_id;
extern int hf_rtps_param_instance_id;
extern int hf_rtps_param_entity;
extern int hf_rtps_param_entity_key;
extern int hf_rtps_param_hf_entity_kind;

#define SHORT_ALIGN_ZERO(offset, alignment_zero) \
    offset = ((offset) + 1) & ~1

#define LONG_ALIGN_ZERO(offset, alignment_zero) \
    offset = ((offset) + 3) & ~3