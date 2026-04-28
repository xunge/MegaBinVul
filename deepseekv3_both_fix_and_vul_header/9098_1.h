#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))

extern int num_items;
extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const void *sequence);
extern const void *HSDSCH_MACdFlow_Specific_InformationResp_Item_sequence;
extern int ett_nbap_HSDSCH_MACdFlow_Specific_InformationResp_Item;