#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    void* cinfo;
    void* pool;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct gquic_info_data {
    int encoding;
    int version;
    int version_valid;
} gquic_info_data_t;

#define ENC_NA 0
#define ENC_VARINT_QUIC 0
#define ENC_ASCII 0

#define FTFLAGS_SPECIAL 0
#define FT_CRYPTO 1
#define FT_PADDING 2
#define FT_RST_STREAM 3
#define FT_CONNECTION_CLOSE 4
#define FT_GOAWAY 5
#define FT_WINDOW_UPDATE 6
#define FT_BLOCKED 7
#define FT_STOP_WAITING 8
#define FT_PING 9
#define FTFLAGS_STREAM 0x10
#define FTFLAGS_STREAM_D 0x20
#define FTFLAGS_ACK 0x40
#define FTFLAGS_ACK_N 0x80
#define FTFLAGS_ACK_T 0x100
#define FTFLAGS_ACK_U 0x200
#define FTFLAGS_ACK_LL 0x400
#define FTFLAGS_ACK_MM 0x800

#define COL_INFO 0
#define TRUE 1
#define FALSE 0

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint32_t guint;
typedef uint64_t guint64;
typedef int32_t gint32;

struct value_string {
    guint32 value;
    const char* strptr;
};

struct value_string_ext {
    struct value_string *values;
    const char *name;
    guint32 mask;
    guint32 min;
    guint32 max;
};

extern const struct value_string frame_type_vals[];
extern const struct value_string_ext rststream_error_code_vals_ext;
extern const struct value_string_ext error_code_vals_ext;
extern const struct value_string message_tag_vals[];

extern proto_item* proto_tree_add_item(proto_tree*, int, tvbuff_t*, int, int, int);
extern proto_item* proto_tree_add_item_ret_uint(proto_tree*, int, tvbuff_t*, int, int, int, guint32*);
extern proto_item* proto_tree_add_item_ret_varint(proto_tree*, int, tvbuff_t*, int, int, int, guint64*, gint32*);
extern proto_item* proto_tree_add_item_ret_string(proto_tree*, int, tvbuff_t*, int, int, int, void*, const char**);
extern proto_item* proto_tree_add_uint(proto_tree*, int, tvbuff_t*, int, int, guint32);
extern proto_tree* proto_item_add_subtree(proto_item*, int);
extern void proto_item_set_text(proto_item*, const char*, ...);
extern void proto_item_set_generated(proto_item*);
extern void proto_item_append_text(proto_item*, const char*, ...);
extern guint8 tvb_get_guint8(tvbuff_t*, int);
extern guint16 tvb_get_guint16(tvbuff_t*, int, int);
extern guint32 tvb_get_ntohl(tvbuff_t*, int);
extern int tvb_reported_length_remaining(tvbuff_t*, int);
extern tvbuff_t* tvb_new_subset_length(tvbuff_t*, int, int);
extern tvbuff_t* tvb_new_subset_remaining(tvbuff_t*, int);
extern void expert_add_info(packet_info*, proto_tree*, int*);
extern void col_set_str(packet_info*, int, const char*);
extern void col_add_str(packet_info*, int, const char*);
extern void col_append_fstr(packet_info*, int, const char*, ...);
extern void col_add_fstr(packet_info*, int, const char*, ...);
extern void col_set_writable(packet_info*, int, int);
extern void call_dissector_with_data(void*, tvbuff_t*, packet_info*, proto_tree*, void*);
extern int dissect_gquic_tags(tvbuff_t*, packet_info*, proto_tree*, int);
extern int dissect_http2_pdu(tvbuff_t*, packet_info*, proto_tree*, void*);
extern void* tls13_handshake_handle;

#define DISSECTOR_ASSERT(expr) ((void)0)
#define GUINT_TO_POINTER(u) ((void*)(uintptr_t)(u))

