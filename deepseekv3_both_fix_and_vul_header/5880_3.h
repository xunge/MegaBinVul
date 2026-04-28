#include <stdint.h>
#include <stddef.h>

typedef int32_t gint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef int16_t gint16;
typedef char gchar;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void *pool;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

struct e_in6_addr {
    uint8_t addr[16];
};

#define ENC_BIG_ENDIAN 0

extern int hf_address_table_family;
extern int hf_address_table_address_length;
extern int hf_address_table_length;
extern int hf_address_table_element;
extern int ett_table_element;

typedef struct expert_field expert_field;
extern expert_field ei_wccp_length_bad;
extern expert_field ei_wccp_address_table_family_unknown;

struct wccp_address_table_t {
    gboolean in_use;
    gint16 family;
    guint16 table_length;
    guint32 *table_ipv4;
    struct e_in6_addr *table_ipv6;
};

extern struct wccp_address_table_t wccp_wccp_address_table;

guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
void tvb_get_ipv6(tvbuff_t *tvb, int offset, struct e_in6_addr *addr);
const char *tvb_ip_to_str(tvbuff_t *tvb, int offset);
const char *tvb_ip6_to_str(tvbuff_t *tvb, int offset);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
proto_item *proto_tree_add_string_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *value, const char *format, ...);
void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *expert, const char *format, ...);
char *wmem_strdup_printf(void *scope, const char *format, ...);
void *wmem_alloc0(void *pool, size_t size);
void *wmem_packet_scope(void);

#define EAT(amount) offset += (amount)
#define EAT_AND_CHECK(amount, min_length) \
    do { \
        EAT(amount); \
        if (length < offset + (min_length)) \
            return length - offset; \
    } while (0)