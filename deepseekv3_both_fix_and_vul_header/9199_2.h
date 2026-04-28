#include <stdint.h>
#include <stdbool.h>

#define _U_ __attribute__((unused))
#define FALSE false

static uint32_t logical_channel_id;
static int num_items;

typedef struct {
    uint32_t lchId[1];
} nbap_edch_channel_info_t;
static nbap_edch_channel_info_t nbap_edch_channel_info[1];
#define e_dch_macdflow_id 0

typedef struct {
    int dummy;
} tvbuff_t;
typedef struct {
    int dummy;
} asn1_ctx_t;
typedef struct {
    int dummy;
} proto_tree;

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, unsigned int min, unsigned int max, uint32_t *val, int flag);