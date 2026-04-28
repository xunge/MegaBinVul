#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct _address {
    int type;
    int len;
    void *data;
} address;

typedef struct _frame_data {
    struct _flags {
        unsigned visited:1;
    } flags;
} frame_data_t;

typedef struct _pinfo {
    frame_data_t *fd;
} pinfo_t;

typedef struct asn1_ctx {
    pinfo_t *pinfo;
} asn1_ctx_t;

extern int transportLayerAddress_ipv4;
extern int BindingID_port;
extern int num_items;
extern int hsdsch_macdflow_id;
extern int ett_nbap_HSDSCH_MACdFlow_Specific_InfoItem_to_Modify;
extern int HSDSCH_MACdFlow_Specific_InfoItem_to_Modify_sequence;

extern struct {
    address crnc_address;
    int crnc_port;
} *nbap_hsdsch_channel_info;

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence);
extern void set_address(address *addr, int type, int len, void *data);
extern void copy_address(address *dst, address *src);

#define AT_IPv4 1
#define _U_ __attribute__((unused))