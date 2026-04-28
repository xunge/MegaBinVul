#include <stdbool.h>
#include <stddef.h>

typedef int gboolean;
#define _U_ __attribute__((unused))

typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;

typedef struct asn1_ctx_t {
    proto_item *created_item;
} asn1_ctx_t;

extern tvbuff_t* content_tvb;
extern void cms_verify_msg_digest(proto_item *pi, tvbuff_t *content_tvb, int algorithm_id, tvbuff_t *tvb, int offset);
extern int x509af_get_last_algorithm_id(void);
extern int dissect_ber_octet_string(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, void* data);
extern int get_ber_identifier(tvbuff_t *tvb, int offset, int *identifier, int *cls, int *pc);
extern int get_ber_length(tvbuff_t *tvb, int offset, int *indefinite, int *len);