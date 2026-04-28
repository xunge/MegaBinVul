#include <stdint.h>
#include <time.h>

typedef struct {
    time_t secs;
    int nsecs;
} nstime_t;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_info expert_info;

typedef uint64_t guint64;
typedef unsigned int guint;

#define FT_VARINT_MAX_LEN 9
#define ENC_VARINT_ZIGZAG 0
#define _U_ __attribute__((unused))

extern expert_info ei_kafka_bad_varint;

static void expert_add_info(packet_info *pinfo, proto_item *pi, expert_info *ei);
static guint tvb_get_varint(tvbuff_t *tvb, int offset, guint max_len, guint64 *val, int encoding);
static proto_item *proto_tree_add_time(proto_tree *tree, int hf_item, tvbuff_t *tvb, int offset, guint len, nstime_t *time);