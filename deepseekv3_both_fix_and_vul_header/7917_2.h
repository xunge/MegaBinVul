#include <stdint.h>
#include <stddef.h>

typedef int32_t gint;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef int gboolean;
typedef char gchar;

#define FALSE 0
#define TRUE 1
#define NULL ((void*)0)

enum {
    ENC_BIG_ENDIAN = 0
};

static int hf_message_sec_cat_nat;
static int hf_message_sec_cat_cl;
static int hf_message_sec_cat_cs;
static int hf_message_sec_cat_ex;
static int hf_message_sec_cat_ne;
static int hf_reserved_0x08;
static int hf_reserved_0x04;
static int hf_message_sec_cat_permissive;
static int hf_message_sec_cat_restrictive;
static int hf_reserved_0x02;
static int hf_reserved_0x01;
static int hf_message_sec_cat_extended;
static int hf_message_sec_cat_country_code;
static int ett_message_sec_cat;

typedef struct {
    int dummy;
} expert_field;
static expert_field ei_reserved_value;

typedef struct {
    void* dummy;
} tvbuff_t;
typedef struct {
    void* dummy;
} packet_info;
typedef struct {
    void* dummy;
} proto_tree;
typedef struct {
    void* dummy;
} proto_item;

enum {
    SEC_CAT_EXT_NONE,
    SEC_CAT_EXT_PERMISSIVE,
    SEC_CAT_EXT_RESTRICTIVE
};

struct {
    gint version;
} dmp;

const gchar* get_nat_pol_id_short(guint8 id);
guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
proto_item* proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint32 value, const char *format, ...);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef);
void proto_item_append_text(proto_item *item, const char *format, ...);
void proto_item_set_len(proto_item *item, gint length);
gchar* wmem_strdup_printf(void *scope, const gchar *format, ...);
gchar* wmem_strconcat(void *scope, const gchar *first, ...);
void* wmem_packet_scope(void);