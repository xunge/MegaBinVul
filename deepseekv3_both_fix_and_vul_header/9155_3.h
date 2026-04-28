#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))

typedef struct {
    int visited;
} fd_flags_t;

typedef struct {
    fd_flags_t flags;
} fd_t;

typedef struct {
    fd_t *fd;
} pinfo_t;

typedef struct {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct {
    int hf_index;
} proto_tree;

typedef struct {
    unsigned char *data;
    int length;
} tvbuff_t;

typedef struct {
    int type;
    int length;
    void *data;
} address;

typedef struct {
    address crnc_address;
    uint16_t crnc_port;
} nbap_common_channel_info_t;

static uint32_t transportLayerAddress_ipv4;
static uint16_t BindingID_port;
static int num_items;
static int common_macdflow_id;
static nbap_common_channel_info_t *nbap_common_channel_info;

#define AT_IPv4 1
#define ett_nbap_CommonMACFlow_Specific_InfoItem 0
#define CommonMACFlow_Specific_InfoItem_sequence NULL