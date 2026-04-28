#include <stdint.h>
#include <string.h>

typedef struct _proto_tree proto_tree;
typedef struct _tvbuff_t tvbuff_t;

typedef struct {
    const char *strptr;
    uint32_t value;
} value_string;

typedef struct {
    value_string *vals;
    size_t count;
} value_string_ext;

extern const value_string_ext vals_wbxml1x_global_tokens_ext;

#define THROW(x) 
#define DebugLog(x)

static const char *Indent(uint8_t level) {
    static char indent[256];
    memset(indent, ' ', level * 2);
    indent[level * 2] = '\0';
    return indent;
}

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef unsigned int guint;

static guint32 tvb_reported_length(tvbuff_t *tvb) { return 0; }
static guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset) { return 0; }
static void proto_tree_add_text(proto_tree *tree, tvbuff_t *tvb, guint32 start, guint32 length, const char *format, ...) {}
static guint32 tvb_get_guintvar(tvbuff_t *tvb, guint32 offset, guint32 *len) { return 0; }
static guint32 tvb_strsize(tvbuff_t *tvb, guint32 offset) { return 0; }
static const char *tvb_format_text(tvbuff_t *tvb, guint32 offset, guint32 length) { return ""; }
static const char *val_to_str_ext(guint32 val, const value_string_ext *vs, const char *fmt) { return ""; }