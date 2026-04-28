#include <string.h>
#include <stdarg.h>

typedef int gint;
typedef char gchar;
typedef unsigned char guint8;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct {
    int dummy;
} expert_field;

static gint ett_variable = -1;
static int hf_rbm_type = -1;
static expert_field ei_rbm_invalid = {0};

#define ENC_NA 0

static void dissect_rbm_basic(tvbuff_t*, packet_info*, proto_tree*, gint*, guint8, gchar**, gchar**) {}
static void dissect_rbm_integer(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_symbol(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_string(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_variable(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_array(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_hash(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_link(tvbuff_t*, packet_info*, proto_tree*, gint*, guint8, gchar**, gchar**) {}
static void dissect_rbm_double(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_class(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_module(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_struct(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_regex(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_drb(tvbuff_t*, packet_info*, proto_tree*, gint*) {}
static void dissect_rbm_inline(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**, gchar**) {}
static void dissect_rbm_rubyobject(tvbuff_t*, packet_info*, proto_tree*, gint*) {}
static void dissect_rbm_userclass(tvbuff_t*, packet_info*, proto_tree*, gint*, gchar**) {}
static void dissect_rbm_extended(tvbuff_t*, packet_info*, proto_tree*, gint*) {}

static proto_item* proto_tree_add_subtree(proto_tree* parent, tvbuff_t* tvb, gint start, gint length, gint idx, void*, const char* text) { return (proto_item*)0; }
static void proto_tree_add_item(proto_tree* tree, int hf, tvbuff_t* tvb, gint offset, gint length, int encoding) {}
static guint8 tvb_get_guint8(tvbuff_t* tvb, gint offset) { return 0; }
static void expert_add_info_format(packet_info* pinfo, proto_tree* tree, expert_field* ei, const char* fmt, ...) {}
static void proto_item_set_len(proto_item* item, gint length) {}
static void proto_item_append_text(proto_item* item, const char* fmt, ...) {}