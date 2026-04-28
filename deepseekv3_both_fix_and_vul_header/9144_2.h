#include <stdlib.h>
#include <string.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

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
    unsigned char crnc_address[4];
    unsigned short crnc_port;
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

#define AT_IPv4 0
#define _U_ 
#define ett_nbap_HSDSCH_MACdFlow_Specific_InfoItem_to_Modify 0
#define HSDSCH_MACdFlow_Specific_InfoItem_to_Modify_sequence NULL

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *sequence);
extern void set_address(address *addr, int type, int length, void *data);
extern void copy_address(void *dst, void *src);