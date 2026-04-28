#include <stdint.h>

#define id_HSDSCH_MACdFlows_to_Add 0
#define maxNrOfMACdFlows 0
#define FP_RLC_MODE_UNKNOWN 0
#define ett_nbap_HSDSCH_MACdFlows_Information 0
#define entity_not_specified 0
#define _U_

typedef uint32_t guint32;

typedef struct {
    int crnc_port;
    int rlc_mode;
    int entity;
} nbap_hsdsch_channel_info_t;

typedef struct {
    unsigned int visited;
} fd_flags_t;

typedef struct {
    fd_flags_t flags;
} fd_t;

typedef struct {
    fd_t* fd;
} pinfo_t;

typedef struct {
    pinfo_t* pinfo;
} asn1_ctx_t;

typedef struct {
    int dummy;
} tvbuff_t;

typedef struct {
    int dummy;
} proto_tree;

extern int ProtocolIE_ID;
extern int num_items;
extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int HSDSCH_MACdFlows_Information_sequence;

int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence);
void add_hsdsch_bind(pinfo_t *pinfo);