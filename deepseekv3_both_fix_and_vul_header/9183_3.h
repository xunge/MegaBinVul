#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;

typedef struct diam_sub_dis_t {
    char *avp_str;
} diam_sub_dis_t;

struct e_in6_addr {
    guint8 bytes[16];
};

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;
typedef struct address {
    int dummy;
} address;

#define _U_
#define ENC_BIG_ENDIAN 0
#define ENC_NA 1
#define AT_IPv6 2

extern int hf_framed_ipv6_prefix_reserved;
extern int hf_framed_ipv6_prefix_length;
extern int hf_framed_ipv6_prefix_bytes;
extern int hf_framed_ipv6_prefix_ipv6;
extern expert_field ei_diameter_invalid_ipv6_prefix_len;

guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
void tvb_memcpy(tvbuff_t *tvb, void *target, int offset, int length);
void expert_add_info(packet_info *pinfo, proto_item *pi, expert_field *ef);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_ipv6(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, struct e_in6_addr *addr);
void set_address(address *addr, int type, int len, const void *data);
void *wmem_packet_scope(void);
char *address_to_str(void *scope, address *addr);
char *wmem_strdup_printf(void *scope, const char *fmt, ...);