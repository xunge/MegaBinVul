#include <stdint.h>

#define LOWPAN_IFC_ID_LEN 8
#define LOWPAN_PATTERN_MESH_BITS 3
#define LOWPAN_PATTERN_MESH 0
#define LOWPAN_PATTERN_BC0_BITS 3
#define LOWPAN_PATTERN_BC0 0
#define LOWPAN_PATTERN_FRAG_BITS 3
#define LOWPAN_PATTERN_FRAG1 0
#define LOWPAN_PATTERN_FRAGN 0
#define LOWPAN_PATTERN_IPV6_BITS 3
#define LOWPAN_PATTERN_IPV6 0
#define LOWPAN_PATTERN_PAGING_DISPATCH_BITS 3
#define LOWPAN_PATTERN_PAGING_DISPATCH 0
#define LOWPAN_PATTERN_IPHC_BITS 3
#define LOWPAN_PATTERN_IPHC 0
#define LOWPAN_PATTERN_HC1_BITS 3
#define LOWPAN_PATTERN_HC1 0
#define ENC_BIG_ENDIAN 0

typedef unsigned int guint;
typedef uint8_t guint8;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct _header_field_info header_field_info;

extern proto_tree* proto_item_add_subtree(proto_item*, int);
extern proto_item* proto_tree_add_protocol_format(proto_tree*, int, tvbuff_t*, int, int, const char*);
extern void col_set_str(void*, int, const char*);
extern void proto_tree_add_bits_item(proto_tree*, int, tvbuff_t*, int, int, int);
extern tvbuff_t* dissect_6lowpan_mesh(tvbuff_t*, packet_info*, proto_tree*, guint8*, guint8*);
extern tvbuff_t* dissect_6lowpan_bc0(tvbuff_t*, packet_info*, proto_tree*);
extern tvbuff_t* dissect_6lowpan_frag_first(tvbuff_t*, packet_info*, proto_tree*, guint8*, guint8*);
extern tvbuff_t* dissect_6lowpan_frag_middle(tvbuff_t*, packet_info*, proto_tree*);
extern tvbuff_t* dissect_6lowpan_ipv6(tvbuff_t*, packet_info*, proto_tree*);
extern tvbuff_t* dissect_6lowpan_6loRH(tvbuff_t*, guint, proto_tree*);
extern tvbuff_t* dissect_6lowpan_iphc(tvbuff_t*, packet_info*, proto_tree*, int, guint8*, guint8*);
extern tvbuff_t* dissect_6lowpan_hc1(tvbuff_t*, packet_info*, proto_tree*, int, guint8*, guint8*);
extern void dissect_6lowpan_unknown(tvbuff_t*, packet_info*, proto_tree*);
extern void call_dissector(void*, tvbuff_t*, packet_info*, proto_tree*);
extern int tvb_captured_length(tvbuff_t*);
extern guint8 tvb_get_bits8(tvbuff_t*, int, int);
extern void lowpan_dlsrc_to_ifcid(packet_info*, guint8*);
extern void lowpan_dldst_to_ifcid(packet_info*, guint8*);

extern int proto_6lowpan;
extern int ett_6lowpan;
extern int hf_6lowpan_pagenb;
extern void* ipv6_handle;

struct packet_info {
    void* cinfo;
};

enum {
    COL_PROTOCOL
};

#define _U_ __attribute__((unused))