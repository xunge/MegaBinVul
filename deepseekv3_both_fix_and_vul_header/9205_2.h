#include <stdint.h>

typedef struct {
    unsigned int visited;
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
    void *crnc_address;
    uint32_t crnc_port;
} nbap_common_channel_info_t;

typedef struct {
    int type;
    int len;
    void *data;
} address;

typedef struct {
    void *buffer;
} tvbuff_t;

typedef struct {
    void *tree;
} proto_tree;

static int num_items;
static uint32_t transportLayerAddress_ipv4;
static uint32_t BindingID_port;
static int common_macdflow_id;
static nbap_common_channel_info_t *nbap_common_channel_info;
static int ett_nbap_CommonMACFlow_Specific_InfoItem;
static const char *CommonMACFlow_Specific_InfoItem_sequence[1];

#define _U_ __attribute__((unused))
#define AT_IPv4 1

void set_address(address *addr, int type, int len, void *data);
void copy_address(void *dst, address *src);
int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const char **seq);