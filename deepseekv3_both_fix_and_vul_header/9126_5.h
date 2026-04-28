#include <stdint.h>
#include <stdbool.h>

typedef uint32_t guint32;
typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))
#define TRUE true

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
                                         proto_tree *tree, int hf_index,
                                         guint32 min, guint32 max,
                                         guint32 *retval, bool sign);

extern guint32 hsdsch_macdflow_id;
extern struct {
    guint32 hsdsch_physical_layer_category;
} nbap_hsdsch_channel_info[];