#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    void* cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item {
    int dummy;
} proto_item;
typedef struct nstime {
    int32_t secs;
    int32_t nsecs;
} nstime_t;
typedef int gint;
typedef unsigned int guint;
typedef int gboolean;

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define WTAP_ENCAP_UNKNOWN 0
#define WTAP_ENCAP_ETHERNET 1
#define TRUE 1
#define COL_PROTOCOL 0
#define COL_INFO 1

static int hf_packet;
static int hf_timestamp;
static int hf_caplen;
static int hf_len;
static int hf_npkt;
static int ett_packet;
static gboolean decode_content;
static int linktype;
static gboolean info_added;
static void* data_handle;
static void* wtap_encap_dissector_table;
static struct {
    int dummy;
} ei_caplen_too_big;

struct eth_phdr {
    int fcs_len;
};

static void rpcap_frame_end(packet_info *pinfo) {}

static proto_item* proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding) { return NULL; }
static proto_tree* proto_item_add_subtree(proto_item *ti, int ett) { return NULL; }
static uint32_t tvb_get_ntohl(tvbuff_t *tvb, int offset) { return 0; }
static void proto_tree_add_time(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, nstime_t *ts) {}
static void proto_item_append_text(proto_item *ti, const char *format, ...) {}
static int tvb_reported_length_remaining(tvbuff_t *tvb, int offset) { return 0; }
static void expert_add_info(packet_info *pinfo, proto_item *ti, void *ei) {}
static tvbuff_t* tvb_new_subset(tvbuff_t *tvb, int offset, int length, int reported_length) { return NULL; }
static void dissector_try_uint_new(void *table, int type, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean boolean, void *phdr) {}
static void col_prepend_fence_fstr(void *cinfo, int column, const char *format) {}
static void register_frame_end_routine(packet_info *pinfo, void (*func)(packet_info *)) {}
static void call_dissector(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {}