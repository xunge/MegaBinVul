#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef int32_t gint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef char gchar;

#define TRUE 1
#define FALSE 0
#define NULL ((void*)0)

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void* pool;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

struct e_in6_addr {
    uint8_t s6_addr[16];
};

struct expert_field {
    int dummy;
};

static struct {
    bool in_use;
    gint family;
    gint version;
    guint32 table_length;
    guint32 *table_ipv4;
    struct e_in6_addr *table_ipv6;
} wccp_wccp_address_table;

static int hf_address_table_family;
static int hf_address_table_address_length;
static int hf_address_table_length;
static int hf_address_table_element;
static int ett_table_element;
static struct expert_field ei_wccp_length_bad;
static struct expert_field ei_wccp_address_table_family_unknown;

#define ENC_BIG_ENDIAN 0

#define EAT(len) offset += (len); length -= (len)
#define EAT_AND_CHECK(len, min_len) \
    do { \
        if (length < (min_len)) \
            return length - (min_len); \
        EAT(len); \
    } while (0)