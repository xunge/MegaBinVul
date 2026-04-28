#include <stddef.h>

#define _U_ __attribute__((unused))

typedef int gboolean;
typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;

extern int hf_cms_attrType;
extern const char *object_identifier_id;
extern proto_tree *cap_tree;

const char *oid_resolved_from_string(void *scope, const char *oid);
void *wmem_packet_scope(void);
void proto_item_append_text(proto_tree *tree, const char *format, ...);
int dissect_ber_object_identifier_str(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, const char **object_identifier_id);