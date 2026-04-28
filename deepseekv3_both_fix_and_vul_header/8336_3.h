#include <stdint.h>
#include <time.h>

typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gint;
typedef int gboolean;
#define TRUE 1
#define _U_ __attribute__((unused))

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    void *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct nstime_t {
    time_t secs;
    int nsecs;
} nstime_t;

typedef struct ipmi_dissect_arg_t {
    int context;
    guint channel;
    guint flags;
} ipmi_dissect_arg_t;

#define COL_DEF_SRC 0
#define COL_PROTOCOL 1
#define COL_INFO 2

#define HPM2_TRACE_PACKET_DATA 0
#define HPM2_CHN_STATE_NOTIFY 1
#define HPM2_EMBED_ASCII_MSG 2

#define IPMI_PROTO_IPMB_1_0 0
#define IPMI_PROTO_KCS 1
#define IPMI_PROTO_SMIC 2
#define IPMI_PROTO_BT_10 3
#define IPMI_PROTO_BT_15 4
#define IPMI_E_NONE 0
#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1

extern int proto_ipmi_trace;
extern int ett_ipmi_trace;
extern int ett_trace_block_type;
extern int ett_trace_timestamp;
extern int ett_trace_protocol_data;
extern int hf_trace_block_type;
extern int hf_trace_timestamp;
extern int hf_trace_timestamp_sec;
extern int hf_trace_timestamp_msec;
extern int hf_trace_data_type;
extern int hf_trace_protocol_data;
extern int hf_trace_data_len;
extern const char* val_to_str(guint value, const void* vs, const char* fmt);
extern const void* str_protocol_types;
extern const int* bits_trace_block_type;
extern const int* bits_ipmb_protocol_data;
extern const int* bits_host_protocol_data;
extern void* proto_dissector_table;

extern guint tvb_captured_length(tvbuff_t *tvb);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
extern guint32 tvb_get_letohl(tvbuff_t *tvb, gint offset);
extern guint16 tvb_get_letohs(tvbuff_t *tvb, gint offset);
extern void tvb_memcpy(tvbuff_t *tvb, void *target, gint offset, gint length);
extern tvbuff_t *tvb_new_subset_remaining(tvbuff_t *tvb, gint offset);
extern void call_data_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
extern void col_add_fstr(void *cinfo, int column, const char *format, ...);
extern void col_set_str(void *cinfo, int column, const char *str);
extern void col_clear(void *cinfo, int column);
extern void col_add_str(void *cinfo, int column, const char *str);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
extern proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
extern proto_item *proto_tree_add_time(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const nstime_t *value_ptr);
extern void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, gint offset, int hfindex, int ett, const int *bits, int encoding);
extern gboolean dissector_try_uint_new(void *table, guint32 key, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean add_proto_name, void *data);
extern void dissect_ipmb_state_notify(tvbuff_t *tvb, proto_tree *tree);