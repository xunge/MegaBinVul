#include <stdint.h>

typedef uint32_t guint32;
typedef int gboolean;
#define TRUE 1
#define _U_ __attribute__((unused))

typedef struct {
    guint32 hsdsch_physical_layer_category;
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

extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern guint32 hsdsch_macdflow_id;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, guint32 lower, guint32 upper, guint32 *value, gboolean enforce_bounds);