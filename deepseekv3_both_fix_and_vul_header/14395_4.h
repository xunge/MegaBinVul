#include <stdint.h>
#include <stddef.h>

typedef int64_t gint64;
typedef unsigned int guint;
typedef int gint;
typedef unsigned char gboolean;

#define FALSE 0
#define TRUE 1

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_info expert_info;

#define _U_ __attribute__((unused))

extern int ei_kafka_bad_varint;
extern int ei_kafka_bad_bytes_length;

#define ENC_VARINT_ZIGZAG 0
#define ENC_NA 0

/* Function prototypes */
guint tvb_get_varint(tvbuff_t *tvb, int offset, int max_len, gint64 *val, int encoding);
proto_item* proto_tree_add_bytes_format_value(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int len, const void *data, const char *format);
void expert_add_info(packet_info *pinfo, proto_item *pi, int *expert_info);
void proto_tree_add_item(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, int len, int encoding);