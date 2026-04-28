#include <stdint.h>
#include <string.h>

#define MAX_ADDR_SIZE 16

#define ADDR_HASHEAD 0x01
#define ADDR_HASFULLTAIL 0x02
#define ADDR_HASZEROTAIL 0x04
#define ADDR_HASSINGLEPRELEN 0x08
#define ADDR_HASMULTIPRELEN 0x10

#define TLV_CAT_ADDRESS 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct e_in6_addr {
    uint8_t bytes[16];
} e_in6_addr;

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef unsigned int guint;
typedef int gint;

extern const int hf_packetbb_addr_flags_hashead;
extern const int hf_packetbb_addr_flags_hasfulltail;
extern const int hf_packetbb_addr_flags_haszerotail;
extern const int hf_packetbb_addr_flags_hassingleprelen;
extern const int hf_packetbb_addr_flags_hasmultiprelen;
extern const int hf_packetbb_addr;
extern const int hf_packetbb_addr_num;
extern const int hf_packetbb_addr_flags;
extern const int hf_packetbb_addr_head;
extern const int hf_packetbb_addr_tail;
extern const int hf_packetbb_addr_value[4];
extern const int hf_packetbb_addr_value_mid;
extern const int hf_packetbb_addr_value_prefix;

extern const int ett_packetbb_addr;
extern const int ett_packetbb_addr_flags;
extern const int ett_packetbb_addr_value;

extern const int ei_packetbb_error;

#define DISSECTOR_ASSERT(expr) ((void)0)

guint8 tvb_get_guint8(const tvbuff_t *tvb, gint offset);
void tvb_memcpy(const tvbuff_t *tvb, void *dst, gint offset, size_t length);
guint tvb_reported_length(const tvbuff_t *tvb);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
proto_item *proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, gint start, int hfindex, int ett, const int **fields, int encoding);
proto_item *proto_tree_add_ipv4(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint32 ipv4);
proto_item *proto_tree_add_ipv6(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const e_in6_addr *ipv6);
proto_item *proto_tree_add_ether(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const guint8 *addr);
proto_item *proto_tree_add_bytes(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const guint8 *addr);
proto_item *proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, const int *ei, tvbuff_t *tvb, gint start, gint length, const char *format, ...);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
void proto_item_append_text(proto_item *item, const char *format, ...);

int dissect_pbb_tlvblock(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint maxoffset, guint numAddr, guint8 tlv_cat);