#include <stdint.h>

#define _U_ __attribute__((unused))

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree_t;
typedef struct proto_tree proto_tree;

typedef uint32_t guint32;

typedef struct {
    struct {
        struct {
            unsigned visited;
        } flags;
    } *fd;
} pinfo_t;

struct asn1_ctx {
    pinfo_t *pinfo;
};

enum {
    id_HSDSCH_MACdFlows_to_Add,
    FP_RLC_MODE_UNKNOWN
};

enum {
    entity_not_specified
};

typedef struct {
    int crnc_port;
    int rlc_mode;
    int entity;
} nbap_hsdsch_channel_info_t;

extern int num_items;
extern int ProtocolIE_ID;
extern guint32 maxNrOfMACdFlows;
extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int ett_nbap_HSDSCH_MACdFlows_Information;
extern int HSDSCH_MACdFlows_Information_sequence[];

static int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int *sequence);
static void add_hsdsch_bind(pinfo_t *pinfo);