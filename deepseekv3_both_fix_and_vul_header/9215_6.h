#include <stdint.h>
#include <stdbool.h>

#define FALSE false
#define TRUE true

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct {
    unsigned int visited;
} fd_flags_t;

typedef struct {
    fd_flags_t flags;
} fd_t;

typedef struct {
    fd_t* fd;
} packet_info_t;

typedef struct asn1_ctx {
    packet_info_t* pinfo;
} asn1_ctx_t;

static uint32_t e_dch_ddi_value;
static uint32_t e_dch_macdflow_id;
static uint32_t num_items;

typedef struct {
    uint32_t* edch_ddi;
} NBAP_EDCH_Channel_Info;

static NBAP_EDCH_Channel_Info* nbap_edch_channel_info;

#define _U_ __attribute__((unused))

extern int dissect_per_constrained_integer(tvbuff_t* tvb, int offset, asn1_ctx_t* actx, proto_tree* tree, int hf_index,
                                         uint32_t min, uint32_t max, uint32_t* val, bool enforce_bounds);