#include <stdint.h>
#include <stdbool.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))
#define FALSE false
#define TRUE true

static uint32_t com_context_id;
static bool crcn_context_present;

/* 注意：dissect_per_constrained_integer 需要额外定义 */
int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
                                  proto_tree *tree, int hf_index, 
                                  uint32_t min_val, uint32_t max_val,
                                  uint32_t *ret_val, bool flag);