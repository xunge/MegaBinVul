#include <stdbool.h>

#define maxNoOfLogicalChannels 1
#define e_dch_macdflow_id 0
#define _U_
#define FALSE false

static int num_items = 0;

typedef struct {
    int no_ddi_entries;
} nbap_edch_channel_info_t;

nbap_edch_channel_info_t nbap_edch_channel_info[1];

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define ett_nbap_E_DCH_LogicalChannelInformation 0
#define E_DCH_LogicalChannelInformation_sequence_of 0

int dissect_per_constrained_sequence_of(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence_of, int min, int max, bool is_unsigned);