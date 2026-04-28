#include <stdint.h>
#include <stddef.h>

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

typedef uint64_t guint64;
typedef int32_t gint32;
typedef int32_t gint;

#define FT_VARINT_MAX_LEN 10
#define ENC_VARINT_PROTOBUF 0
#define ENC_NA 0

extern expert_field ei_kafka_bad_varint;

int tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, guint64 *value, int encoding);
proto_item* proto_tree_add_item(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int length, int encoding);
void expert_add_info(packet_info *pinfo, proto_item *pi, expert_field *ef);