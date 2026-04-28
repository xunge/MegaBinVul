#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct vtp_vlan_ {
    uint8_t status;
    uint8_t type;
    uint8_t name_len;
    uint8_t vlanid[2];
    uint8_t mtu[2];
    uint8_t index[4];
};

#define VTP_HEADER_LEN 4
#define VTP_UPDATE_TIMESTAMP_LEN 12
#define VTP_MD5_DIGEST_LEN 16
#define VTP_VLAN_INFO_OFFSET 12

enum {
    VTP_SUMMARY_ADV = 1,
    VTP_SUBSET_ADV = 2,
    VTP_ADV_REQUEST = 3,
    VTP_JOIN_MESSAGE = 4
};

enum {
    VTP_VLAN_STE_HOP_COUNT = 1,
    VTP_VLAN_PRUNING = 2,
    VTP_VLAN_STP_TYPE = 3,
    VTP_VLAN_BRIDGE_TYPE = 4,
    VTP_VLAN_BACKUP_CRF_MODE = 5,
    VTP_VLAN_SOURCE_ROUTING_RING_NUMBER = 6,
    VTP_VLAN_SOURCE_ROUTING_BRIDGE_NUMBER = 7,
    VTP_VLAN_PARENT_VLAN = 8,
    VTP_VLAN_TRANS_BRIDGED_VLAN = 9,
    VTP_VLAN_ARP_HOP_COUNT = 10
};

extern const char *vtp_message_type_values[];
extern const char *vtp_header_values[];
extern const char *vtp_vlan_status[];
extern const char *vtp_vlan_type_values[];
extern const char *vtp_vlan_tlv_values[];
extern const char *vtp_stp_type_values[];

#define ND_TCHECK2(a, b)
#define ND_TCHECK(a)
#define ND_PRINT(a)
#define EXTRACT_16BITS(p) ((uint16_t)((p)[0] << 8 | (p)[1]))
#define EXTRACT_32BITS(p) ((uint32_t)((p)[0] << 24 | (p)[1] << 16 | (p)[2] << 8 | (p)[3]))

void fn_printzp(netdissect_options *, const u_char *, u_int, const char *);
void print_unknown_data(netdissect_options *, const u_char *, const char *, u_int);
const char *ipaddr_string(netdissect_options *, const u_char *);
const char *tok2str(const char *, const char *, int);