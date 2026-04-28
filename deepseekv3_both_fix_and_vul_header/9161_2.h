#include <stdint.h>
#include <stdbool.h>

#define maxNoOfLogicalChannels 32
#define e_dch_macdflow_id 0
#define _U_ __attribute__((unused))
#define FALSE false

typedef struct {
    int no_ddi_entries;
} nbap_edch_channel_info_t;

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

extern int num_items;
extern nbap_edch_channel_info_t nbap_edch_channel_info[];
extern const int E_DCH_LogicalChannelInformation_sequence_of[];
extern const int ett_nbap_E_DCH_LogicalChannelInformation;

int dissect_per_constrained_sequence_of(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const int *seq, int min_len, int max_len, bool has_extension);