#include <stdint.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef int gint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

typedef struct {
    guint8 value;
    const char *str;
} value_string;

extern int hf_lisp_lcaf;
extern int hf_lisp_lcaf_header;
extern int hf_lisp_lcaf_res1;
extern int hf_lisp_lcaf_flags;
extern int hf_lisp_lcaf_type;
extern int hf_lisp_lcaf_mcinfo_flags;
extern int hf_lisp_lcaf_mcinfo_flags_res;
extern int hf_lisp_lcaf_mcinfo_flags_rp;
extern int hf_lisp_lcaf_mcinfo_flags_leave;
extern int hf_lisp_lcaf_mcinfo_flags_join;
extern int hf_lisp_lcaf_res2;
extern int hf_lisp_lcaf_length;
extern int ett_lisp_lcaf;
extern int ett_lisp_lcaf_header;
extern int ett_lisp_lcaf_mcinfo_flags;
extern expert_field ei_lisp_undecoded;

extern const value_string lcaf_typevals[];
extern const char *val_to_str(guint8 val, const value_string *vs, const char *fmt);

#define LCAF_HEADER_LEN 6
#define LCAF_NULL 0
#define LCAF_AFI_LIST 1
#define LCAF_IID 2
#define LCAF_ASN 3
#define LCAF_GEO 4
#define LCAF_NATT 5
#define LCAF_NONCE_LOC 6
#define LCAF_MCAST_INFO 7
#define LCAF_ELP 8
#define LCAF_SRC_DST_KEY 9
#define LCAF_RLE 10
#define LCAF_KV_ADDR_PAIR 11
#define LCAF_VENDOR 12

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

extern guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern void proto_item_append_text(proto_item *item, const char *format, ...);
extern void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int offset, int length);

extern int dissect_lcaf_afi_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 len);
extern int dissect_lcaf_iid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, proto_item *ti);
extern int dissect_lcaf_asn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, proto_item *ti);
extern int dissect_lcaf_geo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, proto_item *ti);
extern int dissect_lcaf_natt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 len);
extern int dissect_lcaf_nonce_loc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, proto_item *ti);
extern int dissect_lcaf_mcast_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, proto_item *ti);
extern int dissect_lcaf_elp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 len, proto_item *ti);
extern int dissect_lcaf_src_dst_key(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, proto_item *ti);
extern int dissect_lcaf_rle(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 len, proto_item *ti);
extern int dissect_lcaf_kv_addr_pair(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset);
extern int dissect_lcaf_vendor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 len);