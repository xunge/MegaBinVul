#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define G_MAXUINT16 65535
#define G_GINT64_MODIFIER "ll"

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef int gint;
typedef bool gboolean;

typedef struct {
    guint32 secs;
    guint32 nsecs;
} nstime_t;

typedef struct {
    int type;
    int len;
} address;

typedef struct {
    char* str;
    size_t len;
    const char* (*get_str)(void*);
    size_t (*get_len)(void*);
    void (*append_printf)(void*, const char*, ...);
} wmem_strbuf_t;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct packet_info {
    void* cinfo;
    gboolean fragmented;
} packet_info;
typedef struct tvbuff_t {
    const guint8* data;
    guint32 length;
    guint32 reported_length;
    guint8 (*get_guint8)(const struct tvbuff_t*, gint);
    guint16 (*get_ntohs)(const struct tvbuff_t*, gint);
    guint32 (*get_ntohl)(const struct tvbuff_t*, gint);
    guint64 (*get_ntoh64)(const struct tvbuff_t*, gint);
    guint32 (*captured_length)(const struct tvbuff_t*);
    guint32 (*reported_length_remaining)(const struct tvbuff_t*, gint);
    guint8* (*memdup)(void*, const struct tvbuff_t*, gint, gint);
} tvbuff_t;

typedef struct expert_field {
    int ei;
    const char* name;
} expert_field;

typedef struct fragment_head {
    guint32 id;
    guint32 fragment_offset;
    guint32 fragment_len;
    struct fragment_head* next;
} fragment_head;

typedef struct fragment_items {
    int* ett;
    int* hf_fragments;
    int* hf_fragment;
} fragment_items;

static int proto_p_mul = -1;
static gboolean use_relative_msgid = FALSE;
static guint32 message_id_offset = 0;
static gboolean use_seq_ack_analysis = FALSE;
static gboolean p_mul_reassemble = FALSE;

enum {
    Data_PDU,
    Ack_PDU,
    Address_PDU,
    Discard_Message_PDU,
    Extra_Address_PDU,
    FEC_Address_PDU,
    Extra_FEC_Address_PDU,
    Announce_PDU,
    Request_PDU,
    Reject_PDU,
    Release_PDU,
    Ack_Ack_PDU
};

enum {
    COL_PROTOCOL,
    COL_INFO
};

enum {
    ENC_NA,
    ENC_BIG_ENDIAN
};

enum {
    AT_IPv4
};

static int ett_p_mul = -1;
static int ett_pdu_type = -1;
static int ett_checksum = -1;
static int ett_dest_entry = -1;
static int ett_ack_entry = -1;
static int ett_range_entry = -1;

static int hf_length = -1;
static int hf_priority = -1;
static int hf_unused8 = -1;
static int hf_pdu_type = -1;
static int hf_map_first = -1;
static int hf_map_last = -1;
static int hf_map_unused = -1;
static int hf_pdu_type_value = -1;
static int hf_no_pdus = -1;
static int hf_seq_no = -1;
static int hf_count_of_dest = -1;
static int hf_unused16 = -1;
static int hf_checksum = -1;
static int hf_checksum_good = -1;
static int hf_checksum_bad = -1;
static int hf_source_id_ack = -1;
static int hf_ack_count = -1;
static int hf_source_id = -1;
static int hf_message_id = -1;
static int hf_expiry_time = -1;
static int hf_fec_len = -1;
static int hf_fec_id = -1;
static int hf_fec_parameters = -1;
static int hf_length_of_res = -1;
static int hf_dest_entry = -1;
static int hf_dest_id = -1;
static int hf_msg_seq_no = -1;
static int hf_sym_key = -1;
static int hf_data_fragment = -1;
static int hf_ack_entry = -1;
static int hf_ack_length = -1;
static int hf_miss_seq_range = -1;
static int hf_miss_seq_no = -1;
static int hf_timestamp_option = -1;
static int hf_tot_miss_seq_no = -1;
static int hf_ann_mc_group = -1;
static int hf_mc_group = -1;

