#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t guint32;
typedef uint32_t guint;
typedef uint8_t guint8;
typedef int32_t gint;
typedef char gchar;

typedef struct _wbxml_decoding {
    const void *global;
    const void *attrStart;
    const void *attrValue;
    char* (*ext_t[4])(void *tvb, guint32 idx, guint32 str_tbl);
    char* (*opaque_binary_attr)(void *tvb, guint32 offset, guint8 known, guint8 codepage, guint32 *len, void *pinfo);
    char* (*opaque_literal_attr)(void *tvb, guint32 offset, const char *literal, guint8 codepage, guint32 *len, void *pinfo);
    char* (*opaque_literal_tag)(void *tvb, guint32 offset, const char *literal, guint8 codepage, guint32 *len, void *pinfo);
} wbxml_decoding;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;

extern int hf_wbxml_switch_page;
extern int hf_wbxml_entity;
extern int hf_wbxml_str_i;
extern int hf_wbxml_literal;
extern int hf_wbxml_ext_i;
extern int hf_wbxml_ext_t;
extern int hf_wbxml_str_t;
extern int hf_wbxml_extension_token;
extern int hf_wbxml_opaque_data;
extern int hf_wbxml_reserved_2;
extern int hf_wbxml_invalid_token;
extern int hf_wbxml_known_attrvalue;
extern int hf_wbxml_known_attrstart;
extern int ei_wbxml_oversized_uintvar;

extern const void vals_wbxml1x_global_tokens_ext;

extern void DebugLog(const char *fmt, ...);
extern const char *Indent(guint8 level);
extern const char *map_token(const void *vs, guint8 codepage, guint8 token);
extern char *default_opaque_binary_attr(void *tvb, guint32 offset, guint8 known, guint8 codepage, guint32 *len, void *pinfo);
extern char *default_opaque_literal_attr(void *tvb, guint32 offset, const char *literal, guint8 codepage, guint32 *len, void *pinfo);

extern guint32 tvb_reported_length(tvbuff_t *tvb);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
extern guint32 tvb_get_guintvar(tvbuff_t *tvb, guint32 offset, guint32 *len, packet_info *pinfo, int *ei);
extern guint32 tvb_strsize(tvbuff_t *tvb, guint32 offset);
extern gchar *tvb_format_text(tvbuff_t *tvb, guint32 offset, gint length);
extern void proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, guint32 value, const char *format, ...);
extern void proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, const char *value, const char *format, ...);
extern void proto_tree_add_bytes_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, const void *value, const char *format, ...);
extern void proto_tree_add_none_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, const char *format, ...);
extern char *wmem_strdup_printf(void *scope, const char *format, ...);