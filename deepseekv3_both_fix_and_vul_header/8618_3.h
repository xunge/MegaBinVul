#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define ARG_INVALID 0
#define ARG_ARRAY 1
#define ARG_BOOLEAN 2
#define ARG_DOUBLE 3
#define ARG_SIGNATURE 4
#define ARG_HANDLE 5
#define ARG_INT32 6
#define ARG_INT16 7
#define ARG_OBJ_PATH 8
#define ARG_UINT16 9
#define ARG_STRING 10
#define ARG_UINT64 11
#define ARG_UINT32 12
#define ARG_VARIANT 13
#define ARG_INT64 14
#define ARG_BYTE 15
#define ARG_DICT_ENTRY 16
#define ARG_STRUCT 17

#define HDR_SIGNATURE 0
#define HDR_MEMBER 1
#define HDR_INVALID 2

#define MAX_ARRAY_LEN 1048576

#define COL_INFO 0
#define ENC_ASCII 0
#define ENC_NA 0
#define ENC_UTF_8 0

typedef int32_t gint;
typedef uint32_t guint;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef int gboolean;
typedef char gchar;

typedef struct tvbuff_t {
    size_t reported_length;
} tvbuff_t;

typedef struct cinfo {
    int dummy;
} cinfo;

typedef struct packet_info {
    cinfo *cinfo;
} packet_info;

typedef struct proto_item {
    void *tree;
} proto_item;

typedef struct proto_tree {
    // empty struct for compilation
} proto_tree;

typedef struct expert_field {
    // empty struct for compilation
} expert_field;

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

static int ett_alljoyn_mess_body_parameters;

static expert_field ei_alljoyn_empty_arg;

static void* wmem_packet_scope() { return NULL; }

static gint round_to_8byte(gint offset, gint field_starting_offset) { return offset; }
static gint round_to_4byte(gint offset, gint field_starting_offset) { return offset; }
static gint round_to_2byte(gint offset, gint field_starting_offset) { return offset; }
static uint32_t get_uint32(tvbuff_t *tvb, gint offset, guint encoding) { return 0; }
static void add_padding_item(gint padding_start, gint offset, tvbuff_t *tvb, proto_tree *tree) {}
static gint pad_according_to_type(gint offset, gint field_starting_offset, gint packet_length, guint8 type_id) { return offset; }
static void advance_to_end_of_signature(guint8 **signature, guint8 *remaining_sig_length) {}
static void append_struct_signature(proto_item *item, guint8 *signature, guint8 signature_length, guint8 type_stop) {}

static size_t tvb_reported_length(tvbuff_t *tvb) { return tvb->reported_length; }
static size_t tvb_reported_length_remaining(tvbuff_t *tvb, gint offset) { return tvb->reported_length - offset; }
static guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset) { return 0; }
static char* tvb_get_string_enc(void* scope, tvbuff_t *tvb, gint offset, gint length, int enc) { return NULL; }

static void col_add_fstr(cinfo* cinfo, int col, const char* fmt, ...) {}
static void col_append_fstr(cinfo* cinfo, int col, const char* fmt, ...) {}

static proto_item* proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, gint offset, gint length, guint encoding) { return NULL; }
static proto_tree* proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static void proto_item_append_text(proto_item *item, const char* fmt, ...) {}
static void proto_item_set_text(proto_item *item, const char* fmt, ...) {}
static void proto_item_set_end(proto_item *item, tvbuff_t *tvb, gint offset) {}
static void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, gint offset, gint length) {}