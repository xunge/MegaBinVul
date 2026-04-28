#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define VQP_VERSION 1
#define VQP_EXTRACT_VERSION(version) ((version) >> 4)
#define ETHER_ADDR_LEN 6

enum {
    VQP_OBJ_IP_ADDRESS = 1,
    VQP_OBJ_PORT_NAME,
    VQP_OBJ_VLAN_NAME,
    VQP_OBJ_VTP_DOMAIN,
    VQP_OBJ_ETHERNET_PKT,
    VQP_OBJ_MAC_ADDRESS,
    VQP_OBJ_MAC_NULL
};

struct vqp_common_header_t {
    uint8_t version;
    uint8_t msg_type;
    uint8_t error_code;
    uint8_t nitems;
    uint32_t sequence;
};

struct vqp_obj_tlv_t {
    uint32_t obj_type;
    uint16_t obj_length;
};

#define ND_TCHECK(expr)
#define ND_TCHECK2(ptr, len)
#define ND_PRINT(args) printf args
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

extern const char *tok2str(const char *str, const char *fmt, int val);
extern const char *ipaddr_string(netdissect_options *ndo, const u_char *p);
extern const char *etheraddr_string(netdissect_options *ndo, const u_char *p);
extern void safeputs(netdissect_options *ndo, const u_char *p, u_int len);
extern void print_unknown_data(netdissect_options *ndo, const u_char *p, const char *s, u_int len);

extern const char *vqp_msg_type_values[];
extern const char *vqp_error_code_values[];
extern const char *vqp_obj_values[];