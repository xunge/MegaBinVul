#include <stdlib.h>
#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree_t;
typedef struct proto_tree proto_tree;

static int num_items;
static int ett_nbap_HSDSCH_MACdFlows_to_Delete_Item;

#define _U_ __attribute__((unused))

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *sequence);

static const void *HSDSCH_MACdFlows_to_Delete_Item_sequence;