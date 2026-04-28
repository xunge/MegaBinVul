#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define _U_ __attribute__((unused))

typedef uint16_t guint16;
typedef uint32_t guint32;

typedef struct {
    bool in_use;
    int family;
    int version;
    guint32 table_length;
    guint32 *table_ipv4;
    struct e_in6_addr *table_ipv6;
} wccp_address_table_t;

extern wccp_address_table_t wccp_wccp_address_table;
#define WCCP2r1_ADDRESS_TABLE 0
#define FALSE false

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

void dissect_wccp2r1_address_table_info(tvbuff_t *tvb, int offset, guint16 length, packet_info *pinfo, proto_tree *tree);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);