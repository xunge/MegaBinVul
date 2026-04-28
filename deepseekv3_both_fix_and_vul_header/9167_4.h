#include <stdint.h>
#include <stdbool.h>

#define _U_ __attribute__((unused))
#define FALSE 0
#define TRUE 1

static uint32_t e_dch_ddi_value;
static uint32_t e_dch_macdflow_id;
static uint32_t num_items;

typedef struct {
    uint32_t edch_ddi[64];
} nbap_edch_channel_info_t;

static nbap_edch_channel_info_t nbap_edch_channel_info[64];

typedef struct {
    bool visited;
} flags_t;

typedef struct {
    flags_t flags;
} fd_t;

typedef struct {
    fd_t* fd;
} pinfo_t;

typedef struct {
    pinfo_t* pinfo;
} asn1_ctx_t;

typedef struct {
    int length;
    uint8_t* data;
} tvbuff_t;

typedef struct {
    int dummy;
} proto_tree;

static int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index,
                                          unsigned min, unsigned max, uint32_t *value, bool flag);