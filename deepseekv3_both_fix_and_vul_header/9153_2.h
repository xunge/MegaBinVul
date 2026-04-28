#include <stdint.h>
#include <stddef.h>

typedef struct {
    int rlc_mode;
} nbap_hsdsch_channel_info_t;

typedef struct {
    unsigned char *tvb_data;
} tvbuff_t;

typedef struct {
    int dummy;
} asn1_ctx_t;

typedef struct {
    int dummy;
} proto_tree;

enum {
    FP_RLC_AM,
    FP_RLC_UM
};

#define _U_ __attribute__((unused))
#define TRUE 1

extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int hsdsch_macdflow_id;

int dissect_per_enumerated(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int count, uint32_t *value, int bool, int min, const void *ptr);

typedef uint32_t guint32;