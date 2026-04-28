#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef char gchar;

typedef struct proto_tree proto_tree;
typedef struct tvbuff tvbuff_t;

#define DebugLog(x)
#define THROW(x)
#define Indent(x) ""
#define tvb_reported_length(x) 0
#define tvb_get_guint8(x,y) 0
#define tvb_get_guintvar(x,y,z) 0
#define tvb_strsize(x,y) 0
#define tvb_format_text(x,y,z) ""
#define tvb_get_ptr(x,y,z) NULL
#define proto_tree_add_text(...)
#define wmem_strdup_printf(x,...) NULL
#define wmem_packet_scope() NULL

static guint32 parse_wbxml_attribute_list(proto_tree *tree, tvbuff_t *tvb, guint32 offset,
                                        guint32 str_tbl, guint8 level, guint8 *codepage_attr);