#include <stdint.h>
#include <string.h>

typedef int gint;
typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint32_t guint32;

#define QNX_QNET6_LR_PKT_SIZE 64
#define QNET_LR_SA_FAMILY_MAC 0x01
#define QNET_LR_TYPE_REQUEST 0x01
#define QNET_LR_TYPE_REPLY 0x02
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define ENC_ASCII 2
#define COL_PROTOCOL 0
#define COL_INFO 1

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define PROTO_ITEM_SET_GENERATED(ti) ((void)0)

typedef struct tvbuff_t {
    int dummy;
} tvbuff_t;

typedef struct packet_info {
    struct {
        const char* str;
    } cinfo[2];
} packet_info;

typedef struct proto_tree {
    int dummy; 
} proto_tree;

typedef struct proto_item {
    int dummy;
} proto_item;

typedef struct column_info {
    int dummy;
} column_info;

static inline void col_set_str(column_info *cinfo, int col, const char *str) {}
static inline guint tvb_reported_length_remaining(tvbuff_t *tvb, gint offset) { return 0; }
static inline proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint encoding) { return NULL; }
static inline proto_tree *proto_item_add_subtree(proto_item *ti, int ett) { return NULL; }
static inline guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset) { return 0; }
static inline guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding) { return 0; }
static inline void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint32 value) {}
static inline proto_item *proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const char *value) { return NULL; }
static inline proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, gint start, gint length, int ett, proto_item **ti, const char *text) { return NULL; }
static inline guint8 *tvb_get_string_enc(void *scope, tvbuff_t *tvb, gint offset, gint length, guint encoding) { return NULL; }
static inline void col_add_fstr(column_info *cinfo, int col, const char *format, ...) {}

extern int proto_qnet6_lr;
extern int ett_qnet6_lr;
extern int ett_qnet6_lr_src;
extern int ett_qnet6_lr_dst;
extern int ett_qnet6_lr_src_name_subtree;
extern int hf_qnet6_lr_ver;
extern int hf_qnet6_lr_type;
extern int hf_qnet6_lr_total_len;
extern int hf_qnet6_lr_src;
extern int hf_qnet6_lr_dst;
extern int hf_qnet6_lr_src_name_off;
extern int hf_qnet6_lr_src_name_len;
extern int hf_qnet6_lr_src_name_generated;
extern int hf_qnet6_lr_src_domain_off;
extern int hf_qnet6_lr_src_domain_len;
extern int hf_qnet6_lr_src_domain_generated;
extern int hf_qnet6_lr_src_addr_off;
extern int hf_qnet6_lr_src_addr_len;
extern int hf_qnet6_lr_src_addr_generated;
extern int hf_qnet6_lr_dst_name_off;
extern int hf_qnet6_lr_dst_name_len;
extern int hf_qnet6_lr_dst_name_generated;
extern int hf_qnet6_lr_dst_domain_off;
extern int hf_qnet6_lr_dst_domain_len;
extern int hf_qnet6_lr_dst_domain_generated;
extern int hf_qnet6_lr_dst_addr_off;
extern int hf_qnet6_lr_dst_addr_len;
extern int hf_qnet6_lr_dst_addr_generated;

static void *wmem_packet_scope() { return NULL; }