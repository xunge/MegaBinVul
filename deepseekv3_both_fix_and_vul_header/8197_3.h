#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef uint32_t guint;
typedef int32_t gint32;
typedef uint8_t guint8;
typedef int8_t gint8;
typedef int gint;
typedef char gchar;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct expert_field expert_field;

typedef struct _wbxml_decoding {
    char *(*ext_t[3])(tvbuff_t *tvb, guint32 idx, guint32 str_tbl);
    char *(*opaque_binary_tag)(tvbuff_t *tvb, guint32 offset, guint8 tag, guint8 codepage, guint32 *len, packet_info *pinfo);
    char *(*opaque_literal_tag)(tvbuff_t *tvb, guint32 offset, const gchar *tag, guint8 codepage, guint32 *len, packet_info *pinfo);
    const gchar *(*global)(guint8 codepage, guint8 token);
    const gchar *(*tags)(guint8 codepage, guint8 token);
} wbxml_decoding;

extern expert_field ei_wbxml_too_much_recursion;
extern expert_field ei_wbxml_oversized_uintvar;
extern int hf_wbxml_switch_page;
extern int hf_wbxml_end_known_tag;
extern int hf_wbxml_end_literal_tag;
extern int hf_wbxml_entity;
extern int hf_wbxml_str_i;
extern int hf_wbxml_ext_i;
extern int hf_wbxml_pi_xml;
extern int hf_wbxml_end_pi;
extern int hf_wbxml_ext_t;
extern int hf_wbxml_str_t;
extern int hf_wbxml_extension_token;
extern int hf_wbxml_reserved_2;
extern int hf_wbxml_opaque_data;
extern int hf_wbxml_known_tag;
extern int hf_wbxml_literal_ac;
extern int hf_wbxml_literal_c;
extern int hf_wbxml_literal_a;
extern int hf_wbxml_literal;
extern int hf_wbxml_end_attribute_list;
extern int hf_wbxml_end_known_tag_uint;

#define DebugLog(x)
#define THROW(x)
#define Indent(x) ""

static guint32 tvb_reported_length(const tvbuff_t *tvb);
static guint32 tvb_captured_length_remaining(const tvbuff_t *tvb, gint offset);
static guint8 tvb_get_guint8(const tvbuff_t *tvb, gint offset);
static guint32 tvb_get_guintvar(const tvbuff_t *tvb, gint offset, guint32 *len, packet_info *pinfo, expert_field *ei);
static guint32 tvb_strsize(const tvbuff_t *tvb, gint offset);
static const gchar *tvb_format_text(const tvbuff_t *tvb, gint offset, gint size);
static const guint8 *tvb_get_ptr(const tvbuff_t *tvb, gint offset, gint length);

static void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, gint start, gint length);
static void proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint32 value, const char *format, ...);
static void proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const char *value, const char *format, ...);
static void proto_tree_add_none_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const char *format, ...);
static void proto_tree_add_bytes_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const void *valueptr, const char *format, ...);

static const gchar *map_token(const gchar *(*map_func)(guint8 codepage, guint8 token), guint8 codepage, guint8 token);
static char *default_opaque_binary_tag(tvbuff_t *tvb, guint32 offset, guint8 tag, guint8 codepage, guint32 *len, packet_info *pinfo);
static char *default_opaque_literal_tag(tvbuff_t *tvb, guint32 offset, const gchar *tag, guint8 codepage, guint32 *len, packet_info *pinfo);
static guint32 parse_wbxml_attribute_list_defined(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 offset, guint32 str_tbl, guint8 level, guint8 *codepage_attr, const wbxml_decoding *map);

static char *wmem_strdup_printf(void *scope, const char *fmt, ...);
static void *wmem_packet_scope(void);