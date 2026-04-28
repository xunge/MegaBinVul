#include <stdint.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct netdissect_options netdissect_options;

#define ND_TCHECK2(p, l)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_24BITS(p) ((p)[0] << 16 | (p)[1] << 8 | (p)[2])
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

#define ISIS_SUBTLV_EXT_IS_REACH_ADMIN_GROUP 3
#define ISIS_SUBTLV_EXT_IS_REACH_LINK_LOCAL_REMOTE_ID 4
#define ISIS_SUBTLV_EXT_IS_REACH_LINK_REMOTE_ID 5
#define ISIS_SUBTLV_EXT_IS_REACH_IPV4_INTF_ADDR 6
#define ISIS_SUBTLV_EXT_IS_REACH_IPV4_NEIGHBOR_ADDR 8
#define ISIS_SUBTLV_EXT_IS_REACH_MAX_LINK_BW 9
#define ISIS_SUBTLV_EXT_IS_REACH_RESERVABLE_BW 10
#define ISIS_SUBTLV_EXT_IS_REACH_UNRESERVED_BW 11
#define ISIS_SUBTLV_EXT_IS_REACH_TE_METRIC 18
#define ISIS_SUBTLV_EXT_IS_REACH_LINK_ATTRIBUTE 19
#define ISIS_SUBTLV_EXT_IS_REACH_LINK_PROTECTION_TYPE 20
#define ISIS_SUBTLV_EXT_IS_REACH_INTF_SW_CAP_DESCR 21
#define ISIS_SUBTLV_EXT_IS_REACH_BW_CONSTRAINTS 22
#define ISIS_SUBTLV_EXT_IS_REACH_BW_CONSTRAINTS_OLD 23
#define ISIS_SUBTLV_SPB_METRIC 29

#define GMPLS_PSC1 1
#define GMPLS_PSC2 2
#define GMPLS_PSC3 3
#define GMPLS_PSC4 4
#define GMPLS_TSC 100

const char *tok2str(const char **, const char *, int);
const char *bittok2str(const char **, const char *, int);
const char *ipaddr_string(netdissect_options *, const uint8_t *);
int print_unknown_data(netdissect_options *, const uint8_t *, const char *, int);