#include <stdint.h>
#include <stddef.h>

#define MAX_ARRAY_LEN 1048576
#define COL_INFO 0

#define ENC_ASCII 0x01
#define ENC_UTF_8 0x02
#define ENC_NA 0x04

enum {
    ARG_INVALID,
    ARG_ARRAY,
    ARG_BOOLEAN,
    ARG_DOUBLE,
    ARG_SIGNATURE,
    ARG_HANDLE,
    ARG_INT32,
    ARG_INT16,
    ARG_OBJ_PATH,
    ARG_UINT16,
    ARG_STRING,
    ARG_UINT64,
    ARG_UINT32,
    ARG_VARIANT,
    ARG_INT64,
    ARG_BYTE,
    ARG_DICT_ENTRY,
    ARG_STRUCT
};

enum {
    HDR_INVALID,
    HDR_SIGNATURE,
    HDR_MEMBER
};

typedef int32_t gint;
typedef uint32_t guint;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int gboolean;
typedef char gchar;

typedef struct tvbuff_t {
    // dummy structure
} tvbuff_t;

typedef struct packet_info {
    struct {
        int cinfo;
    } *cinfo;
} packet_info;

typedef struct proto_item {
    // dummy structure
} proto_item;

typedef struct proto_tree {
    // dummy structure
} proto_tree;

typedef struct expert_field {
    // dummy structure
} expert_field;

typedef struct wmem_allocator_t {
    // dummy structure
} wmem_allocator_t;

static int ett_alljoyn_mess_body_parameters;
static int hf_alljoyn_mess_body_array;
static int hf_alljoyn_boolean;
static int hf_alljoyn_double;
static int hf_alljoyn_mess_body_signature_length;
static int hf_alljoyn_mess_body_signature;
static int hf_alljoyn_handle;
static int hf_alljoyn_int32;
static int hf_alljoyn_int16;
static int hf_alljoyn_uint32;
static int hf_alljoyn_string_data;
static int hf_alljoyn_uint16;
static int hf_alljoyn_string_size_32bit;
static int hf_alljoyn_uint64;
static int hf_alljoyn_mess_body_variant;
static int hf_alljoyn_int64;
static int hf_alljoyn_uint8;
static int hf_alljoyn_mess_body_structure;
static int hf_alljoyn_mess_body_dictionary_entry;

static expert_field ei_alljoyn_empty_arg;

static gint round_to_8byte(gint offset, gint field_starting_offset);
static gint round_to_4byte(gint offset, gint field_starting_offset);
static gint round_to_2byte(gint offset, gint field_starting_offset);
static guint32 get_uint32(tvbuff_t *tvb, gint offset, guint encoding);
static void add_padding_item(gint padding_start, gint offset, tvbuff_t *tvb, proto_tree *tree);
static gint pad_according_to_type(gint offset, gint field_starting_offset, gint packet_length, guint8 type_id);
static void advance_to_end_of_signature(guint8 **signature, guint8 *remaining_sig_length);
static void append_struct_signature(proto_item *item, guint8 *signature, guint8 signature_length, guint8 type_stop);
static gint tvb_reported_length(tvbuff_t *tvb);
static gint tvb_reported_length_remaining(tvbuff_t *tvb, gint offset);
static void col_add_fstr(void *cinfo, int col_info, const char *fmt, ...);
static void col_append_fstr(void *cinfo, int col_info, const char *fmt, ...);
static proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, gint offset, gint length, guint encoding);
static proto_tree *proto_item_add_subtree(proto_item *item, int ett);
static void proto_item_append_text(proto_item *item, const char *fmt, ...);
static void proto_item_set_text(proto_item *item, const char *fmt, ...);
static void proto_item_set_end(proto_item *item, tvbuff_t *tvb, gint offset);
static guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
static char *tvb_get_string_enc(wmem_allocator_t *alloc, tvbuff_t *tvb, gint offset, gint length, guint encoding);
static wmem_allocator_t *wmem_packet_scope(void);
static void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, gint offset, gint length);