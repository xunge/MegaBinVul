#include <stdint.h>
#include <stddef.h>

typedef int64_t gint64;
typedef unsigned int guint;
typedef int gint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern expert_field ei_kafka_bad_varint;
extern expert_field ei_kafka_bad_string_length;

#define ENC_VARINT_ZIGZAG 0
#define ENC_UTF_8 0
#define _U_ __attribute__((unused))

extern guint tvb_get_varint(tvbuff_t *tvb, int offset, int size, gint64 *val, int encoding);
extern proto_item *proto_tree_add_string_format_value(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int len, const char *str, const char *format);
extern void expert_add_info(packet_info *pinfo, proto_item *pi, expert_field *expert);
extern void proto_tree_add_item(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int len, int encoding);