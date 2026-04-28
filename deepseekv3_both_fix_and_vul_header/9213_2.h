#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct {
    unsigned int flags;
    int visited;
} fd_flags_t;

typedef struct {
    fd_flags_t flags;
} frame_data;

typedef struct {
    frame_data *fd;
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
static nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[1];

#define AT_IPv4 0
#define ett_nbap_HSDSCH_MACdFlow_Specific_InfoItem 0
#define HSDSCH_MACdFlow_Specific_InfoItem_sequence NULL
#define _U_

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *sequence);
static void set_address(address *addr, int type, int length, void *data);
static void copy_address(void *dst, address *src);