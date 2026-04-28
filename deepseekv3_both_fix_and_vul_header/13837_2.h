#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef uint32_t guint;
typedef int32_t gint32;
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
    char *(*opaque_literal_tag)(tvbuff_t *tvb, guint32 offset, const char *tag, guint8 codepage, guint32 *len, packet_info *pinfo);
    const char *(*global)(guint8 codepage, guint8 token);
    const char *(*tags)(guint8 codepage, guint8 token);
} wbxml_decoding;

extern guint32 tvb_reported_length(tvbuff_t *tvb);
extern guint32 tvb_captured_length_remaining(tvbuff_t *tvb, guint32 offset);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
extern guint32 tvb_get_guintvar(tvbuff_t *tvb, guint32 offset, guint32 *len, packet_info *pinfo, expert_field *ei);
extern guint32 tvb_strsize(tvbuff_t *tvb, guint32 offset);
extern gchar *tvb_format_text(tvbuff_t *tvb, guint32 offset, gint32 size);
extern const guint8 *tvb_get_ptr(tvbuff_t *tvb, guint32 offset, gint32 length);

extern void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, guint32 start, gint32 length);
extern void proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint32 length, guint32 value, const char *format, ...);
extern void proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint32 length, const char *value, const char *format, ...);
extern void proto_tree_add_none_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint32 length, const char *format, ...);
extern void proto_tree_add_bytes_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint32 length, const void *value, const char *format, ...);

extern const char *Indent(guint8 level);
extern const char *map_token(const char *(*map)(guint8, guint8), guint8 codepage, guint8 token);
extern char *default_opaque_binary_tag(tvbuff_t *tvb, guint32 offset, guint8 tag, guint8 codepage, guint32 *len, packet_info *pinfo);
extern char *default_opaque_literal_tag(tvbuff_t *tvb, guint32 offset, const char *tag, guint8 codepage, guint32 *len, packet_info *pinfo);
extern guint32 parse_wbxml_attribute_list_defined(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 offset, guint32 str_tbl, guint8 level, guint8 *codepage_attr, const wbxml_decoding *map);

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

extern expert_field ei_wbxml_too_much_recursion;
extern expert_field ei_wbxml_oversized_uintvar;

extern void *wmem_packet_scope(void);
extern char *wmem_strdup_printf(void *allocator, const char *format, ...);

#define DebugLog(x)
#define THROW(x)