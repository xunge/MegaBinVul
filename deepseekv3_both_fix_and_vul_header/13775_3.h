#include <stdbool.h>
#include <string.h>

typedef bool gboolean;
typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct wmem_allocator_t wmem_allocator_t;

#define _U_ __attribute__((unused))

const char *object_identifier_id = NULL;

extern int dissect_ber_object_identifier_str(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, const char **object_identifier_id);
extern const char *oid_resolved_from_string(wmem_allocator_t *allocator, const char *oid);
extern wmem_allocator_t *wmem_packet_scope(void);
extern void proto_item_append_text(proto_tree *tree, const char *format, ...);