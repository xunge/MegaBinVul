#include <stdint.h>
#include <stdbool.h>

#define _U_ __attribute__((unused))
#define TRUE true

typedef bool gboolean;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct asn1_ctx_t asn1_ctx_t;

struct asn1_ctx_t {
    void *value_ptr;
};

struct tcap_private_t {
    const void *oid;
    gboolean acv;
};

extern const void *cur_oid;
extern int dissect_ber_object_identifier_str(gboolean implicit_tag, asn1_ctx_t *actx, 
                                           proto_tree *tree, tvbuff_t *tvb,
                                           int offset, int hf_index, const void **oid_ptr);