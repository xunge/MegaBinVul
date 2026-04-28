#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))

typedef struct {
    uint32_t crnc_port;
    int entity;
} nbap_hsdsch_channel_info_t;

typedef struct {
    int dummy;
} tvbuff_t;

typedef struct {
    int dummy;
} asn1_ctx_t;

typedef struct {
    int dummy;
} proto_tree;

#define ehs 0
#define TRUE 1
#define UINT32_C(c) c ## U

static nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[1];
static int hsdsch_macdflow_id;

static int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, uint32_t min, uint32_t max, void *ptr, int flag);