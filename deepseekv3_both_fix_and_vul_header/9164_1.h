#include <stdint.h>

static int num_items;

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

typedef struct {
    // Add necessary fields for PriorityQueue_InfoItem sequence
} PriorityQueue_InfoItem_t;

#define ett_nbap_PriorityQueue_InfoItem 0
#define _U_ __attribute__((unused))

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const void *sequence);

extern const PriorityQueue_InfoItem_t PriorityQueue_InfoItem_sequence[];