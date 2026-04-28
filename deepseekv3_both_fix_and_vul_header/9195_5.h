#include <stdint.h>
#include <stdbool.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

static uint32_t com_context_id;
static bool crcn_context_present;

#define _U_ __attribute__((unused))
#define FALSE false
#define TRUE true

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, uint32_t min_val, uint32_t max_val, uint32_t *retval, bool is_unsigned);