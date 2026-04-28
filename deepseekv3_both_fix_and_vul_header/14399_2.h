#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

#define FT_VARINT_MAX_LEN 10
#define ENC_VARINT_ZIGZAG 0
#define _U_ __attribute__((unused))

typedef uint64_t guint64;
typedef int64_t gint64;
typedef unsigned int guint;

extern expert_field ei_kafka_bad_varint;

guint tvb_get_varint(tvbuff_t *tvb, int offset, guint max_len, gint64 *val, int encoding);
proto_item *proto_tree_add_int64(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, guint len, gint64 value);
void expert_add_info(packet_info *pinfo, proto_item *pi, expert_field *expert);