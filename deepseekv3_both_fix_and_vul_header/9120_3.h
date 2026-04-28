#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))
#define DISSECTOR_ASSERT(expr) ((void)0)

typedef struct address {
    int type;
    void *data;
} address;

typedef struct {
    uint16_t crnc_port;
    address crnc_address;
} nbap_hsdsch_channel_info_t;

typedef struct {
    int hrnti;
} umts_fp_conversation_info_t;

typedef struct {
    int num;
    struct {
        unsigned visited : 1;
    } flags;
} frame_data;

typedef struct {
    frame_data *fd;
} pinfo_t;

typedef struct {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct {
    int dummy;
} conversation_t;

typedef struct {
    int dummy;
} proto_tree;

typedef struct {
    int dummy;
} tvbuff_t;

#define AT_NONE 0
#define PT_UDP 0
#define NO_ADDR_B 0
#define FALSE 0

extern int hrnti;
extern int maxNrOfMACdFlows;
extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int proto_fp;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index,
                                  unsigned min, unsigned max, int *val, int flag);
void set_address(address *addr, int type, int len, void *data);
conversation_t *find_conversation(int num, address *addr1, address *addr2, int type, uint16_t port1, uint16_t port2, int flags);
void *conversation_get_proto_data(conversation_t *conv, int proto);