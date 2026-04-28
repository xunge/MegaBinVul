#include <stdint.h>
#include <stdbool.h>

#define _U_
#define FALSE false

static uint32_t logical_channel_id;
static int num_items;
static struct {
    uint32_t lchId[1];
} nbap_edch_channel_info[1];
#define e_dch_macdflow_id 0

typedef struct {
} asn1_ctx_t;

typedef struct {
} tvbuff_t;

typedef struct {
} proto_tree;

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, uint32_t min, uint32_t max, uint32_t *val, int strict);