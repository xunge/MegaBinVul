#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

extern int num_items;
extern int ett_nbap_PriorityQueue_InfoItem_to_Add;
extern const char PriorityQueue_InfoItem_to_Add_sequence[];

int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const char *seq);

#define _U_ __attribute__((unused))