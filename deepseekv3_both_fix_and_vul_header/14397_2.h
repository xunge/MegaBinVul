#include <stdint.h>
#include <stddef.h>

typedef int64_t gint64;
typedef unsigned int guint;
typedef struct _proto_tree proto_tree;
typedef struct _tvbuff_t tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _proto_item proto_item;
typedef struct _expert_field expert_field;

extern expert_field ei_kafka_bad_varint;
#define FT_VARINT_MAX_LEN 10
#define ENC_VARINT_ZIGZAG 0

guint tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, gint64 *value, int encoding);
proto_item *proto_tree_add_int64(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int len, gint64 value);
void expert_add_info(packet_info *pinfo, proto_item *pi, expert_field *expert);