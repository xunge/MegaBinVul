#include <stdbool.h>
#include <string.h>

typedef bool gboolean;
#define _U_ 

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct asn1_ctx_t {
    struct {
        char *direct_reference;
    } external;
} asn1_ctx_t;

extern int hf_x509af_extension_id;
extern void *wmem_packet_scope(void);
extern char *oid_resolved_from_string(void *scope, const char *oid_str);
extern void proto_item_append_text(proto_tree *tree, const char *format, ...);
extern int dissect_ber_object_identifier_str(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, char **direct_reference);