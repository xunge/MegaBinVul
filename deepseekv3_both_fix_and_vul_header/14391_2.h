#include <stdint.h>
#include <stddef.h>

typedef int32_t kafka_api_version_t;
typedef int64_t gint64;
typedef int32_t gint32;

#define FT_VARINT_MAX_LEN 10
#define ENC_VARINT_PROTOBUF 0

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct expert_field expert_field;

extern expert_field ei_kafka_bad_varint;
extern expert_field ei_kafka_bad_array_length;

int dissect_kafka_array_elements(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
                               kafka_api_version_t api_version,
                               int(*func)(tvbuff_t*, packet_info*, proto_tree*, int, kafka_api_version_t),
                               int count);

int tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, gint64 *value, int encoding);
int tvb_captured_length(tvbuff_t *tvb);
void expert_add_info(packet_info *pinfo, proto_tree *tree, expert_field *expert_field);
proto_tree *proto_tree_get_parent(proto_tree *tree);