#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct {
    unsigned int visited;
} flags_t;

typedef struct {
    flags_t flags;
} fd_t;

typedef struct {
    fd_t *fd;
} pinfo_t;

typedef struct {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct {
    uint8_t type;
    uint8_t len;
    void *data;
} address;

typedef struct {
    address crnc_address;
    uint16_t crnc_port;
} nbap_hsdsch_channel_info_t;

static uint32_t transportLayerAddress_ipv4;
static uint16_t BindingID_port;
static int num_items;
static int hsdsch_macdflow_id;
static nbap_hsdsch_channel_info_t *nbap_hsdsch_channel_info;

#define AT_IPv4 0
#define ett_nbap_HSDSCH_MACdFlow_Specific_InfoItem_to_Modify 0
#define HSDSCH_MACdFlow_Specific_InfoItem_to_Modify_sequence NULL

void set_address(address *addr, uint8_t type, uint8_t len, void *data);
void copy_address(address *dst, address *src);
int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *sequence);

#define _U_ __attribute__((unused))