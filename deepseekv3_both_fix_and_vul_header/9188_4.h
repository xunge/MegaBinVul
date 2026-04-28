#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint32_t guint;
typedef int32_t gint;
typedef char gchar;

#define TRUE true
#define FALSE false

typedef struct {
    void *elem_item;
    void *message_item;
    bool meid_configured;
} ansi_a_shared_data_t;

typedef struct {
    const char *out;
} digit_t;

typedef struct {
    void *tvb;
} tvbuff_t;

typedef struct {
    void *cinfo;
} packet_info;

typedef struct {
    void *tree;
} proto_tree;

typedef struct {
    void *field;
} expert_field;

typedef struct {
    const char *name;
} value_string_ext;

extern int hf_ansi_a_meid_mid_digit_1;
extern int hf_ansi_a_mid_odd_even_ind;
extern int hf_ansi_a_mid_type_of_id;
extern int hf_ansi_a_meid;
extern int hf_ansi_a_reserved_bits_8_f8;
extern int hf_ansi_a_mid_broadcast_priority;
extern int hf_ansi_a_mid_broadcast_message_id;
extern int hf_ansi_a_mid_broadcast_zone_id;
extern int hf_ansi_a_mid_broadcast_srvc_cat;
extern int hf_ansi_a_mid_broadcast_language;
extern int hf_ansi_a_mid_unused;
extern int hf_ansi_a_esn;
extern int hf_ansi_a_imsi_mid_digit_1;
extern int hf_ansi_a_imsi;
extern expert_field ei_ansi_a_unknown_format;

extern const value_string_ext ansi_tsb58_srvc_cat_vals_ext;
extern const value_string_ext ansi_tsb58_language_ind_vals_ext;

extern bool global_a_info_display;
extern const digit_t Dgt_meid;
extern const digit_t Dgt_msid;

#define ENC_BIG_ENDIAN 0
#define COL_INFO 0
#define EXTRANEOUS_DATA_CHECK(a,b)

static guint8 tvb_get_guint8(tvbuff_t *tvb, guint offset);
static guint16 tvb_get_ntohs(tvbuff_t *tvb, guint offset);
static guint32 tvb_get_ntohl(tvbuff_t *tvb, guint offset);
static const gchar* tvb_bcd_dig_to_wmem_packet_str(tvbuff_t *tvb, guint offset, gint len, const digit_t *dgt, bool skip_first);
static void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint start, gint length, int encoding);
static void proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint start, gint length, const char *string);
static void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint start, gint length, guint32 value);
static void proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint start, gint length, guint32 value, const char *format, ...);
static void proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint start, gint length, const char *string, const char *format, ...);
static void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, guint start, gint length, const char *format, ...);
static void proto_item_append_text(void *item, const char *format, ...);
static const gchar* val_to_str_ext_const(guint32 value, const value_string_ext *vs, const char *default_str);
static void col_append_fstr(void *cinfo, int column, const char *format, ...);