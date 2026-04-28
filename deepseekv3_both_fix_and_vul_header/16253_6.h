#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef int32_t gint32;
typedef uint8_t guint8;
typedef unsigned int guint;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define ENC_NA 0
#define ENC_ASCII 1
#define ENC_LITTLE_ENDIAN 2

static int hf_fb_zero_tags = -1;
static int hf_fb_zero_tag_type = -1;
static int hf_fb_zero_tag_offset_end = -1;
static int hf_fb_zero_tag_length = -1;
static int hf_fb_zero_tag_value = -1;
static int hf_fb_zero_tag_sni = -1;
static int hf_fb_zero_tag_vers = -1;
static int hf_fb_zero_tag_sno = -1;
static int hf_fb_zero_tag_aead = -1;
static int hf_fb_zero_tag_scid = -1;
static int hf_fb_zero_tag_time = -1;
static int hf_fb_zero_tag_alpn = -1;
static int hf_fb_zero_tag_pubs = -1;
static int hf_fb_zero_tag_kexs = -1;
static int hf_fb_zero_tag_nonc = -1;
static int hf_fb_zero_tag_unknown = -1;

static int ett_fb_zero_tag_value = -1;

typedef struct {
    int code;
    const char* str;
} expert_field;

static expert_field ei_fb_zero_tag_length = {0};
static expert_field ei_fb_zero_tag_undecoded = {0};
static expert_field ei_fb_zero_tag_unknown = {0};
static expert_field ei_fb_zero_length_invalid = {0};

typedef struct {
    guint32 value;
    const char* str;
} value_string;

static const value_string tag_vals[] = {
    { 0x494e53, "SNI" },
    { 0x53524556, "VERS" },
    { 0x4f4e53, "SNO" },
    { 0x44414541, "AEAD" },
    { 0x44494353, "SCID" },
    { 0x454d4954, "TIME" },
    { 0x4e504c41, "ALPN" },
    { 0x53425550, "PUBS" },
    { 0x5358454b, "KEXS" },
    { 0x434e4f4e, "NONC" },
    { 0, NULL }
};

static const value_string tag_aead_vals[] = {
    { 0, NULL }
};

static const value_string tag_kexs_vals[] = {
    { 0, NULL }
};

#define TAG_SNI 0x494e53
#define TAG_VERS 0x53524556
#define TAG_SNO 0x4f4e53
#define TAG_AEAD 0x44414541
#define TAG_SCID 0x44494353
#define TAG_TIME 0x454d4954
#define TAG_ALPN 0x4e504c41
#define TAG_PUBS 0x53425550
#define TAG_KEXS 0x5358454b
#define TAG_NONC 0x434e4f4e

static void* wmem_packet_scope() { return NULL; }
static const char* val_to_str(guint32 val, const value_string *vs, const char *def) { return def; }
static guint32 tvb_get_ntohl(tvbuff_t *tvb, guint offset) { return 0; }
static guint32 tvb_get_letohl(tvbuff_t *tvb, guint offset) { return 0; }
static guint32 tvb_reported_length_remaining(tvbuff_t *tvb, guint offset) { return 0; }
static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint start, gint32 length, int encoding) { return NULL; }
static proto_tree* proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static proto_item* proto_tree_add_item_ret_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint start, gint32 length, int encoding, void* scope, const guint8** strptr) { return NULL; }
static void proto_item_append_text(proto_item *item, const char *format, ...) {}
static proto_item* proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint start, gint32 length, guint32 value) { return NULL; }
static void proto_item_set_generated(proto_item *item) {}
static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef) {}
static void expert_add_info_format(packet_info *pinfo, proto_tree *tree, expert_field *ef, const char *format, ...) {}
static proto_item* proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, guint start, gint32 length) { return NULL; }