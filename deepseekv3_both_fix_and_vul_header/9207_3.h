#include <stdint.h>
#include <stdbool.h>

typedef uint32_t guint32;
#define TRUE true

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

typedef struct {
    guint32 hsdsch_physical_layer_category;
} HSDSCH_Channel_Info;

extern HSDSCH_Channel_Info nbap_hsdsch_channel_info[];
extern guint32 hsdsch_macdflow_id;

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index,
                                         guint32 lower, guint32 upper, guint32 *value, bool has_extension);

#define _U_ __attribute__((unused))