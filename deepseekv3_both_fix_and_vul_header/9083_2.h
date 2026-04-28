#include <stdint.h>
#include <stdbool.h>

static uint32_t logical_channel_id;
static int num_items;
static struct {
    uint32_t lchId[1];
} nbap_edch_channel_info[1];
#define e_dch_macdflow_id 0
#define _U_
#define FALSE false

typedef struct {
    int dummy; 
} tvbuff_t;
typedef struct {
    int dummy;
} asn1_ctx_t;
typedef struct {
    int dummy;
} proto_tree;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, unsigned int min, unsigned int max, uint32_t *value, int flag);