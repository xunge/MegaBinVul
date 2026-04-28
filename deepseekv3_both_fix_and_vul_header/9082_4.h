#include <stdint.h>
#include <stdbool.h>

extern uint32_t maxNrOfCommonMACFlows_1;
extern int common_macdflow_id;

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree_t;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree_t *tree, int hf_index, uint32_t lower, uint32_t upper, int *value, bool enforce_bounds);

#define _U_ __attribute__((unused))
#define FALSE 0

typedef proto_tree_t proto_tree;