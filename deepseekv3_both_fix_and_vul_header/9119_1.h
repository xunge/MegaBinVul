#include <stdint.h>

static int num_items;

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const void *sequence);

#define ett_nbap_E_DCH_LogicalChannelInformationItem 0
extern const void *E_DCH_LogicalChannelInformationItem_sequence;