static expert_field ei_message_discarded;
static expert_field ei_checksum_bad;
static expert_field ei_ack_length;
static expert_field ei_miss_seq_range;
static expert_field ei_miss_seq_no;
static expert_field ei_tot_miss_seq_no;
static expert_field ei_length;
static expert_field ei_more_data;
static expert_field ei_illegal_seq_no;

static fragment_items p_mul_frag_items = {
    &ett_p_mul,
    NULL,
    NULL
};

static fragment_head p_mul_reassembly_table;

#define _U_ __attribute__((unused))

static const char* get_type(int pdu_type);
static void set_address_tvb(address* addr, int type, int len, tvbuff_t* tvb, int offset);
static guint16 ip_checksum(const guint8* data, guint32 len);
static guint16 checksum_acp142(const guint8* data, guint32 len, guint32 offset);
static void add_ack_analysis(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int offset, int pdu_type, address* src, address* dst, guint32 message_id, int no_missing);
static void add_seq_analysis(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, address* src, int offset, int pdu_type, guint32 message_id, guint16 seq_no, int tot_no_missing);
static void fragment_start_seq_check(fragment_head* table, packet_info* pinfo, guint32 id, void* data, guint32 tot_len);
static fragment_head* fragment_add_seq_check(fragment_head* table, tvbuff_t* tvb, int offset, packet_info* pinfo, guint32 id, void* data, guint32 frag_number, guint32 frag_data_len, gboolean more_frags);
static tvbuff_t* process_reassembled_data(tvbuff_t* tvb, int offset, packet_info* pinfo, const char* name, fragment_head* fd_head, fragment_items* fit, proto_tree* tree, proto_item* item);
static void dissect_reassembled_data(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree);
static const char* plurality(int count, const char* singular, const char* plural);
static void* wmem_packet_scope(void);
static wmem_strbuf_t* wmem_strbuf_new_label(void* scope);
static void wmem_strbuf_append_printf(wmem_strbuf_t* buf, const char* format, ...);
static const char* wmem_strbuf_get_str(const wmem_strbuf_t* buf);
static size_t wmem_strbuf_get_len(const wmem_strbuf_t* buf);
static guint8* tvb_memdup(void* scope, const tvbuff_t* tvb, gint offset, gint length);
static guint32 tvb_captured_length(const tvbuff_t* tvb);
static guint32 tvb_reported_length_remaining(const tvbuff_t* tvb, gint offset);
static guint32 tvb_captured_length_remaining(const tvbuff_t* tvb, gint offset);
static guint8 tvb_get_guint8(const tvbuff_t* tvb, gint offset);
static guint16 tvb_get_ntohs(const tvbuff_t* tvb, gint offset);
static guint32 tvb_get_ntohl(const tvbuff_t* tvb, gint offset);
static guint64 tvb_get_ntoh64(const tvbuff_t* tvb, gint offset);
static void col_set_str(void* cinfo, int column, const char* str);
static void col_clear(void* cinfo, int column);
static void col_append_str(void* cinfo, int column, const char* str);
static void col_append_fstr(void* cinfo, int column, const char* format, ...);
static proto_item* proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, int encoding);
static proto_item* proto_tree_add_uint(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, guint32 value);
static proto_item* proto_tree_add_uint_format(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, guint32 value, const char* format, ...);
static proto_item* proto_tree_add_uint_format_value(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, guint32 value, const char* format, ...);
static proto_item* proto_tree_add_uint64_format_value(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, guint64 value, const char* format, ...);
static proto_item* proto_tree_add_boolean(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, gboolean value);
static proto_item* proto_tree_add_bytes_format_value(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, const guint8* value_ptr, const char* format, ...);
static proto_item* proto_tree_add_none_format(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, const char* format, ...);
static proto_item* proto_tree_add_time(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, const nstime_t* value_ptr);
static proto_tree* proto_item_add_subtree(proto_item* item, int tree_type);
static void proto_item_append_text(proto_item* item, const char* format, ...);
static void proto_item_set_len(proto_item* item, int length);
static void expert_add_info(packet_info* pinfo, proto_item* item, expert_field* ef);
static void expert_add_info_format(packet_info* pinfo, proto_item* item, expert_field* ef, const char* format, ...);
#define PROTO_ITEM_SET_GENERATED(pi)