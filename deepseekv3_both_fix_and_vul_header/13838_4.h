#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int32_t gint32;
typedef int32_t gint;
typedef unsigned int guint;
typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct tvbuff_t {
    // dummy structure
} tvbuff_t;

typedef struct packet_info {
    gboolean fragmented;
    struct {
        const char* info;
    } *cinfo;
} packet_info;

typedef struct proto_tree {
    // dummy structure
} proto_tree;

typedef struct proto_item {
    // dummy structure
} proto_item;

typedef struct fragment_head {
    guint32 len;
} fragment_head;

typedef struct {
    guint8 subframe1;
    guint8 subframe2;
    guint8 scm_udid[5];
    gboolean scm_udid_valid;
    struct {
        guint8 subframe1;
        guint8 subframe2;
    } frame;
    struct {
        struct {
            struct {
                gboolean toggle;
                gboolean abort_transfer;
                gboolean preload;
                gboolean read_access;
                gboolean initiate;
                gboolean segmented;
                gboolean end_segment;
            } sacmd;
        } *ssdo;
    } payload;
} opensafety_packet_info;

typedef struct {
    int dummy;
} expert_field;

typedef struct {
    int dummy;
} reassembly_table;

typedef struct {
    int dummy;
} fragment_items;

typedef struct {
    guint32 value;
    const char* str;
} value_string;

typedef struct {
    value_string* vals;
    guint32 mask;
} value_string_ext;

static const int hf_oss_ssdo_sacmd_end_segment;
static const int hf_oss_ssdo_sacmd_initiate;
static const int hf_oss_ssdo_sacmd_toggle;
static const int hf_oss_ssdo_sacmd_segmentation;
static const int hf_oss_ssdo_sacmd_abort_transfer;
static const int hf_oss_ssdo_sacmd_preload;
static const int hf_oss_ssdo_sacmd_access_type;
static const int hf_oss_ssdo_sacmd;
static const int hf_oss_ssdo_client;
static const int hf_oss_ssdo_server;
static const int hf_oss_ssdo_sano;
static const int hf_oss_ssdo_preload_queue;
static const int hf_oss_ssdo_preload_error;
static const int hf_oss_ssdo_sod_index;
static const int hf_oss_ssdo_sod_subindex;
static const int hf_oss_ssdo_abort_code;
static const int hf_oss_ssdo_payload_size;
static const int hf_oss_ssdo_payload;
static const int hf_oss_sod_par_timestamp;
static const int hf_oss_sod_par_checksum;

static const int ett_opensafety_ssdo;
static const int ett_opensafety_ssdo_sacmd;
static const int ett_opensafety_ssdo_payload;

static expert_field ei_payload_length_not_positive;
static reassembly_table os_reassembly_table;
static const fragment_items oss_frag_items;

static const value_string opensafety_ssdo_sacmd_values[] = {
    {0, NULL}
};

static const value_string_ext opensafety_sod_idx_names_ext = {NULL, 0};
static const value_string_ext opensafety_abort_codes_ext = {NULL, 0};

#define OPENSAFETY_SSDO_SACMD_TGL   0x01
#define OPENSAFETY_SSDO_SACMD_ABRT  0x02
#define OPENSAFETY_SSDO_SACMD_PRLD  0x04
#define OPENSAFETY_SSDO_DOWNLOAD    0x08
#define OPENSAFETY_SSDO_SACMD_INI   0x10
#define OPENSAFETY_SSDO_SACMD_SEG   0x20
#define OPENSAFETY_SSDO_SACMD_ENSG  0x40

#define OPENSAFETY_SOD_DVI          0x101A

#define OSS_FRAME_POS_LEN           0
#define OSS_FRAME_POS_DATA          1
#define COL_INFO 0
#define ENC_NA 0

#define OSS_FRAME_ID_T(tvb, offset) 0
#define OSS_FRAME_ADDR_T(tvb, offset) 0
#define OSS_FRAME_ADDR_T2(tvb, offset, a, b) 0

static guint8 tvb_get_guint8(tvbuff_t* tvb, guint offset) { return 0; }
static guint16 tvb_get_letohs(tvbuff_t* tvb, guint offset) { return 0; }
static guint32 tvb_get_letohl(tvbuff_t* tvb, guint offset) { return 0; }

static const char* val_to_str_const(guint8 val, const value_string* table, const char* default_str) { return ""; }
static const char* val_to_str_ext_const(guint32 val, const value_string_ext* table, const char* default_str) { return ""; }

static void opensafety_packet_sendreceiv(tvbuff_t*, packet_info*, proto_tree*, proto_item*, opensafety_packet_info*, guint16, guint8, guint8, guint8, guint8, guint16) {}
static void opensafety_packet_sender(tvbuff_t*, packet_info*, proto_tree*, proto_item*, opensafety_packet_info*, guint8, guint8, guint8, gint32) {}
static void opensafety_packet_receiver(tvbuff_t*, packet_info*, proto_tree*, proto_item*, opensafety_packet_info*, guint8, guint8, guint8, gint32) {}
static proto_tree* opensafety_packet_payloadtree(tvbuff_t*, proto_tree*, opensafety_packet_info*, int) { return NULL; }
static void opensafety_packet_response(tvbuff_t*, proto_tree*, opensafety_packet_info*, gboolean) {}
static void opensafety_packet_node(tvbuff_t*, packet_info*, proto_tree*, int, guint8, guint8, guint8, guint16) {}
static void dissect_opensafety_ssdo_payload(packet_info*, tvbuff_t*, proto_tree*, guint8) {}

static void proto_tree_add_bitmask(proto_tree*, tvbuff_t*, guint, int, int, const int**, int) {}
static proto_item* proto_tree_add_uint(proto_tree*, int, tvbuff_t*, guint, guint, guint) { return NULL; }
static proto_item* proto_tree_add_uint_format_value(proto_tree*, int, tvbuff_t*, guint, guint, guint, const char*, ...) { return NULL; }
static proto_item* proto_tree_add_item(proto_tree*, int, tvbuff_t*, guint, guint, int) { return NULL; }
static void proto_item_append_text(proto_item*, const char*) {}
static proto_item* proto_tree_add_bytes_format_value(proto_tree*, int, tvbuff_t*, guint, guint, void*, const char*) { return NULL; }
static proto_tree* proto_item_add_subtree(proto_item*, int) { return NULL; }
static void PROTO_ITEM_SET_GENERATED(proto_item*) {}
static void expert_add_info_format(packet_info*, proto_item*, expert_field*, const char*, ...) {}
static void col_append_fstr(packet_info*, int, const char*, ...) {}
static void col_append_str(packet_info*, int, const char*) {}

static fragment_head* fragment_add_seq_check(reassembly_table*, tvbuff_t*, guint, packet_info*, guint32, void*, guint, guint, gboolean) { return NULL; }
static void fragment_add_seq_offset(reassembly_table*, packet_info*, guint32, void*, guint) {}
static tvbuff_t* process_reassembled_data(tvbuff_t*, guint, packet_info*, const char*, fragment_head*, const fragment_items*, void*, proto_tree*) { return NULL; }