#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

typedef struct {
    unsigned int crnc_port;
    int entity;
} nbap_hsdsch_channel_info_t;

static nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[256];
static int hsdsch_macdflow_id;
static const int ehs = 0;

#define _U_ __attribute__((unused))
#define TRUE 1

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, uint32_t min_len, uint32_t max_len, void *data, bool is_signed);