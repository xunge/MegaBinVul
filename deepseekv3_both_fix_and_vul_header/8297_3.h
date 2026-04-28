#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef uint32_t guint;
typedef uint8_t guint8;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef char gchar;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct wbxml_decoding {
    char *(*ext_t[3])(tvbuff_t *tvb, guint32 idx, guint32 str_tbl);
    char *(*opaque_binary_tag)(tvbuff_t *tvb, guint32 offset, guint8 tag, guint8 codepage, guint32 *len);
    char *(*opaque_literal_tag)(tvbuff_t *tvb, guint32 offset, const char *tag, guint8 codepage, guint32 *len);
    const char *global;
    const char *tags;
} wbxml_decoding;

#define DebugLog(x)
#define THROW(x)
#define Indent(x) ""
#define wmem_packet_scope() NULL
#define wmem_strdup_printf(scope, fmt, ...) NULL

static const char *map_token(const char *map, guint8 codepage, guint8 token);
static guint32 parse_wbxml_attribute_list_defined(proto_tree *tree, tvbuff_t *tvb, guint32 offset, guint32 str_tbl, guint8 level, guint8 *codepage_attr, const wbxml_decoding *map);
static char *default_opaque_binary_tag(tvbuff_t *tvb, guint32 offset, guint8 tag, guint8 codepage, guint32 *len);
static char *default_opaque_literal_tag(tvbuff_t *tvb, guint32 offset, const char *tag, guint8 codepage, guint32 *len);

guint32 tvb_reported_length(tvbuff_t *tvb);
guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
guint32 tvb_get_guintvar(tvbuff_t *tvb, guint32 offset, guint32 *len);
guint32 tvb_strsize(tvbuff_t *tvb, guint32 offset);
const char *tvb_format_text(tvbuff_t *tvb, guint32 offset, guint32 length);
const char *tvb_get_ptr(tvbuff_t *tvb, guint32 offset, guint32 length);

void proto_tree_add_text(proto_tree *tree, tvbuff_t *tvb, guint32 start, guint32 length, const char *format, ...);