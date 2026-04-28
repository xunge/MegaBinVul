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

#define _U_ 
#define guint32 uint32_t
#define TRUE 1
#define FP_RLC_AM 0
#define FP_RLC_UM 1

extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int hsdsch_macdflow_id;

int dissect_per_enumerated(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int count, guint32 *value, int unknown, int min, const void *labels);