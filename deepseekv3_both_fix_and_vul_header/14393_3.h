#include <stdint.h>
#include <stddef.h>

typedef uint64_t guint64;
typedef int64_t gint64;
typedef unsigned int guint;
typedef int gint;
typedef int gboolean;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;
typedef struct header_field_info header_field_info;

#define ENC_VARINT_ZIGZAG 0
#define ENC_BIG_ENDIAN 0
#define _U_ 

extern int ett_kafka_record;
extern expert_field ei_kafka_bad_varint;
extern expert_field ei_kafka_bad_record_length;
extern int hf_kafka_record_attributes;
extern int hf_kafka_message_timestamp;
extern int hf_kafka_offset;
extern int hf_kafka_message_key;
extern int hf_kafka_message_value;

proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *text);
guint tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, gint64 *value, int encoding);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);
void proto_tree_add_item(proto_tree *tree, int hfi, tvbuff_t *tvb, int offset, int length, int encoding);
void proto_item_set_end(proto_item *ti, tvbuff_t *tvb, int offset);

int dissect_kafka_timestamp_delta(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int hf_index, int offset, guint64 first_timestamp);
int dissect_kafka_offset_delta(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int hf_index, int offset, guint64 base_offset);
int dissect_kafka_bytes_new(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int hf_index, int offset, void *data, void *unused, gboolean *invalid);
int dissect_kafka_record_headers(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);