#include <stdint.h>
#include <stdbool.h>

static uint32_t dch_id;
static uint32_t prev_dch_id;
static uint32_t g_num_dch_in_flow;
static uint32_t g_dchs_in_flow_list[256];

typedef struct {
    uint32_t next_dch;
} nbap_dch_chnl_info_t;

static nbap_dch_chnl_info_t nbap_dch_chnl_info[256];

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))
#define FALSE false

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, 
                                          unsigned int min, unsigned int max, uint32_t *val, bool is_unsigned);