#include <stdbool.h>

typedef bool gboolean;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

struct asn1_ctx_t {
    void *value_ptr;
};

#define _U_ __attribute__((unused))
#define TRUE true

struct tcap_private_t {
    const void *oid;
    gboolean acv;
};

extern const void *cur_oid;
extern int dissect_ber_object_identifier_str(gboolean implicit_tag, struct asn1_ctx_t *actx, 
                                           proto_tree *tree, tvbuff_t *tvb, int offset, 
                                           int hf_index, const void **cur_oid);

typedef struct asn1_ctx_t asn1_ctx_t;