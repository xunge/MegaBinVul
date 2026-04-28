#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint32_t ipv4;
} address;

typedef struct {
    int visited;
} flags;

typedef struct {
    flags flags;
} frame_data;

typedef struct {
    frame_data *fd;
} pinfo;

typedef struct {
    pinfo *pinfo;
} asn1_ctx_t;

typedef struct {
    address crnc_address;
    uint16_t crnc_port;
} nbap_hsdsch_channel_info_t;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

static uint32_t transportLayerAddress_ipv4;
static uint16_t BindingID_port;
static unsigned int num_items;
static unsigned int hsdsch_macdflow_id;
static nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[1];

#define AT_IPv4 0
#define _U_
#define SET_ADDRESS(addr, type, len, data) 
#define COPY_ADDRESS(dst, src) 

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *sequence);

#define ett_nbap_HSDSCH_MACdFlow_Specific_InfoItem 0
#define HSDSCH_MACdFlow_Specific_InfoItem_sequence NULL