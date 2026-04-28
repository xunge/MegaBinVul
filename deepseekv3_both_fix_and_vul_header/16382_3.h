#include <stdint.h>
#include <stddef.h>

#define ENC_BIG_ENDIAN 0
#define ENC_TIME_MSECS 0
#define KAFKA_MESSAGE_CODEC_MASK 0x07

typedef int8_t gint8;
typedef uint8_t guint8;
typedef uint32_t guint32;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct {
    int dummy;
} expert_field;

static int ett_kafka_message;
static int hf_kafka_offset;
static int hf_kafka_message_size;
static int hf_kafka_message_crc;
static int hf_kafka_message_magic;
static int hf_kafka_message_codec;
static int hf_kafka_message_timestamp_type;
static int hf_kafka_message_timestamp;
static int hf_kafka_message_key;
static int hf_kafka_message_value;

static expert_field ei_kafka_bad_bytes_length;

static uint32_t tvb_get_guint32(tvbuff_t *tvb, int offset, int encoding);
static void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding);
static void proto_item_set_end(proto_item *item, tvbuff_t *tvb, int offset);
static void proto_item_append_text(proto_item *item, const char *text);
static proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **item, const char *text);
static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);
static void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *description);
static void show_compression_reduction(tvbuff_t *tvb, proto_tree *tree, uint32_t orig_len, uint32_t new_len);
static uint32_t tvb_get_ntohl(tvbuff_t *tvb, int offset);
static int tvb_captured_length(tvbuff_t *tvb);
static int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);

static int dissect_kafka_int64(proto_tree *tree, int hf, tvbuff_t *tvb, packet_info *pinfo, int offset, void *data);
static int dissect_kafka_int32(proto_tree *tree, int hf, tvbuff_t *tvb, packet_info *pinfo, int offset, void *data);
static int dissect_kafka_int8(proto_tree *tree, int hf, tvbuff_t *tvb, packet_info *pinfo, int offset, void *data);
static int dissect_kafka_regular_bytes(proto_tree *tree, int hf, tvbuff_t *tvb, packet_info *pinfo, int offset, void *data, uint32_t *length);
static int decompress(tvbuff_t *tvb, packet_info *pinfo, int offset, uint32_t length, uint8_t codec, tvbuff_t **decompressed_tvb, int *decompressed_offset);
static void dissect_kafka_message_set(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int end_offset, uint8_t codec);

#define _U_ __attribute__((unused))