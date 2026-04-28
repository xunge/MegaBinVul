#include <stdint.h>
#include <stddef.h>

typedef struct {
    struct {
        uint32_t num;
        struct {
            unsigned visited : 1;
        } flags;
    } *fd;
} pinfo_t;

typedef struct {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct {
    int dummy;
} tvbuff_t;

typedef struct {
    int dummy;
} proto_tree;

typedef struct {
    int type;
    int len;
    void *data;
} address;

typedef struct {
    int dummy;
} conversation_t;

static int hrnti;
static int maxNrOfMACdFlows;
static struct {
    address crnc_address;
    uint32_t crnc_port;
} nbap_hsdsch_channel_info[1];

typedef struct {
    int hrnti;
} umts_fp_conversation_info_t;

extern int proto_fp;

#define AT_NONE 0
#define PT_UDP 0
#define NO_ADDR_B 0
#define FALSE 0
#define _U_
#define DISSECTOR_ASSERT(x) (void)(x)

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
                                  proto_tree *tree, int hf_index, unsigned min,
                                  unsigned max, int *value, int flag);
void set_address(address *addr, int type, int len, void *data);
conversation_t *find_conversation(uint32_t num, address *addr1, address *addr2,
                                int ptype, uint32_t port1, uint32_t port2, int flags);
void *conversation_get_proto_data(conversation_t *conv, int proto);