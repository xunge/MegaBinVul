#include <stdint.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

typedef int32_t kafka_api_version_t;
typedef int64_t gint64;
typedef int32_t gint32;
typedef unsigned int guint;

#define FT_VARINT_MAX_LEN 10
#define ENC_VARINT_PROTOBUF 0

extern int ett_kafka_tagged_fields;
extern expert_field ei_kafka_bad_varint;

proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **item, const char *text);
guint tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, gint64 *value, int encoding);
void expert_add_info(packet_info *pinfo, proto_tree *tree, expert_field *field);
void proto_item_set_end(proto_item *item, tvbuff_t *tvb, int offset);

int dissect_kafka_array_elements(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, kafka_api_version_t api_version,
                               void (*dissector)(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, kafka_api_version_t api_version),
                               gint32 count);
void dissect_kafka_tagged_field(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, kafka_api_version_t api_version);

#define _U_ __attribute__((unused))