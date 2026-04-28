#include <stdint.h>

#define id_HSDSCH_MACdFlows_to_Add 0
#define maxNrOfMACdFlows 0
#define FP_RLC_MODE_UNKNOWN 0
#define ett_nbap_HSDSCH_MACdFlows_Information 0
#define entity_not_specified 0
#define HSDSCH_MACdFlows_Information_sequence 0
#define _U_ __attribute__((unused))

typedef uint32_t guint32;

typedef struct {
    int crnc_port;
    int rlc_mode;
    int entity;
} nbap_hsdsch_channel_info_t;

typedef struct {
    struct {
        struct {
            struct {
                int visited;
            } flags;
        } *fd;
    } *pinfo;
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
extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence);
extern void add_hsdsch_bind(void *pinfo);