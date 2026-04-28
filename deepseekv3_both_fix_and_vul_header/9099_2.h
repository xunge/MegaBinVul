#include <stdint.h>

#define maxNoOfLogicalChannels 32
#define e_dch_macdflow_id 0
#define FALSE 0
#define _U_ 

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

typedef struct {
    int no_ddi_entries;
} nbap_edch_channel_info_t;

static int num_items;
static nbap_edch_channel_info_t nbap_edch_channel_info[1];

extern int dissect_per_constrained_sequence_of(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence_of, int min_len, int max_len, int has_extension);

#define ett_nbap_E_DCH_LogicalChannelInformation 0
#define E_DCH_LogicalChannelInformation_sequence_of 0