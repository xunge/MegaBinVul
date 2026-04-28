#include <stdlib.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

int num_items;
int ett_nbap_HSDSCH_MACdFlow_Specific_InformationResp_Item;
const void *HSDSCH_MACdFlow_Specific_InformationResp_Item_sequence;

int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const void *ptr);

#define _U_