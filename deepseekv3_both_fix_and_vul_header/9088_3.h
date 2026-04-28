#include <stddef.h>
#include <stdint.h>

#define _U_ __attribute__((unused))

typedef struct {
    void *crnc_address;
    uint32_t crnc_port;
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
    int type;
    int len;
    void *data;
} address;

typedef void tvbuff_t;
typedef void proto_tree;
typedef void conversation_t;

#define PT_UDP 0
#define NO_ADDR_B 0
#define AT_NONE 0
#define FALSE 0

extern int maxNrOfMACdFlows;
extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int proto_fp;
extern int hrnti;

void SET_ADDRESS(address *addr, int type, int len, void *data);
conversation_t *find_conversation(int num, address *addr1, address *addr2, int type, uint32_t port1, uint32_t port2, int flags);
void *conversation_get_proto_data(conversation_t *conv, int proto);
void DISSECTOR_ASSERT(int condition);
int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, unsigned min, unsigned max, int *value, int flag);