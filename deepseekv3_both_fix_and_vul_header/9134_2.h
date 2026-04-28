#include <stdlib.h>
#include <string.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

#define AT_IPv4 1

typedef struct {
    int visited;
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
    int crnc_port;
    void *crnc_address;
} nbap_hsdsch_channel_info_t;

typedef struct {
    int type;
    int length;
    void *data;
} address;

static int transportLayerAddress_ipv4;
static int BindingID_port;
static int num_items;
static int hsdsch_macdflow_id;
static nbap_hsdsch_channel_info_t *nbap_hsdsch_channel_info;

static int ett_nbap_HSDSCH_MACdFlow_Specific_InfoItem;
static int HSDSCH_MACdFlow_Specific_InfoItem_sequence;

static int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence);

static void set_address(address *addr, int type, int length, void *data);
static void copy_address(void *dst, address *src);

#define _U_ __attribute__((unused))