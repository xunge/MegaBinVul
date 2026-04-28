#include <stdint.h>
#include <stddef.h>

typedef struct _tvbuff tvbuff_t;
typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _packet_info packet_info;
typedef struct _expert_field expert_field;

#define FT_VARINT_MAX_LEN 10
#define ENC_VARINT_PROTOBUF 0

typedef uint64_t guint64;
typedef unsigned int guint;

extern guint tvb_get_varint(tvbuff_t *tvb, int offset, guint max_len, guint64 *value, int encoding);
extern proto_item *proto_tree_add_uint64(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, guint len, guint64 value);
extern void expert_add_info(packet_info *pinfo, proto_item *pi, expert_field *expert);

extern expert_field ei_kafka_bad_varint;