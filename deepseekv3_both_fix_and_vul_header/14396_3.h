#include <stdint.h>
#include <stdbool.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern expert_field ei_kafka_bad_varint;
extern expert_field ei_kafka_bad_array_length;
extern int ett_kafka_record_headers;

typedef int64_t gint64;
typedef unsigned int guint;
typedef bool gboolean;

#define _U_ __attribute__((unused))
#define FALSE false
#define TRUE true

enum {
    ENC_VARINT_ZIGZAG
};

int dissect_kafka_record_headers_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, gboolean *invalid);
proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *text);
guint tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, gint64 *value, int encoding);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);
void proto_item_set_end(proto_item *item, tvbuff_t *tvb, int offset);