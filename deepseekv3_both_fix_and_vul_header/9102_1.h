#include <stdint.h>

#define _U_ __attribute__((unused))

static int num_items;

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett_nbap_PriorityQueue_InfoItem, int PriorityQueue_InfoItem_sequence);

#define ett_nbap_PriorityQueue_InfoItem 0
#define PriorityQueue_InfoItem_sequence 0