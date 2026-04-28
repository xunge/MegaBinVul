#include <stdint.h>
#include <stdbool.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))
#define FALSE false

static uint32_t cfn;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, 
                                  proto_tree *tree, int hf_index, 
                                  unsigned min, unsigned max, 
                                  uint32_t *value, bool flag);