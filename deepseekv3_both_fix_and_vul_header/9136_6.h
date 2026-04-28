#include <stdint.h>
#include <stdbool.h>

#define _U_ __attribute__((unused))
#define FALSE false

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

struct asn1_ctx {
    struct _packet_info *pinfo;
};

struct _packet_info {
    struct {
        struct {
            unsigned int visited;
        } flags;
    } *fd;
};

static uint32_t e_dch_ddi_value;
static uint32_t e_dch_macdflow_id;
static uint32_t num_items;

typedef struct {
    uint32_t edch_ddi[1];
} nbap_edch_channel_info_t;

static nbap_edch_channel_info_t nbap_edch_channel_info[1];

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, 
                                  proto_tree *tree, int hf_index, 
                                  uint32_t min_val, uint32_t max_val, 
                                  uint32_t *value, bool flag);