extern int hf_gquic_frame;
extern int hf_gquic_frame_type;
extern int hf_gquic_frame_type_padding_length;
extern int hf_gquic_frame_type_padding;
extern int hf_gquic_frame_type_rsts_stream_id;
extern int hf_gquic_frame_type_rsts_byte_offset;
extern int hf_gquic_frame_type_rsts_error_code;
extern int hf_gquic_frame_type_cc_error_code;
extern int hf_gquic_frame_type_cc_reason_phrase_length;
extern int hf_gquic_frame_type_cc_reason_phrase;
extern int hf_gquic_frame_type_goaway_error_code;
extern int hf_gquic_frame_type_goaway_last_good_stream_id;
extern int hf_gquic_frame_type_goaway_reason_phrase_length;
extern int hf_gquic_frame_type_goaway_reason_phrase;
extern int hf_gquic_frame_type_wu_stream_id;
extern int hf_gquic_frame_type_wu_byte_offset;
extern int hf_gquic_frame_type_blocked_stream_id;
extern int hf_gquic_frame_type_sw_send_entropy;
extern int hf_gquic_frame_type_sw_least_unacked_delta;
extern int hf_gquic_crypto_offset;
extern int hf_gquic_crypto_length;
extern int hf_gquic_crypto_crypto_data;
extern int hf_gquic_tag;
extern int hf_gquic_frame_type_stream;
extern int hf_gquic_frame_type_stream_f;
extern int hf_gquic_frame_type_stream_d;
extern int hf_gquic_frame_type_stream_ooo;
extern int hf_gquic_frame_type_stream_ss;
extern int hf_gquic_stream_id;
extern int hf_gquic_offset;
extern int hf_gquic_data_len;
extern int hf_gquic_stream_data;
extern int hf_gquic_frame_type_ack;
extern int hf_gquic_frame_type_ack_n;
extern int hf_gquic_frame_type_ack_t;
extern int hf_gquic_frame_type_ack_u;
extern int hf_gquic_frame_type_ack_ll;
extern int hf_gquic_frame_type_ack_mm;
extern int hf_gquic_frame_type_ack_received_entropy;
extern int hf_gquic_frame_type_ack_largest_observed;
extern int hf_gquic_frame_type_ack_ack_delay_time;
extern int hf_gquic_frame_type_ack_num_timestamp;
extern int hf_gquic_frame_type_ack_delta_largest_observed;
extern int hf_gquic_frame_type_ack_first_timestamp;
extern int hf_gquic_frame_type_ack_time_since_previous_timestamp;
extern int hf_gquic_frame_type_ack_num_ranges;
extern int hf_gquic_frame_type_ack_missing_packet;
extern int hf_gquic_frame_type_ack_range_length;
extern int hf_gquic_frame_type_ack_num_revived;
extern int hf_gquic_frame_type_ack_revived_packet;
extern int hf_gquic_frame_type_ack_largest_acked;
extern int hf_gquic_frame_type_ack_largest_acked_delta_time;
extern int hf_gquic_frame_type_ack_num_blocks;
extern int hf_gquic_frame_type_ack_first_ack_block_length;
extern int hf_gquic_frame_type_ack_gap_to_next_block;
extern int hf_gquic_frame_type_ack_ack_block_length;
extern int hf_gquic_frame_type_ack_time_since_largest_acked;
extern int hf_gquic_frame_type_ack_delta_largest_acked;

extern int ett_gquic_ft;
extern int ett_gquic_ftflags;

extern int ei_gquic_data_invalid;

extern const char* rval_to_str(guint8, const struct value_string*, const char*);
extern const char* val_to_str_ext(guint32, const struct value_string_ext*, const char*);
extern const char* val_to_str(guint32, const struct value_string*, const char*);

static inline guint32 get_len_offset(guint8 frame_type) { return 0; }
static inline guint32 get_len_stream(guint8 frame_type) { return 0; }
static inline guint32 get_len_largest_observed(guint8 frame_type) { return 0; }
static inline guint32 get_len_missing_packet(guint8 frame_type) { return 0; }