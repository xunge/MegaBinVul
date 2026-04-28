#include <stdint.h>
#include <stdbool.h>

#define FALSE false
#define TRUE true

extern uint32_t maxNrOfCommonMACFlows_1;
extern int common_macdflow_id;

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index,
                                  uint32_t min_val, uint32_t max_val, int *val, bool is_unsigned);

#define _U_ __attribute__((unused))