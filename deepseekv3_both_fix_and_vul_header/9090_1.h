#include <stdint.h>
#include <stddef.h>

typedef struct {
    int rlc_mode;
} hsdsch_channel_info_t;

typedef struct {
    unsigned char *buffer;
    int offset;
} asn1_ctx_t;

typedef struct {
    int dummy;
} proto_tree;

typedef struct {
    int dummy;
} tvbuff_t;

#define FP_RLC_AM 0
#define FP_RLC_UM 1
#define TRUE 1
#define _U_

typedef uint32_t guint32;

extern hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int hsdsch_macdflow_id;

int dissect_per_enumerated(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int count, guint32 *value, int bool, int min, const void *ptr);