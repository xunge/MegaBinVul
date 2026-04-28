#include <stdint.h>
#include <stddef.h>

typedef unsigned int guint;
typedef uint64_t guint64;
typedef int gint;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void *pool;
} packet_info;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

#define FT_VARINT_MAX_LEN 10
#define ENC_VARINT_PROTOBUF 0
#define ENC_NA 0

extern int tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, uint64_t *value, int encoding);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int length, int encoding);
extern void expert_add_info(packet_info *pinfo, proto_item *pi, expert_field *expert);
extern void proto_tree_add_string(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int length, const char *value);
extern char *kafka_tvb_get_string(void *pool, tvbuff_t *tvb, int offset, int length);

extern expert_field ei_kafka_bad_varint;