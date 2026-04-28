#include <stdint.h>

typedef struct {
    uint32_t ipv4;
} address;

typedef struct {
    struct {
        struct {
            unsigned visited : 1;
        } flags;
    } *fd;
    int hf_index;
} pinfo;

typedef struct {
    pinfo *pinfo;
} asn1_ctx_t;

typedef struct {
    address crnc_address;
    uint16_t crnc_port;
} nbap_common_channel_info_t;

typedef struct {
    unsigned char *data;
    int length;
} tvbuff_t;

typedef struct {
    int hf_index;
} proto_tree;

extern uint32_t transportLayerAddress_ipv4;
extern uint16_t BindingID_port;
extern unsigned int num_items;
extern unsigned int common_macdflow_id;
extern nbap_common_channel_info_t nbap_common_channel_info[];
extern int ett_nbap_CommonMACFlow_Specific_InfoItem;
extern int CommonMACFlow_Specific_InfoItem_sequence[];

int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int *sequence);

#define AT_IPv4 1
#define SET_ADDRESS(addr, type, len, value) ((addr)->ipv4 = *(value))
#define COPY_ADDRESS(dst, src) ((dst)->ipv4 = (src)->ipv4)
#define _U_ __attribute__((unused))