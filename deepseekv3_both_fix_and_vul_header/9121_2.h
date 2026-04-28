#include <stdbool.h>

static int num_items;
static const int maxNrOfMACdFlows;
static const int ett_nbap_HSDSCH_MACdFlows_to_Delete;
static const int HSDSCH_MACdFlows_to_Delete_sequence_of;

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))
#define FALSE false

extern int dissect_per_constrained_sequence_of(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence_of, int min_len, int max_len, bool has_extension);