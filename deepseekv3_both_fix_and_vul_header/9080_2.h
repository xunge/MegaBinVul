#include <stdint.h>

#define _U_ __attribute__((unused))

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct {
    uint32_t ipv4;
} address;

typedef struct {
    int visited;
} flags;

typedef struct {
    flags flags;
} fd;

typedef struct {
    fd* fd;
} pinfo;

typedef struct {
    pinfo* pinfo;
} asn1_ctx_t;

typedef struct {
    address crnc_address;
    uint16_t crnc_port;
} nbap_hsdsch_channel_info_t;

static uint32_t transportLayerAddress_ipv4;
static uint16_t BindingID_port;
static unsigned int num_items;
static unsigned int hsdsch_macdflow_id;
static nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[1];

#define AT_IPv4 0
#define SET_ADDRESS(addr, type, len, value) ((void)0)
#define COPY_ADDRESS(dst, src) ((void)0)

extern int dissect_per_sequence(tvbuff_t*, int, asn1_ctx_t*, proto_tree*, int, int, int);
extern int ett_nbap_HSDSCH_MACdFlow_Specific_InfoItem_to_Modify;
extern int HSDSCH_MACdFlow_Specific_InfoItem_to_Modify_sequence;