#include <stdint.h>
#include <stddef.h>

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _tvbuff tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _expert_field expert_field;

typedef unsigned int guint;
typedef uint64_t guint64;
typedef int gint;

extern expert_field ei_kafka_bad_varint;

#define FT_VARINT_MAX_LEN 10
#define ENC_VARINT_PROTOBUF 0
#define ENC_NA 0

/* Function prototypes */
int tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, guint64 *value, int encoding);
proto_item* proto_tree_add_item(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int length, int encoding);
void expert_add_info(packet_info *pinfo, proto_item *pi, expert_field *ef);
void proto_tree_add_bytes_with_length(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int length, const void *data, int data_length);
const void* tvb_get_ptr(tvbuff_t *tvb, int offset, int length);