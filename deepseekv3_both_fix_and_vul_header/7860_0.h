#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_info expert_info;

#define _U_ __attribute__((unused))
#define ENC_BIG_ENDIAN 0

extern int hf_thrift_bool;
extern int hf_thrift_byte;
extern int hf_thrift_double;
extern int hf_thrift_i16;
extern int hf_thrift_i32;
extern int hf_thrift_u64;
extern int hf_thrift_i64;
extern expert_info ei_thrift_wrong_type;

static int proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
static void expert_add_info(packet_info *pinfo, proto_item *pi, expert_info *ei);
static int tvb_reported_length(tvbuff_t *tvb);

static int dissect_thrift_utf7(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int offset, int length);
static int dissect_thrift_struct(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int offset, int length);
static int dissect_thrift_map(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int offset, int length);
static int dissect_thrift_list(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int offset, int length);