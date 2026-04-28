#include <stdlib.h>

static int num_items;

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *sequence);

#define ett_nbap_HSDSCH_MACdFlow_Specific_InformationResp_Item 0
#define HSDSCH_MACdFlow_Specific_InformationResp_Item_sequence NULL

#define _U_