#include <stdint.h>
#include <stdbool.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

static uint32_t MACdPDU_Size;
static int num_items;
static int e_dch_macdflow_id;

typedef struct {
    unsigned int visited;
} fd_flags_t;

typedef struct {
    fd_flags_t flags;
} fd_t;

typedef struct {
    fd_t *fd;
} pinfo_t;

typedef struct {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct {
    uint32_t *edch_macd_pdu_size;
} nbap_edch_channel_info_t;

static nbap_edch_channel_info_t *nbap_edch_channel_info;

#define TRUE true
#define _U_ __attribute__((unused))

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, 
                                         proto_tree *tree, int hf_index,
                                         uint32_t min_val, uint32_t max_val,
                                         uint32_t *retval, bool is_unsigned);