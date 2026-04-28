#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;

typedef struct {
    int rlc_mode;
} hsdsch_channel_info_t;

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))
#define TRUE 1
#define FP_RLC_AM 0
#define FP_RLC_UM 1

extern hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int hsdsch_macdflow_id;

int dissect_per_enumerated(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, 
                          int count, guint32 *value, int unknown, int min, const void *labels);