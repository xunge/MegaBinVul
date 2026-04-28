#include <stdbool.h>

typedef bool gboolean;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct {
    void *value_ptr;
} asn1_ctx_t;

struct tcap_private_t {
    const void *oid;
    bool acv;
};

#define TRUE true
#define _U_ __attribute__((unused))

extern const void *cur_oid;
extern int dissect_ber_object_identifier_str(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, const void **cur_oid);