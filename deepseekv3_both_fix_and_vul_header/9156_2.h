#include <stdbool.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define _U_ __attribute__((unused))
#define FALSE false

static int dissect_per_enumerated(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int count, const void *data, bool unknown, int value, const void *ptr);